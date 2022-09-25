#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,vis[N],m;
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)vis[i]=0;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		vis[y]=1;
	}
	int rt=0;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			rt=i;
			break;
		}
	}
	for(int i=1;i<=n;++i){
		if(i==rt)continue;
		cout<<i<<' '<<rt<<'\n';	
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