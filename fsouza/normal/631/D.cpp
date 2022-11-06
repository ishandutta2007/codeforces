#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct range_t {
  lint many;
  char c;
  bool operator == (const range_t &o) const {
    return many == o.many && c == o.c;
  }
  bool operator != (const range_t &o) const {
    return many != o.many || c != o.c;
  }
};

vector<range_t> read(int n) {
  vector<range_t> result;
  for (int i = 0; i < n; ++i) {
    lint many;
    char c;
    cin >> many >> c >> c;
    if (!result.empty() && result.back().c == c) result.back().many += many;
    else result.push_back({many, c});
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<range_t> text, str;
  {
    int n, m;
    cin >> n >> m;
    text = read(n), str = read(m);
  }
  lint result = 0;
  if (str.size() == 1) {
    for (int i = 0; i < (int)text.size(); ++i)
      if (text[i].c == str[0].c && text[i].many >= str[0].many)
	result += text[i].many - str[0].many + 1;
  } else if (str.size() == 2) {
    for (int i = 0; i+1 < (int)text.size(); ++i)
      if (text[i].c == str[0].c && text[i].many >= str[0].many &&
	  text[i+1].c == str[1].c && text[i+1].many >= str[1].many)
	++result;
  } else {
    vector<range_t> mid(str.begin()+1, str.end()-1);
    int len = mid.size();
    vector<int> failure(len+1);
    failure[0] = failure[1] = 0;
    for (int s = 2; s <= len; ++s) {
      failure[s] = failure[s-1];
      while (failure[s] > 0 && mid[s-1] != mid[failure[s]])
	failure[s] = failure[failure[s]];
      if (mid[s-1] == mid[failure[s]]) ++failure[s];
    }
    int size = 0;
    for (int i = 0; i < (int)text.size(); ++i) {
      while (size > 0 && text[i] != mid[size]) size = failure[size];
      if (text[i] == mid[size]) {
	++size;
	if (size == len) {
	  int before = i-size, after = i+1;
	  if (before >= 0 && after < (int)text.size() &&
	      text[before].c == str.front().c && text[before].many >= str.front().many &&
	      text[after].c == str.back().c && text[after].many >= str.back().many)
	    ++result;

	  size = failure[size];
	}
      }
    }
  }

  cout << result << endl;

  return 0;
}