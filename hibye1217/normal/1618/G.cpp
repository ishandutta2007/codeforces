#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define fr first
#define sc second
using ll = long long;
using pl2 = pair<ll, ll>;

ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

// #define DEBUG

typedef pair<ll, pl2> pl3;
pl2 arr[400020]; ll sum[400020];
int ptr[400020];
pl2 qry[200020]; ll res[200020];
pl3 par[400020];

inline ll sumf(int st, int ed){
	return sum[ed] - sum[st-1];
}

int fnd(int a){
	if (a == par[a].fr){ return a; }
	return par[a].fr = fnd( par[a].fr );
}

ll ans = 0;
void uni(int a, int b){
	int pa = fnd(a), pb = fnd(b);
	if (pa == pb){ return; }
	par[pa].fr = pb;
	int cnt = par[pa].sc.fr + par[pb].sc.fr;
	//cout << "CHK " << a << ' ' << b << ' ' << ans << endl;
	ans -= par[pa].sc.sc + par[pb].sc.sc;
	//cout << "CHK " << a << ' ' << b << ' ' << ans << endl;
	ans += sumf(pb-cnt+1, pb);
	par[pb].sc.fr += par[pa].sc.fr;
	par[pb].sc.sc = sumf(pb-cnt+1, pb);
	//cout << "CHK " << a << ' ' << b << ' ' << ans << endl;
}

void Main(){
	int n, m, k, q; cin >> n >> m >> q;
	for (int i = 1; i <= n; i++){ cin >> arr[i].fr; arr[i].sc = 1; ans += arr[i].fr; }
	for (int i = 1; i <= m; i++){ cin >> arr[n+i].fr; arr[n+i].sc = 0; }
	k = n+m;
	sort(arr+1, arr+k+1);
	for (int i = 1; i <= k; i++){
		sum[i] = sum[i-1] + arr[i].fr;
		par[i].fr = i;
		if (arr[i].sc == 1){ par[i].sc = {1, arr[i].fr}; }
		else{ par[i].sc = {0, 0}; }
	}
	priority_queue< pl2, vector<pl2>, greater<pl2> > pq;
	for (int i = 1; i < k; i++){
		pq.push({ arr[i+1].fr-arr[i].fr, i });
	}
	int cnt = 0;
	for (int i = 1; i <= k; i++){
		if (arr[i].sc == 1){ cnt += 1; ptr[cnt] = i; }
	}
	for (int i = 1; i <= q; i++){
		cin >> qry[i].fr; qry[i].sc = i;
	}
	sort(qry+1, qry+q+1);
	for (int i = 1; i <= q; i++){
		ll x = qry[i].fr; int qi = qry[i].sc;
		while (!pq.empty()){
			ll val = pq.top().fr; int idx = pq.top().sc;
			if (val <= x){ uni(idx, idx+1); pq.pop(); }
			else{ break; }
		}
		res[qi] = ans;
	}
	for (int i = 1; i <= q; i++){ cout << res[i] << endl; }
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}