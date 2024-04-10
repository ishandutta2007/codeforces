#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct node{
	int u,v,w;
}path[300001];
bool cmp(node A,node B){return A.w<B.w;}
int ans,dp[300001]/*best*/,olddp[300001]/*second better*/,bestpath[300001]/*the best way to point i*/,u[300001],v[300001],w[300001];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	rb(i,1,m){
		scanf("%d %d %d",&path[i].u,&path[i].v,&path[i].w);
	}
	sort(path+1,path+1+m,cmp);
	rb(i,1,m){
		u[i]=path[i].u;
		v[i]=path[i].v;
		w[i]=path[i].w;
	}
	rb(i,1,m){
		int nowval;
		if(bestpath[u[i]]==path[i].w){
			nowval=olddp[u[i]]+1;
		}
		else{
			nowval=dp[u[i]]+1;
		}
		if(nowval>dp[v[i]]){
			if(w[i]!=bestpath[v[i]]){
				olddp[v[i]]=dp[v[i]];
			}
			dp[v[i]]=nowval;
			bestpath[v[i]]=w[i];
		}
		ans=max(nowval,ans);
	}
	printf("%d\n",ans);
	return 0;
}