#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
int n,a[N];
void Solve(){
	string s;
	cin>>n;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'0';
	}
	int p=0,x=0,y=0;
	for(int i=1;i<=n/2;++i){
		if(!a[i]&&!a[n-i+1])++x;
		else if(a[i]^a[n-i+1])++y;
	}
	if(n&1)p=a[n/2+1]^1;
	if(!y)cout<<(p&&x?"ALICE":"BOB")<<'\n';
	else cout<<(p&&!x&&y==1?"DRAW":"ALICE")<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}