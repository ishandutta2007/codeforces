#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char str[50005];

vector<int> pos1[26], pos2[26][26], pos3[26][26][26], pos4[26][26][26][26];

int solve(int l1, int l2, vector<int>* a, vector<int>* b) {
  if (a->size() > b->size()) {
    swap(a, b);
    swap(l1, l2);
  }
  int ret = 1000000;
  for (int i = 0; i < a->size(); ++i) {
    int pos = lower_bound(b->begin(), b->end(), a->at(i)) - b->begin();
    if (pos >= 0 && pos < b->size()) {
      // cout << a->at(i) << " " << b->at(pos) << endl;
      int l = min(a->at(i), b->at(pos)), r = max(a->at(i) + l1 - 1, b->at(pos) + l2 - 1);
      ret = min(ret, r - l + 1);
    }
    --pos;
    if (pos >= 0 && pos < b->size()) {
      // cout << a->at(i) << " " << b->at(pos) << endl;
      int l = min(a->at(i), b->at(pos)), r = max(a->at(i) + l1 - 1, b->at(pos) + l2 - 1);
      ret = min(ret, r - l + 1);
    }
  }
  return ret;
}

int code(char s[]) {
  int l = strlen(s);
  int ret = 0;
  for (int i = l - 1; i >= 0; --i)
    ret = ret * 31 + s[i] - 'a' + 1;
  return ret;
}

map<pair<int, int>, int> f;

vector<int>* get(char s[]) {
  int l = strlen(s);
  if (l == 1) return &pos1[s[0] - 'a'];
  if (l == 2) return &pos2[s[0] - 'a'][s[1] - 'a'];
  if (l == 3) return &pos3[s[0] - 'a'][s[1] - 'a'][s[2] - 'a'];
  if (l == 4) return &pos4[s[0] - 'a'][s[1] - 'a'][s[2] - 'a'][s[3] - 'a'];
  return NULL;
}

int main() {
  gets(str);
  int n = strlen(str);
  for (int i = 0; i < n; ++i) {
    pos1[str[i] - 'a'].push_back(i);
  }
  for (int i = 0; i + 1 < n; ++i) {
    pos2[str[i] - 'a'][str[i + 1] - 'a'].push_back(i);
  }
  for (int i = 0; i + 2 < n; ++i) {
    pos3[str[i] - 'a'][str[i + 1] - 'a'][str[i + 2] - 'a'].push_back(i);
  }
  for (int i = 0; i + 3 < n; ++i) {
    pos4[str[i] - 'a'][str[i + 1] - 'a'][str[i + 2] - 'a'][str[i + 3] - 'a'].push_back(i);
  }
  int q;
  scanf("%d\n", &q);
  char a[5] = {0}, b[5] = {0};
  while (q--) {
    scanf("%s %s\n", a, b);
    int ca = code(a), cb = code(b);
    if (!f.count(make_pair(ca, cb))) {
      vector<int>* va = get(a);
      vector<int>* vb = get(b);
      int val = solve(strlen(a), strlen(b), va, vb);
      if (val == 1000000) val = -1;
      f[make_pair(ca, cb)] = val;
      f[make_pair(cb, ca)] = val;
    }
    printf("%d\n", f[make_pair(ca, cb)]);
  }
  return 0;
}