#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define LL long long

pair <LL, LL> a[100005];
int c[100005];
vector <pair<LL, LL> > v;

int main () {
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)  {
		cin >> a[i].fi;
		c[a[i].fi]++;
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i].se;
	}
	
	int t = 0;
	for (int i = 1; i <= k; i++) {
		if (c[i] == 0) t++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (c[a[i].fi] > 1) v.push_back(make_pair(a[i].se, a[i].fi));
	}
	
	sort(v.begin(), v.end());
	
	LL hasil = 0;
	for (int i = 0; i < v.size(); i++) {
		//cout << v[i].se << ' ' << c[v[i].se] << endl;
		if (c[v[i].se] > 1 && t > 0) {
			hasil += v[i].fi;
			c[v[i].se]--;
			t--;
		}
	}
	
	cout << hasil << endl;
	return 0;
}