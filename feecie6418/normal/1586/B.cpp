#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,is[100005];
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),is[y]=1;
	for(int i=1;i<=n;i++){
		if(!is[i]){
			for(int j=1;j<=n;j++)if(j!=i)cout<<i<<' '<<j<<'\n';
			break;
		}
	}
	for(int i=1;i<=n;i++)is[i]=0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}