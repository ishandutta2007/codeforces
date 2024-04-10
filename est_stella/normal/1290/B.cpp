#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

string s;
int q;
int sum[200010][30];

int main() {
	fast;

	cin >> s;

	s = "*" + s;

	for(int i=1; i<s.size(); i++) {
		for(int j=0; j<='z'-'a'; j++) {
			sum[i][j] = sum[i-1][j];
		}

		sum[i][s[i]-'a']++;
	}

	cin >> q;

	while(q--) {
		int l, r;
		cin >> l >> r;

		if(l == r || s[l] != s[r]) {
			cout << "Yes\n";
			continue;
		}

		int cnt = 0;
		for(int i=0; i<='z'-'a'; i++) {
			if(sum[r][i] - sum[l-1][i] > 0) cnt++;
		}

		if(cnt > 2) cout << "Yes\n";
		else cout << "No\n";
	}
}