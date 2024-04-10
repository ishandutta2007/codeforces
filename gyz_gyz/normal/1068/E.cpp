#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 200000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,k,x,y,hm,rt,f[N],d[N];
vector<int>p[N];
void dfs0(int x,int h){d[h]=x;
	if(p[x].size()==1){
		if(h&1){
			printf("No\n");exit(0);
		}
		if(h>hm)hm=h,rt=d[hm/2];
	}
	for(auto i:p[x])if(f[x]!=i){
		f[i]=x;dfs0(i,h+1);
	}
}
void dfs(int x,int h){
	if(p[x].size()-(x!=rt)<3&&((p[x].size()-(x!=rt))||h!=k)){
		printf("No\n");exit(0);
	}
	for(auto i:p[x])if(f[x]!=i){
		f[i]=x;dfs(i,h+1);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	rep(i,1,n)if(p[i].size()==1){x=i;break;}
	hm=-1;dfs0(x,0);
	if(hm!=k*2){
		printf("No\n");return 0;
	}
	rep(i,1,n)f[i]=0;dfs(rt,0);
	printf("Yes\n");
}