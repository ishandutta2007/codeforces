#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
int a[111];
int b[111];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	int ans = 0;
	for (int it = 0; it < 1e5; it++){
		if (ans == n) break;
		int now = 0;
		for (auto c : s) if (c == '1') now++;
		ans = max(ans, now);
		//cout << it << ' ' << now << endl;
		for (int i = 0; i < n; i++){
			if (it >= b[i] && (it - b[i]) % a[i] == 0){
				if (s[i] == '1') s[i] = '0'; else s[i] = '1';
			}
		}
	}
	cout << ans;
}