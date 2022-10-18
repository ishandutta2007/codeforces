/* Written by Filip Hlasek 2020 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int N;
vector<vector<pair<int, int> > > v, nv;

long long count_inversions(const vector<pair<int, int> >& v0, const vector<pair<int, int> >& v1) {
  long long ans = 0;
  int pos = 0;
  REP(i, v0.size()) {
    while (pos < (int)v1.size() && v0[i].second >= v1[pos].second) pos++;
    ans += pos;
  }
  return ans;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  v.push_back(vector<pair<int, int> >());

  REP(i, N) {
    int a;
    scanf("%d", &a);
    v[0].push_back(make_pair(a, i));
  }

  long long ans = 0;
  int x = 0;

  FORD(b, 30, 0) {
    long long inv0 = 0, inv1 = 0;
    REP(i, v.size()) {
      vector<pair<int, int> > v0, v1;
      REP(j, v[i].size()) {
        if (v[i][j].first & (1 << b)) v1.push_back(v[i][j]);
        else v0.push_back(v[i][j]);
      }
      long long inv = count_inversions(v0, v1);
      inv0 += inv;
      inv1 += (long long)v0.size() * (long long)v1.size() - inv;

      if (v0.size()) nv.push_back(v0);
      if (v1.size()) nv.push_back(v1);
    }

    if (inv0 > inv1) x |= (1 << b);
    ans += min(inv0, inv1);

    v = nv;
    nv.clear();
  }

  cout << ans << " " << x << endl;
	return 0;
}