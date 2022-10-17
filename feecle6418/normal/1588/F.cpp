#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ub(a,b) upper_bound(pos[a].begin(),pos[a].end(),b)
int in[N],p[N];
int op[N],x[N],y[N],id[N];
long long a[N],sum[N],val[N];
vector<int>pos[N];
int main() {
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d%d%d",op+i,x+i,y+i);
	int B=500;//sqrt(n/log2(n+1))+1;
	for(int T=1;T<=q;T+=B) {
		int l=T,r=min(q,T+B-1);
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i];
		memset(in,0,sizeof(in));
		memset(val,0,sizeof(val));
		for(int i=l;i<=r;i++) {
			if(op[i]!=1)in[x[i]]=x[i];
			if(op[i]==3)in[y[i]]=y[i];
		}
		for(int i=1;i<=n;i++)
			pos[i].clear();
		int top=0;
		for(int i=1;i<=n;i++) {
			if(in[i]==i)id[++top]=i;
			if(in[i])continue;
			int now=p[i],c;
			while(now!=i&&!in[now])now=p[now];
			c=in[now];
			if(now==i)c=-1;
			now=p[i];
			in[i]=c;
			while(now!=i&&!in[now])in[now]=c,now=p[now];
		}
		for(int i=1;i<=n;i++)
			if(in[i]>0)pos[in[i]].push_back(i);
		for(int i=l;i<=r;i++) {
			if(op[i]==1) {
				long long Sum=sum[y[i]]-sum[x[i]-1];
				for(int j=1;j<=top;j++)
					Sum+=val[id[j]]*(ub(id[j],y[i])-ub(id[j],x[i]-1));
				printf("%lld\n",Sum);
			} else if(op[i]==2) {
				int now=in[x[i]];
				do {
					val[now]+=y[i];
					now=in[p[now]];
				}while(now!=in[x[i]]);
			} else swap(p[x[i]],p[y[i]]);
		}
		for(int i=1;i<=n;i++)
			if(in[i]>0)a[i]+=val[in[i]];
	}
	return 0;
}