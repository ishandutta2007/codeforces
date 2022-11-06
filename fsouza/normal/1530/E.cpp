#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

void print_let(int i) {
  printf("%c", 'a' + i);
}

bool check(vector<int> freq, int target, bool show_answer=false) {
  int total = accumulate(freq.begin(), freq.end(), 0);
  int ndiff = 0;
  for (int i = 0; i < 26; ++i)
    if (freq[i] > 0)
      ++ndiff;

  auto print_remaining_sorted = [&]() {
    for (int i = 0; i < 26; ++i) {
      for (int rep = 0; rep < freq[i]; ++rep) {
        print_let(i);
      }
      freq[i] = 0;
    }
  };

  if (target == 1) {
    int first_uniq = -1;
    for (int i = 0; i < 26; ++i)
      if (freq[i] == 1) {
        first_uniq = i;
        break;
      }
    if (first_uniq == -1)
      return false;

    if (show_answer) {
      print_let(first_uniq);
      freq[first_uniq] -= 1;
      print_remaining_sorted();
      printf("\n");
    }
    return true;
  }

  int smallest = -1;
  for (int i = 0; i < 26; ++i)
    if (freq[i] > 0) {
      smallest = i;
      break;
    }
  assert(smallest != -1);

  if (freq[smallest] < target) {
    if (show_answer) {
      print_remaining_sorted();
      printf("\n");
    }
    return true;
  }

  int remain = freq[smallest] - target;
  int max_group_size = target - 1;
  int need_groups = (remain + (max_group_size - 1)) / max_group_size;
  int need_sep = need_groups;
  int have_sep = total - freq[smallest];
  if (have_sep >= need_sep) {
    if (show_answer) {
      for (int rep = 0; rep < target; ++rep) {
        print_let(smallest);
        freq[smallest] -= 1;
      }
      int next_sep = smallest + 1;
      int ninrow = target;
      while (freq[smallest] > 0) {
        if (ninrow + 1 >= target) {
          while (freq[next_sep] == 0) ++next_sep;
          print_let(next_sep);
          freq[next_sep] -= 1;
          ninrow = 0;
        }
        print_let(smallest);
        freq[smallest] -= 1;
        ++ninrow;
      }
      print_remaining_sorted();
      printf("\n");
    }

    return true;
  }

  if (ndiff >= 3) {
    if (show_answer) {
      int second_smallest = smallest + 1;
      while (freq[second_smallest] == 0) ++second_smallest;
      int third_smallest = second_smallest + 1;
      while (freq[third_smallest] == 0) ++third_smallest;

      for (int i = 0; i < target - 1; ++i) {
        print_let(smallest);
        freq[smallest] -= 1;
      }
      print_let(second_smallest);
      freq[second_smallest] -= 1;
      while (freq[smallest] > 0) {
        print_let(smallest);
        freq[smallest] -= 1;
      }
      print_let(third_smallest);
      freq[third_smallest] -= 1;
      print_remaining_sorted();
      printf("\n");
    }
    return true;
  }

  if (target >= 3 && ndiff == 2) {
    if (show_answer) {
      int second_smallest = smallest + 1;
      while (freq[second_smallest] == 0) ++second_smallest;

      for (int i = 0; i < target - 1; ++i) {
        print_let(smallest);
        freq[smallest] -= 1;
      }
      print_let(second_smallest);
      freq[second_smallest] -= 1;

      int ninrow = 0;
      while (freq[smallest] > 0) {
        if (ninrow + 1 + 1 >= target && freq[second_smallest] > 0) {
          print_let(second_smallest);
          freq[second_smallest] -= 1;
          ninrow = 0;
        }
        print_let(smallest);
        freq[smallest] -= 1;
      }

      print_remaining_sorted();
      printf("\n");
    }
    return true;
  }

  if (ndiff == 2) {
    assert(target == 2);
    if (show_answer) {
      int second_smallest = smallest + 1;
      while (freq[second_smallest] == 0) ++second_smallest;

      print_let(smallest);
      freq[smallest] -= 1;
      while (freq[second_smallest] > 0) {
        print_let(second_smallest);
        freq[second_smallest] -= 1;
      }
      while (freq[smallest] > 0) {
        print_let(smallest);
        freq[smallest] -= 1;
      }

      printf("\n");
    }
    return true;
  }

  return false;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    const int maxlen = 1e5 + 10;
    static char str[maxlen + 1];
    scanf(" %s", str);
    vector<int> freq(26, 0);
    const int len = strlen(str);
    int n = 0;
    for (int i = 0; i < len; ++i)
      if ('a' <= str[i] && str[i] <= 'z') {
        freq[str[i] - 'a'] += 1;
        n += 1;
      }

    int l = 1, r = n;
    while (l < r) {
      int m = (l + r) / 2;
      if (check(freq, m)) r = m;
      else l = m + 1;
    }
    check(freq, l, true);
  }
  return 0;
}