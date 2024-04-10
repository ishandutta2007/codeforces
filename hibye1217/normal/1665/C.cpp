#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

int cnt[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i < n; i++){
			int x; cin >> x; cnt[x] += 1;
		}
		cnt[0] = 1;
		sort(cnt, cnt+n+1, [](int a, int b){ return a > b; });
		priority_queue<int> pq;
		for (int i = 0; cnt[i] > 0; i++){ pq.push(cnt[i]); }
		int ans = 0;
		priority_queue<int> tmp;
		int num = pq.size();
		while (!pq.empty()){
			int now = pq.top(); pq.pop();
			now -= num; num -= 1;
			if (now > 0){ tmp.push(now); }
			ans += 1;
		}
		pq = tmp;
		int dlt = 0;
		while (!tmp.empty()){
			int now = tmp.top(); tmp.pop();
			if (now <= dlt){ break; }
			ans += 1; dlt += 1; tmp.push(now-1);
		}
		cout << ans << endl;
		for (int i = 0; i <= n; i++){ cnt[i] = 0; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}