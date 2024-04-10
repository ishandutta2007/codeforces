#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+100,maxn=2e6;
int a[N],b[N],fa[N],g[N],h[N];

bool cmp(int n1,int n2) {return (b[n1]<b[n2]);}

set<ll> S;
set<ll>::iterator iter1,iter2;

int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}

int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i],h[i]=i;
	sort(h+1,h+n,cmp);
	
	for(int i=0;i<=maxn;i++) S.insert((ll)i*i);
	
	for(int i=1;i<=n;i++) fa[i]=g[i]=i;
	
	int id=1;
	for(int i=1;i<=maxn-1;i++){
		while(id<=n-1&&b[h[id]]<=i){
			int t1=Find(h[id]),t2=Find(h[id]+1);
			fa[t2]=t1;g[t1]=g[t2];
			id++;
		}
		ll st=(ll)i*i,Max=0,LL=0,RR=1e18;
		for(int j=1;j<=n;j=g[j]+1){
			ll t=a[j]-a[1]+st,tt=a[g[j]]-a[1]+st;
			iter1=iter2=S.lower_bound(t+1);
			ll t1=(*iter1);
			iter1--;ll t2=(*iter1);
			iter2++;ll t3=(*iter2);
			ll L,R;
			if(t-t2<t1-t){
				L=0,R=(t1+t2)/2-tt;
			}
			else{
				L=t1-t,R=(t1+t3)/2-tt;
			}
			if(LL<L) LL=L;
			if(RR>R) RR=R;
		}
		
		if(LL<a[1]-st) LL=a[1]-st;
		
		if(LL<=RR){
			printf("%lld\n",LL+st-a[1]);
			return 0;
		}
	}
	
	return 0;
}