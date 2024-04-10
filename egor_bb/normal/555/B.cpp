#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;

using namespace std;

struct A{
	ll x, t, num, d;
	A(): x(), t(), num(), d(){}
	A(ll x, ll t, ll num, ll d): x(x), t(t), num(num), d(d){}
};

bool cmp(A &x, A &y){
	return (x.x < y.x) || (x.x == y.x && x.t < y.t); 
}

int n, m, k;
ll l[200005], r[200005], t = 0, ans[200005];
A a[600005];

int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%I64d%I64d", &l[i], &r[i]);
		if (i){
			a[k++] = (A(l[i] - r[i - 1], 0, i - 1, r[i] - l[i - 1]));
			a[k++] = (A(r[i] - l[i - 1], 2, i - 1, 0));
		}
	}
	for (int i = 0; i < m; i++){
		ll d; scanf("%I64d", &d);
		a[k++] = (A(d, 1, i + 1, 0));
	}
	sort(a, a + k, &cmp);
	set <pll> s;
	for (int i = 0; i < k; i++){
		if (a[i].t == 0){
			s.insert(mp(a[i].d, a[i].num));
		} else if (a[i].t == 1){
			if (s.size() == 0) continue;
			pll p = *s.begin();
			s.erase(s.begin());
			ans[p.second] = a[i].num;
		} else {
			if (!ans[a[i].num]){
				printf("No\n");
				return 0;
			} 
			s.erase(mp(a[i].x, a[i].num));
		}
	}
	printf("Yes\n");
	for (int i = 0; i < n - 1; i++){
		printf("%d ", ans[i]);
	}
}