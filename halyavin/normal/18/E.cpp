#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif

#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

const int mins = 4;

struct info {
  std::array<char, mins> letterOdd;
  std::array<char, mins> letterEven;
  std::array<int, mins> sumOdd;
  std::array<int, mins> sumEven;
};

info findMin(std::string row) {
  info result;
  std::array<std::pair<int, char>, 26> stat;
  for (int i = 0; i < 26; i++) {
    stat[i].second = (char) ('a' + i);
    stat[i].first = 0;
  }
  for (int i = 0; i < row.length(); i += 2) {
    for (int j = 0; j < 26; j++) {
      if ('a' + j != row[i]) {
        stat[j].first++;
      }
    }
  }
  std::sort(stat.begin(), stat.end());
  for (int i = 0; i < mins; i++) {
    result.letterEven[i] = stat[i].second;
    result.sumEven[i] = stat[i].first;
  }

  for (int i = 0; i < 26; i++) {
    stat[i].second = (char) ('a' + i);
    stat[i].first = 0;
  }
  for (int i = 1; i < row.length(); i += 2) {
    for (int j = 0; j < 26; j++) {
      if ('a' + j != row[i]) {
        stat[j].first++;
      }
    }
  }
  std::sort(stat.begin(), stat.end());
  for (int i = 0; i < mins; i++) {
    result.letterOdd[i] = stat[i].second;
    result.sumOdd[i] = stat[i].first;
  }
  return result;
}

void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  std::vector<std::string> flag(n);
  for (int i = 0; i < n; i++) {
    in >> flag[i];
  }

  std::vector<info> minLetters(n);
  for (int i = 0; i < n; i++) {
    minLetters[i] = findMin(flag[i]);
  }

  const int inf = 1000000000;
  std::vector<std::array<std::array<int, mins>, mins>> dyn(n);
  std::vector<std::array<std::array<int, mins>, mins>> prev(n);
  for (int i = 0; i < mins; i++) {
    for (int j = 0; j < mins; j++) {
      if (minLetters[0].letterEven[i] != minLetters[0].letterOdd[j]) {
        dyn[0][i][j] = minLetters[0].sumEven[i] + minLetters[0].sumOdd[j];
      } else {
        dyn[0][i][j] = inf;
      }
    }
  }
  for (int len = 1; len < n; len++) {
    for (int icur = 0; icur < mins; icur++) {
      for (int jcur = 0; jcur < mins; jcur++) {
        int pprev = -1;
        int min = inf;
        if (minLetters[len].letterEven[icur] == minLetters[len].letterOdd[jcur]) {
          dyn[len][icur][jcur] = inf;
          continue;
        }
        for (int iprev = 0; iprev < mins; iprev++) {
          if (minLetters[len].letterEven[icur] == minLetters[len - 1].letterEven[iprev]) {
            continue;
          }
          for (int jprev = 0; jprev < mins; jprev++) {
            if (minLetters[len].letterOdd[jcur] == minLetters[len - 1].letterOdd[jprev]) {
              continue;
            }
            if (dyn[len - 1][iprev][jprev] < min) {
              min = dyn[len - 1][iprev][jprev];
              pprev = iprev * mins + jprev;
            }
          }
        }
        dyn[len][icur][jcur] = min + minLetters[len].sumEven[icur] + minLetters[len].sumOdd[jcur];
        prev[len][icur][jcur] = pprev;
      }
    }
  }
  std::vector<std::pair<int, int>> answer(n);
  int min = inf;
  int iopt = -1;
  int jopt = -1;
  for (int i = 0; i < mins; i++) {
    for (int j = 0; j < mins; j++) {
      if (dyn[n - 1][i][j] < min) {
        min = dyn[n - 1][i][j];
        iopt = i;
        jopt = j;
      }
    }
  }
  for (int i = n; i-- > 0;) {
    answer[i].first = iopt;
    answer[i].second = jopt;
    int before = prev[i][iopt][jopt];
    iopt = before / mins;
    jopt = before % mins;
  }
  out << min << std::endl;
  for (int i = 0; i < n; i++) {
    char cEven = minLetters[i].letterEven[answer[i].first];
    char cOdd = minLetters[i].letterOdd[answer[i].second];
    for (int j = 0; j < m; j++) {
      if (j & 1) {
        out << cOdd;
      } else {
        out << cEven;
      }
    }
    out << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}