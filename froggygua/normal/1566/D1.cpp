#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N],m,b[N],s[N],vis[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		b[i]=a[i];
		s[i]=vis[i]=0;
	}
	sort(b+1,b+n*m+1);
	int ans=0;
	for(int i=1;i<=n*m;++i){
		for(int j=n*m;j>=1;--j){
			if(a[i]==b[j]&&!vis[j]){
				vis[j]=1;
				ans+=s[j];
				for(int k=j;k<=n*m;++k)++s[k];
				break;	
			}
		}
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