#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::set;
using std::map;
using std::pair;
using ui32 = std::uint32_t;
using i32 = std::int32_t;
using ui64 = std::uint64_t;
using i64 = std::int64_t;
using std::size_t;
using std::sort;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto solve = []() -> unsigned {
    unsigned n, m;
    cin >> n >> m;
    vector<vector<unsigned>> a(n, vector<unsigned>(m));
    for (auto& r : a) {
      for (auto& e : r) {
        cin >> e;
      }
    }
    vector<unsigned> s(m), col_max(m), col_min(m, 1000000);
    for (size_t i = 0; i != n; ++i) {
      for (size_t j = 0; j != m; ++j) {
        s[j] += a[i][j];
        col_max[j] = std::max(col_max[j], a[i][j]);
        col_min[j] = std::min(col_min[j], a[i][j]);
      }
    }
    unsigned answer = *std::max_element(s.begin(), s.end());
    if (n == 1) {
      return answer;
    }
    for (size_t i = 0; i != m; ++i) {
      for (size_t j = 0; j != m; ++j) {
        if (i == j) {
          continue;
        }
        auto m_first = col_max[i];
        auto top_second = s[j] - col_min[j];
        answer = std::max(answer, m_first + top_second);
        if (n != 4) {
          continue;
        }
        for (size_t i_start = 0; i_start < 4; ++i_start) {
          for (size_t j_start = 0; j_start < 4; ++j_start) {
            for (auto d : {1u, 2u}) {
              auto res_i = a[i_start][i] + a[(i_start + d) % 4][i];
              auto res_j = a[j_start][j] + a[(j_start + d) % 4][j];
              answer = std::max(answer, res_i + res_j);
            }
          }
        }
      }
    }
    if (n == 2) {
      return answer;
    }
    vector<vector<unsigned>> transpose(m, vector<unsigned>(n));
    for (size_t i = 0; i != n; ++i) {
      for (size_t j = 0; j != m; ++j) {
        transpose[j][i] = a[i][j];
      }
    }
    for (size_t i = 0; i != m; ++i) {
      sort(transpose[i].begin(), transpose[i].end());
    }
    for (size_t i = 0; i != m; ++i) {
      for (size_t j = 0; j != m; ++j) {
        if (j == i) {
          continue;
        }
        for (size_t k = 0; k != m; ++k) {
          if (k == i || k == j) {
            continue;
          }
          auto r_j = col_max[j];
          auto r_k = col_max[k];
          auto need = n == 4 ? 2 : 1;
          auto r_i = 0;
          for (auto start = n - need; start != n; ++start) {
            r_i += transpose[i][start];
          }
          answer = std::max(answer, r_i + r_j + r_k);
        }
      }
    }
    if (n == 3 || m < 4) {
      return answer;
    }
    std::sort(col_max.begin(), col_max.end());
    answer = std::max(answer, col_max[m - 1] + col_max[m - 2] + col_max[m -
    3] +col_max[m - 4]);
    return answer;
  };

  unsigned tests;
  cin >> tests;
  while (tests--) {
    cout << solve() << '\n';
  }
  return 0;
}