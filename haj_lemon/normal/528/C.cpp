#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
struct Info{int nu,ne;}a[N];
int m,n,x,y,num=1,b[N],d[N],ns,st[N],g[N],ng,cur[N];
bool v1[N],v2[N];
void jb(int x,int y){
	a[++num].nu=y;a[num].ne=b[x];b[x]=num;d[x]++;
	a[++num].nu=x;a[num].ne=b[y];b[y]=num;d[y]++;
}
void dfs(int x){
	v1[x]=0;
	for (int y=cur[x];y;y=a[y].ne){
		cur[x]=y;
		if (v2[y/2]){v2[y/2]=0;st[++ns]=y;dfs(a[y].nu);}
		y=cur[x];
	}
	if (ns>0)g[++ng]=st[ns--];
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){cin>>x>>y;jb(x,y);}
	for (int i=1,la=0;i<=n;i++){if(d[i]%2){if (la){jb(la,i);la=0;m++;}else la=i;}}
	if (m%2==1){jb(1,1);m++;}
	for (int i=1;i<=m;i++)v2[i]=1;
	for (int i=1;i<=n;i++)cur[i]=b[i];
	dfs(1);
	for (int i=1;i<=ng;i++)if ((i%2)^(g[i]%2))swap(a[g[i]].nu,a[g[i]^1].nu);
	cout<<m<<endl;
	for (int i=1;i<=m;i++)cout<<a[i*2+1].nu<<' '<<a[i*2].nu<<endl;
	return 0;
}