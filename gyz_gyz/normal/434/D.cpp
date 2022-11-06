#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back
#define N 2000010
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int tot,t[N],p[N],nt[N];ll ans,w[N];
void init(int n){
	ans=0;tot=0;rep(i,1,n)t[i]=-1;
}
void lk(int x,int y,ll z){
	nt[tot]=t[x];p[tot]=y;w[tot]=z;t[x]=tot++;
	nt[tot]=t[y];p[tot]=x;w[tot]=0;t[y]=tot++;
}
int dl[N],h[N],cur[N];
ll dfs(int n,int x,ll y){
	if(x==n)return y;ll t0=y;
	for(;~cur[x];cur[x]=nt[cur[x]])if(w[cur[x]]&&h[p[cur[x]]]>h[x]){
		ll z=dfs(n,p[cur[x]],min(w[cur[x]],y));
		w[cur[x]]-=z;w[cur[x]^1]+=z;y-=z;if(!y)break;
	}return t0-y;
}
void dinic(int n){
	for(;;){
		rep(i,1,n)h[i]=0,cur[i]=t[i];
		int s=1,ta=1;dl[1]=h[1]=1;
		for(;s<=ta;s++)for(int i=t[dl[s]];~i;i=nt[i])if(w[i]&&!h[p[i]]){
			h[p[i]]=h[dl[s]]+1;dl[++ta]=p[i];
		}
		if(!h[n])return;
		ans+=dfs(n,1,Inf);
	}
}
int n,m,A[N],B[N],C[N];
int main(){
	scanf("%d%d",&n,&m);init(n*201+2);
	rep(i,1,n)scanf("%d%d%d",&A[i],&B[i],&C[i]);
	rep(i,1,n){int l,r;
		scanf("%d%d",&l,&r);
		rep(j,-100,100)lk(j==-100?1:(i-1)*201+j+101,(i-1)*201+j+102,
		j<l||j>r?Inf:200000-(A[i]*j*j+B[i]*j+C[i]));
		lk(i*201+1,n*201+2,Inf);
	}
	rep(i,1,m){int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		rep(j,-300,100)if(j-z>=-100){
			if(j>=-100){
				if(j-z>100)lk((x-1)*201+j+102,n*201+2,Inf);
				else lk((x-1)*201+j+102,(y-1)*201+j-z+102,Inf);
			}else if(j-z<=100)lk(1,(y-1)*201+j-z+102,Inf);
		}
	}
	dinic(n*201+2);
	printf("%lld\n",200000*n-ans);
}