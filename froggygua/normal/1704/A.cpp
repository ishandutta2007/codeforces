#include<bits/stdc++.h>
using namespace std;
#define N 2333
typedef long long ll;
char s[N],t[N];
int n,m;
void Solve(){
	cin>>n>>m;
	cin>>(s+1);
	cin>>(t+1);
	for(int i=1;i<m;++i){
		if(t[m-i+1]^s[n-i+1]){
			cout<<"NO\n";
			return;
		}
	}
	for(int i=1;i<=n-m+1;++i){
		if(s[i]==t[1]){
			cout<<"YES\n";
			return;
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