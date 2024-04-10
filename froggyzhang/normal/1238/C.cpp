#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int h,n,a[N];
void Solve(){
	cin>>h>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int ans=1;
	for(int i=1,u=h;i<=n;++i){
		if(a[i]==u)--ans;
		else if(a[i]<u)++ans,u=a[i]-1;
		if(!u)--ans;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}