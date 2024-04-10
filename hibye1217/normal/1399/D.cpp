#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		set<int> a[2];
		int ans[200020];
		int n;
		string s;
		cin >> n >> s;
		int cnt=0;
		for (int i = 0; i < n; i++){
			int x = s[i]-'0';
			if (a[x^1].empty()){
				cnt += 1;
				a[x].insert(cnt);
				ans[i] = cnt;
			}
			else{
				int idx = *(a[x^1].begin());
				ans[i] = idx;
				a[x^1].erase(idx);
				a[x].insert(idx);
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << endl;
	}
}