#include<bits/stdc++.h>
using namespace std;
int n,a[105],b[105],g[105][105],vst[105],mch[105];
bool dfs(int x){
    for(int y=1;y<=n;y++){
        if(!g[x][y]||vst[y])continue;
        vst[y]=1;
        if(!mch[y]||dfs(mch[y]))return mch[y]=x,1;
    }
    return 0;
}
int Hungary(){
	int ans=0;
    memset(mch,0,sizeof(mch));
    for(int i=1;i<=n;i++)memset(vst,0,sizeof(vst)),ans+=dfs(i);
    return ans;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==b[j]||a[i]+1==b[j])g[i][j]=1;
		}
	}
	if(Hungary()==n)puts("YES");
	else puts("NO");
	memset(g,0,sizeof(g));
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve(); 
}