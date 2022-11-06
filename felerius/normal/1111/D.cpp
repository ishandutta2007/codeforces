#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

constexpr static size_t MAX_NUM = 100000;
constexpr static uint32_t MOD = 1000000007;

constexpr uint32_t mod_pow(uint32_t n, uint32_t mod, uint32_t pow) {
    if (pow == 0) {
        return 1;
    }

    uint64_t r = mod_pow(n, mod, pow / 2);
    if (pow % 2 == 1) {
        return static_cast<uint32_t>(r * r % mod * n % mod);
    }

    return static_cast<uint32_t>(r * r % mod);
}

constexpr uint32_t prime_mod_inv(uint32_t n, uint32_t mod_prime) {
    return mod_pow(n, mod_prime, mod_prime - 2);
}

constexpr auto make_factorial_array() {
    array<uint32_t, MAX_NUM + 1> result = {0};
    result[0] = 1;
    for (size_t i = 1; i < result.size(); ++i) {
        result[i] = static_cast<uint32_t>(static_cast<uint64_t>(i) *
                                          result[i - 1] % MOD);
    }

    return result;
}

constexpr static auto FACTORIALS = make_factorial_array();

//auto sub(uint32_t a, uint32_t b) {
//    return b > a ? (a + MOD - b) % MOD : a - b;
//
//}

vector<uint32_t>
compute_results(const vector<size_t>& type_counts, size_t size) {
    unsigned long num_types = type_counts.size();
    vector<uint32_t> result_matrix(num_types * num_types);

    vector<uint32_t> prev_row(size + 1);
    vector<uint32_t> cur_row(size + 1);
    prev_row[0] = 1;
    for (auto count : type_counts) {
        for (size_t i = 0; i < count; ++i) {
            cur_row[i] = prev_row[i];
        }

        for (size_t i = count; i <= size; ++i) {
            cur_row[i] = (prev_row[i] + prev_row[i - count]) % MOD;
        }

        swap(cur_row, prev_row);
    }

    for (size_t i = 0; i < num_types; ++i) {
        cur_row = prev_row;
        auto a = type_counts[i];
        for (size_t k = a; k <= size; ++k) {
            cur_row[k] = (cur_row[k] + MOD - cur_row[k - a]) % MOD;
//            cur_row[k] = sub(cur_row[k], cur_row[k - a]);
        }

        result_matrix[i * num_types + i] = cur_row.back();

        for (size_t j = i + 1; j < num_types; ++j) {
            cur_row = prev_row;
            auto b = type_counts[j];
            auto[x, y] = minmax(a, b);
            for (size_t k = x; k < y; ++k) {
                cur_row[k] = (cur_row[k] + MOD - cur_row[k - x]) % MOD;
//                cur_row[k] = sub(cur_row[k], cur_row[k - x]);
            }
            for (size_t k = y; k < x + y; ++k) {
                cur_row[k] = (cur_row[k] + 2 * MOD - cur_row[k - x] -
                              cur_row[k - y]) % MOD;
//                cur_row[k] = sub(cur_row[k], cur_row[k - x]);
//                cur_row[k] = sub(cur_row[k], cur_row[k - y]);
            }
            for (size_t k = x + y; k <= size; ++k) {
                cur_row[k] = (cur_row[k] + 3 * MOD - cur_row[k - x] -
                              cur_row[k - y] - cur_row[k - x - y]) % MOD;
//                cur_row[k] = sub(cur_row[k], cur_row[k - x]);
//                cur_row[k] = sub(cur_row[k], cur_row[k - y]);
//                cur_row[k] = sub(cur_row[k], cur_row[k - x - y]);
            }

            result_matrix[i * num_types + j] = result_matrix[j * num_types +
                                                             i] = cur_row.back();
        }
    }

    return result_matrix;
}

size_t get_type_idx(char c) {
    if (c >= 'a') {
        return static_cast<size_t>(c - 'a');
    } else {
        return static_cast<size_t>(26 + c - 'A');
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    array<size_t, 52> all_type_counts = {0};
    for (char c : s) {
        ++all_type_counts[get_type_idx(c)];
    }

    vector<size_t> type_counts;
    array<size_t, 52> all_type_map = {0};
    uint64_t multinom_coeff = FACTORIALS[s.size() / 2];
    multinom_coeff = (multinom_coeff * multinom_coeff) % MOD;
    for (size_t i = 0; i < 52; ++i) {
        auto count = all_type_counts[i];
        if (count > 0) {
            multinom_coeff =
                    (multinom_coeff * prime_mod_inv(FACTORIALS[count], MOD)) %
                    MOD;
            all_type_map[i] = type_counts.size();
            type_counts.emplace_back(count);
        }
    }

    auto result_matrix = compute_results(type_counts, s.size() / 2);

    size_t q;
    cin >> q;
    while (q--) {
        size_t x, y;
        cin >> x >> y;

        size_t a = all_type_map[get_type_idx(s[x - 1])];
        size_t b = all_type_map[get_type_idx(s[y - 1])];
        cout << (2 * multinom_coeff *
                 result_matrix[a * type_counts.size() + b] % MOD) << '\n';
    }

    return 0;
}