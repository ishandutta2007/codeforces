#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <functional>

#define pb push_back
#define mp make_pair

using namespace std;

int n;
bool primes[111111], used[111111];
vector<pair<int, int> > ans;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i=2; i<1200; i++) if (!primes[i]) for (int j=i*2; j<111111; j+=i) primes[j]=true;
	for (int i=n/2; i>=2; i--) if (!primes[i]) {
		vector<int> v;
		for (int j=i; j<=n; j+=i) if (!used[j]&&j!=2*i) v.pb(j);
		for (int j=0; j<v.size()-1; j+=2) ans.pb(mp(v[j], v[j+1])), used[v[j]]=used[v[j+1]]=true;
		if (v.size()%2) ans.pb(mp(v.back(), 2*i)), used[v.back()]=used[2*i]=true;
	}
	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++) cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}