#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char s[10][10];
void Solve(){
	cin>>n>>m;
	int mnx=n+1,mny=m+1;
	for(int i=1;i<=n;++i){
		cin>>(s[i]+1);
		for(int j=1;j<=m;++j){
			if(s[i][j]=='R'){
				mnx=min(mnx,i);
				mny=min(mny,j);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i][j]=='R'&&i==mnx&&j==mny){
				cout<<"YES\n";
				return;
			}
		}
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}