#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <utility>

std::vector<int> getSelfZ(const std::string& view) {
    size_t n = view.length();
    std::vector<int> selfZ(n);
    selfZ[0] = n;
    size_t right_bound = 1;
    size_t offset = 0;
    for (size_t i = 1; i < n; i++) {
        if (i >= right_bound || selfZ[i - offset] + i >= right_bound) {
            size_t start = std::max(i, right_bound);
            for (; start < n && view[start] == view[start - i]; start++) {
            }
            selfZ[i] = start - i;
            right_bound = start;
            offset = i;
        } else {
            selfZ[i] = selfZ[i - offset];
        }
    }
    return selfZ;
}

std::vector<int> getCommonZ(const std::string& view,
                            const std::string& pattern,
                            const std::vector<int>& patternZ,
                            size_t maxn) {
    size_t n = view.size();
    size_t m = pattern.size();
    size_t right_bound = 0;
    size_t offset = 0;
    std::vector<int> commonZ(maxn);
    for (size_t i = 0; i < maxn; i++) {
        if (i >= right_bound || patternZ[i - offset] + i >= right_bound) {
            size_t start = std::max(i, right_bound);
            for (; start < std::min(n, m + i) && view[start] == pattern[start - i]; start++) {
            }
            commonZ[i] = start - i;
            right_bound = start;
            offset = i;
        } else {
            commonZ[i] = patternZ[i - offset];
        }
    }
    return commonZ;
}

std::vector<int> getCommonZ(const std::string& view,
                            const std::string& pattern,
                            const std::vector<int>& patternZ) {
    return getCommonZ(view, pattern, patternZ, view.length());
}

const int NPrimes = 5;

uint32_t rd() {
    uint32_t res;
#ifdef __MINGW32__
    asm volatile("rdrand %0" :"=a"(res)::"cc");
#else
    res = std::random_device()();
#endif
    return res;
}

struct Solution {
    std::string x;
    std::string s;
    std::vector<int> selfZ;
    std::vector<int> commonZ;
    std::array<uint32_t, NPrimes> primes;
    std::array<std::vector<uint32_t>, NPrimes> hashes;
    std::array<std::vector<uint32_t>, NPrimes> mults;
    std::array<int, NPrimes> xHashes;

    void genPrimes() {
        for (int i = 0; i < NPrimes; i++) {
            int init = (rd() >> 4) + 100000000;
            int cur = init | 1;
            bool good;
            do {
                good = true;
                for (int j = 3; j * j <= cur; j++) {
                    if (cur % j == 0) {
                        cur += 2;
                        good = false;
                        break;
                    }
                }
            } while (!good);
            primes[i] = cur;
        }
    }

    void genHashes() {
        for (int i = 0; i < NPrimes; i++) {
            std::vector<uint32_t>& hash = hashes[i];
            std::vector<uint32_t>& mult = mults[i];
            hash.resize(s.length() + 1);
            mult.resize(s.length() + 1);
            mult[0] = 1;
            hash[0] = 0;
            int p = primes[i];
            for (int j = 0; j < s.length(); j++) {
                hash[j + 1] = ((hash[j] * 10) + (s[j] - '0')) % p;
                mult[j + 1] = (mult[j] * 10) % p;
            }
        }
        for (int i = 0; i < NPrimes; i++) {
            uint32_t cur = 0;
            int p = primes[i];
            for (int j = 0; j < x.length(); j++) {
                cur = ((cur * 10) + (x[j] - '0')) % p;
            }
            xHashes[i] = cur;
        }
    }

    int getHash(int idx, int from, int to) {
        int res = (int) hashes[idx][to] - (int) (hashes[idx][from] * int64_t(mults[idx][to - from]) % primes[idx]);
        if (res < 0) {
            res += primes[idx];
        }
        return res;
    }

    std::vector<int> getNines(const std::string& s) {
        std::vector<int> res(s.length());
        int cur = 0;
        for (int i = (int) s.length() - 1; i >= 0; i--) {
            if (s[i] == '9') {
                cur++;
            } else {
                cur = 0;
            }
            res[i] = cur;
        }
        return res;
    }

    void run(std::istream& in, std::ostream& out) {
        in >> s >> x;
        selfZ = getSelfZ(x);
        commonZ = getCommonZ(s, x, selfZ);
        genPrimes();
        genHashes();
        for (int i = 0; i + x.length() <= s.length(); i++) {
            int z = commonZ[i];
            if (z == x.length()) {
                continue;
            }
            if (s[i + z] > x[z]) {
                continue;
            }
            for (int blen = x.length() - z - 1; blen <= x.length() - z; blen++) {
                if (i + x.length() + blen <= s.length()) {
                    bool good = true;
                    for (int j = 0; j < NPrimes; j++) {
                        int aHash = getHash(j, i, i + x.length());
                        int bHash = getHash(j, i + x.length(), i + x.length() + blen);
                        int sumHash = aHash + bHash;
                        if (sumHash >= primes[j]) {
                            sumHash -= primes[j];
                        }
                        if (sumHash != xHashes[j]) {
                            good = false;
                            break;
                        }
                    }
                    if (good) {
                        out << i + 1 << " " << i + x.length() << "\n";
                        out << i + x.length() + 1 << " " << i + x.length() + blen << "\n";
                        return;
                    }
                }
                if (blen <= i) {
                    bool good = true;
                    for (int j = 0; j < NPrimes; j++) {
                        int aHash = getHash(j, i, i + x.length());
                        int bHash = getHash(j, i - blen, i);
                        int sumHash = aHash + bHash;
                        if (sumHash >= primes[j]) {
                            sumHash -= primes[j];
                        }
                        if (sumHash != xHashes[j]) {
                            good = false;
                            break;
                        }
                    }
                    if (good) {
                        out << i - blen + 1 << " " << i << "\n";
                        out << i + 1 << " " << i + x.length() << "\n";
                        return;
                    }
                }
            }
        }
        if (x[0] != '1') {
            out << "fail\n";
            return;
        }
        int xZeros = 0;
        std::vector<int> nines = getNines(s);
        for (int i = 0; i + x.length() - 1 <= s.length(); i++) {
            int blen = x.length() - 1;
            if (i + x.length() - 1 + blen <= s.length()) {
                bool good = true;
                for (int j = 0; j < NPrimes; j++) {
                    int aHash = getHash(j, i, i + x.length() - 1);
                    int bHash = getHash(j, i + x.length() - 1, i + x.length() - 1 + blen);
                    int sumHash = aHash + bHash;
                    if (sumHash >= primes[j]) {
                        sumHash -= primes[j];
                    }
                    if (sumHash != xHashes[j]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    out << i + 1 << " " << i + x.length() - 1 << "\n";
                    out << i + x.length() << " " << i + x.length() - 1 + blen << "\n";
                    return;
                }
            }
            if (blen <= i) {
                bool good = true;
                for (int j = 0; j < NPrimes; j++) {
                    int aHash = getHash(j, i, i + x.length() - 1);
                    int bHash = getHash(j, i - blen, i);
                    int sumHash = aHash + bHash;
                    if (sumHash >= primes[j]) {
                        sumHash -= primes[j];
                    }
                    if (sumHash != xHashes[j]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    out << i - blen + 1 << " " << i << "\n";
                    out << i + 1 << " " << i + x.length() - 1 << "\n";
                    return;
                }
            }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}