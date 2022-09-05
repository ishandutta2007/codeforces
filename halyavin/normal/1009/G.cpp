#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>
#include <numeric>

struct Solution {
    static constexpr int letters = 6;
    static constexpr int masks = 1 << letters;
    std::array<int, letters> stats;
    std::array<int, masks> maskStats;
    std::array<std::array<int, masks>, letters> flow;
    std::vector<int> allowed;
    std::array<int, masks> minLetter;

    std::array<bool, letters> flags;
    std::array<bool, masks> maskFlags;

    bool dfs2(int m, int mask) {
        if (maskFlags[m]) {
            return false;
        }
        maskFlags[m] = true;
        for (int letter = 0; letter < letters; letter++) {
            if (((m >> letter) & 1) == 0) continue;
            if (dfs1(letter, mask)) {
                flow[letter][m]++;
                return true;
            }
        }
        return false;
    }

    bool dfs1(int letter, int mask) {
        if (flags[letter]) {
            return false;
        }
        flags[letter] = true;
        if (flow[letter][mask] > 0) {
            flow[letter][mask]--;
            return true;
        }
        for (int m = 0; m < masks; m++) {
            if (((m >> letter) & 1) == 0) continue;
            if (flow[letter][m] == 0) continue;
            if (dfs2(m, mask)) {
                flow[letter][m]--;
                return true;
            }
        }
        return false;
    }

    bool canUse(int letter, int mask) {
        std::fill(flags.begin(), flags.end(), false);
        std::fill(maskFlags.begin(), maskFlags.end(), false);
        return dfs1(letter, mask);
    }

    bool constructFlow() {
        std::array<int, letters> remained = stats;
        std::array<int, masks> maskRemained = maskStats;
        std::array<int, letters> dist = {};
        std::array<int, letters> prev = {};
        std::array<int, letters> pushFlow = {};
        std::array<int, masks> maskDist = {};
        std::array<int, masks> maskPrev = {};
        std::array<int, masks> maskPushFlow = {};
        flow = {};
        int total = std::accumulate(stats.begin(), stats.end(), 0);
        while (total > 0) {
            std::fill(dist.begin(), dist.end(), 1000);
            std::fill(maskDist.begin(), maskDist.end(), 1000);
            for (size_t i = 0; i < remained.size(); i++) {
                if (remained[i] > 0) {
                    dist[i] = 0;
                    prev[i] = -1;
                    pushFlow[i] = remained[i];
                }
            }
            for (int iter = 0; iter < letters; iter++) {
                for (int i = 0; i < letters; i++) {
                    if (dist[i] != 1000) {
                        for (int j = 0; j < masks; j++) {
                            if (((j >> i) & 1) == 0) continue;
                            if (maskDist[j] > dist[i] + 1) {
                                maskDist[j] = dist[i] + 1;
                                maskPrev[j] = i;
                                maskPushFlow[j] = pushFlow[i];
                            }
                        }
                    }
                }
                for (int j = 0; j < masks; j++) {
                    if (dist[j] != 1000) {
                        for (int i = 0; i < letters; i++) {
                            if (((j >> i) & 1) == 0) continue;
                            if (dist[i] > maskDist[j] + 1 && flow[i][j] > 0) {
                                dist[i] = maskDist[j] + 1;
                                prev[i] = j;
                                pushFlow[i] = std::min(maskPushFlow[j], flow[i][j]);
                            }
                        }
                    }
                }
            }
            int minDist = 1000;
            int minIndex = -1;
            for (int j = 0; j < masks; j++) {
                if (maskRemained[j] > 0 && maskDist[j] < minDist) {
                    minDist = maskDist[j];
                    minIndex = j;
                }
            }
            if (minIndex == -1) {
                return false;
            }
            int addFlow = std::min(maskPushFlow[minIndex], maskRemained[minIndex]);
            maskRemained[minIndex] -= addFlow;
            total -= addFlow;
            while (true) {
                int prevLetter = maskPrev[minIndex];
                flow[prevLetter][minIndex] += addFlow;
                minIndex = prev[prevLetter];
                if (minIndex == -1) {
                    remained[prevLetter] -= addFlow;
                    break;
                } else {
                    flow[prevLetter][minIndex] -= addFlow;
                }
            }
        }
        return true;
    }

    void run(std::istream &in, std::ostream &out) {
        std::string s;
        in >> s;
        stats = {};
        for (size_t i = 0; i < s.length(); i++) {
            stats[s[i] - 'a']++;
        }
        allowed.assign(s.length(), 63);
        int m;
        in >> m;
        for (int i = 0; i < m; i++) {
            int pos;
            in >> pos;
            pos--;
            std::string s;
            in >> s;
            int mask = 0;
            for (char c : s) {
                mask += 1 << (c - 'a');
            }
            allowed[pos] = mask;
        }
        maskStats = {};
        for (int mask : allowed) {
            maskStats[mask]++;
        }

        if (!constructFlow()) {
            out << "Impossible\n";
            return;
        }
        std::string answer;
        minLetter = {};
        for (size_t i = 0; i < allowed.size(); i++) {
//            std::cerr << "flow\n";
//            for (int letter = 0; letter < letters; letter++) {
//                for (int mask = 0; mask < masks; mask++) {
//                    if (flow[letter][mask]) {
//                        std::cerr << letter << " " << mask << " " << flow[letter][mask] << "\n";
//                    }
//                }
//            }
            for (int letter = minLetter[allowed[i]]; letter < letters; letter++) {
                if (((allowed[i] >> letter) & 1) == 0) continue;
                if (canUse(letter, allowed[i])) {
                    answer.push_back('a' + letter);
                    minLetter[allowed[i]] = letter;
                    break;
                }
            }
        }
        out << answer << "\n";
    }
};
const int Solution::letters;
const int Solution::masks;

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}