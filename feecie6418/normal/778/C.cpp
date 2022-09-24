#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7,inf=2e9;
int n,c[300005][26],sz[300005],top;
struct Change{
	int x,y,z,sz;
}st[9000005];
vector<int> ind[300005];
void dfs(int x,int dep){
	sz[x]=1,ind[dep].push_back(x);
	for(int i=0;i<26;i++)if(c[x][i])dfs(c[x][i],dep+1),sz[x]+=sz[c[x][i]];
}
int Merge(int x,int y){
	if(!x||!y)return x+y;
	int t=1;
	for(int i=0;i<26;i++){
		st[++top]={x,i,c[x][i],sz[x]};
		c[x][i]=Merge(c[x][i],c[y][i]);
		t+=sz[c[x][i]];
	}
	sz[x]=t;
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		char z[10];
		scanf("%d%d%s",&x,&y,z);
		c[x][z[0]-'a']=y;
	}
	dfs(1,1);
	int mn=0,mnp=0;
	for(int i=1;i<=n;i++){
		int dlt=0;
		for(int j:ind[i]){
			dlt-=sz[j];
			int p=0;
			for(int k=0;k<26;k++)p=Merge(p,c[j][k]);
			dlt+=max(sz[p],1);
			while(top){
				c[st[top].x][st[top].y]=st[top].z;
				sz[st[top].x]=st[top].sz;
				top--;
			}
		}
		if(dlt<mn)mn=dlt,mnp=i;
	}
	if(mn<0)cout<<mn+n<<'\n'<<mnp<<'\n';
	else cout<<n<<'\n'<<1<<'\n';
}