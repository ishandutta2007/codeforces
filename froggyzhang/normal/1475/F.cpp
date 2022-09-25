#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
int T,n,a[N][N];
char s[N][N],t[N][N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>(s[i]+1);	
	}
	for(int i=1;i<=n;++i){
		cin>>(t[i]+1);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=s[i][j]==t[i][j]?0:1;		
		}
	}
	for(int i=2;i<=n;++i){
		for(int j=2;j<=n;++j){
			if(a[1][1]^a[1][j]^a[i][1]^a[i][j]){
				cout<<"No\n";
				return;	
			}
		}
	}
	cout<<"Yes\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)Solve();
	return 0;
}