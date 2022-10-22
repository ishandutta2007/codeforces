#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define fr first
#define sc second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int len = s.size();
		if (len > 10) cout << s[0] << len-2 << s[len-1] << endl;
		else cout << s << endl;
	}
}