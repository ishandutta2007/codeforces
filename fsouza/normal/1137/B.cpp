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

struct kmp_t {
  string word;
  vector<int> failure;
  kmp_t(const string &_word): word(_word) {
    int n = word.size();
    failure.resize(n + 1, 0);
    for (int s = 2; s <= n; ++s) {
      failure[s] = failure[s - 1];
      while (failure[s] > 0 && word[failure[s]] != word[s - 1])
        failure[s] = failure[failure[s]];
      if (word[failure[s]] == word[s - 1])
        failure[s] += 1;
    }
  }
  vector<int> matches_in(const string &text) {
    vector<int> result;
    int s = 0;
    for (int i = 0; i < (int)text.size(); ++i) {
      while (s > 0 && word[s] != text[i])
        s = failure[s];
      if (word[s] == text[i])
        s += 1;
      if (s == (int)word.size()) {
        result.push_back(i - (int)word.size() + 1);
        s = failure[s];
      }
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  string t;
  cin >> s;
  cin >> t;

  int n0 = 0, n1 = 0;
  for (char c : s)
    if (c == '0') ++n0;
    else ++n1;

  kmp_t kmp(t);
  string result;

  int size = 0;
  while (n0 > 0 && n1 > 0) {
    if (kmp.word[size] == '0') {
      ++size;
      --n0;
      result += string(1, '0');
    } else {
      ++size;
      --n1;
      result += string(1, '1');
    }
    if (size == (int)kmp.word.size())
      size = kmp.failure[size];
  }
  result += string(n0, '0');
  result += string(n1, '1');

  printf("%s\n", result.c_str());

  return 0;
}