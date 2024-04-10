#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,m,q;
string s[40001],t[540001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n ;i++) cin >> s[i];
	for(int i=0; i<m ;i++) cin >> t[i];
	cin >> q;
	for(int i=1; i<=q ;i++){
		int y;cin >> y;y--;
		cout << s[y%n] << t[y%m] << '\n';
	}
}