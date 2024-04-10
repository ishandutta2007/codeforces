#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,p[200002],O[1002],X[1002],Y[1002],k,ED[2002],bl[200002],P[200002];
ll a[200002],sum[200002],W[2002];
char tg[200002];
vector<int>V[2002];
inline void work(){
	memset(tg,0,sizeof(tg));
	for(re int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i],P[i]=p[i];
	for(re int i=1;i<=k;++i)
		if(O[i]==2)tg[X[i]]=1;
		else if(O[i]==3)tg[P[X[i]]]=tg[P[Y[i]]]=1,swap(P[X[i]],P[Y[i]]);
	re int c=0;
	for(re int i=1;i<=n;++i)
		if(tg[i]){
			re int x=p[i];V[++c].clear(),V[c].push_back(i),W[c]=0,ED[c]=i,bl[i]=c;
			while(!tg[x])V[c].push_back(x),ED[c]=x,x=p[x];
			sort(V[c].begin(),V[c].end());
		}
	for(re int i=1;i<=k;++i)
		if(O[i]==1){
			re ll tmp=sum[Y[i]]-sum[X[i]-1];
			for(re int j=1;j<=c;++j)
				if(W[j]){
					re int r=lower_bound(V[j].begin(),V[j].end(),Y[i]+1)-V[j].begin(),l=lower_bound(V[j].begin(),V[j].end(),X[i])-V[j].begin();
					tmp+=W[j]*(r-l);
				}
			printf("%lld\n",tmp);
		}
		else if(O[i]==2){
			W[bl[X[i]]]+=Y[i];
			re int x=p[ED[bl[X[i]]]];
			while(x^X[i])W[bl[x]]+=Y[i],x=p[ED[bl[x]]];
		}
		else swap(p[X[i]],p[Y[i]]);
	for(re int i=1;i<=c;++i)for(auto z:V[i])a[z]+=W[i];
	k=0;
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i)p[i]=read();
	m=read();
	while(m--){
		O[++k]=read(),X[k]=read(),Y[k]=read();
		if(k>=1000)work();
	}if(k)work();
}