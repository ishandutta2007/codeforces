/* Written by Filip Hlasek 2019 */
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

vector<int> by_first, by_last;

int main(int argc, char *argv[]) {
  long long ans = 0;
  int N;
  scanf("%d", &N);
  REP(i, N) {
    int L;
    scanf("%d", &L);
    vector<int> v;
    REP(j, L) { int x; scanf("%d", &x); v.push_back(x); }
    bool ascent = false;
    REP(j, L - 1) if (v[j + 1] > v[j]) ascent = true;
    if (ascent) {
      ans += 2 * (by_first.size() + N - i) - 1;
    } else {
      by_first.push_back(v[0]);
      by_last.push_back(v[L - 1]);
    }
  }
  sort(by_first.begin(), by_first.end());
  sort(by_last.begin(), by_last.end());
  int first_id = 0;
  REP(i, by_last.size()) {
    while (first_id < (int)by_first.size() && by_first[first_id] <= by_last[i]) ++first_id;
    ans += by_first.size() - first_id;
  }
  cout << ans << endl;
	
	return 0;
}