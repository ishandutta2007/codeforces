#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n;
char s[N];
void Solve(){
	cin>>n;
	cin>>(s+1);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='1')++cnt;
	}
	if(!cnt||cnt&1){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	int rt=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='0'&&s[i==1?n:i-1]=='1'){
			rt=i;
			break;
		}
	}
	if(!rt)rt=1;
	for(int i=1;i<n;++i){
		int v=(rt+i-2)%n+1;
		int u=(rt+i-1)%n+1;
		if(s[v]=='0'){
			cout<<u<<' '<<v<<'\n';
		}
		else{
			cout<<u<<' '<<rt<<'\n';
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}