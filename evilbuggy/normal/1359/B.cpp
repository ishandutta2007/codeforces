#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
	int n, m, x, y;
	cin>>n>>m>>x>>y;
	y = min(y, x + x);
	int ans = 0;
	string s;
	for(int i = 0; i < n; i++){
		cin>>s;
		for(int j = 0; j < m; j++){
			if(s[j] == '*')continue;
			if(j + 1 < m && s[j + 1] == '.'){
				ans += y;
				s[j + 1] = '*';
			}else{
				ans += x;
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--)solve();

	return 0;
}