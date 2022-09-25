#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,s,vis[N],tot;
ll t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s>>t;
	--s;
	memset(vis,-1,sizeof(vis));
	vis[s]=0;
	int u=s;
	for(int p=1;;++p){
		for(int i=1;i<=n;++i){
			u=(u<m?(u+t)%n:((u-t)%n+n)%n);
			--t;
			if(!t){
				cout<<u+1<<'\n';
				return 0;
			}
		}
		if(~vis[u]){
			t%=1LL*(p-vis[u])*n;
		}
		vis[u]=p;
	}
	return 0;
}