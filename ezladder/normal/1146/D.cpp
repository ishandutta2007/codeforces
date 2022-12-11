#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define x first
#define ll long long
#define y second

using namespace std;

int a, b, m;
bool was[5000007];
int cnt = 1;

int MA;

void go(int pos){
	vector<int> t;
	t.pb(pos);
	int uk = 0;
	while(uk < t.size()){
		int v = t[uk++];
		cnt++;
		was[v] = 1;
		if (v + a <= MA && !was[v + a]) t.pb(v + a);
		if (v - b >= 0 && !was[v - b]) t.pb(v - b);
	}
}

ll solve(ll n, ll a, ll b, ll m) {
    if (b == 0) return n * (a / m);
    if (a >= m) return n * (a / m) + solve(n, a % m, b, m);
    if (b >= m) return n * (n - 1) / 2 * (b / m) + solve(n, a, b % m, m);
    return solve((a + b * n) / m, (a + b * n) % m, m, b);
}

ll add(int val, int l, int r){
	return solve(r - l + 1, l, 1, val) + (r - l + 1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
//	freopen("input.txt", "r", stdin);
	cin >> m >> a >> b;
	int g = __gcd(a, b);
	was[0] = 1;
	ll ans = 1;
	for (int i = 1; i <= min(m, 5000000); i++){
		MA = i;
		if (i - a >= 0 && was[i - a]){
			go(i);
		}
		ans += cnt;
	}
	//cout << g << ' ' << min(m, 5000000) + 1 << ' ' << m << endl;
	ans += add(g, min(m, 5000000) + 1, m);
	cout << ans;
}