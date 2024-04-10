#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
constexpr int N=2e5+5,B=414;
int n,k,q,ans,flag,sz,a[N],b[N],bel[N],tag[N],L[N],c[N],pre[N],num[1000][16384];
inline void rd(int &x){
    x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-f;
    do x=x*10+(48^c);while(isdigit(c=getchar()));x*=f;
}
inline void upd1(int p,int v){
	if(!v)return;
	for(int i=p;i<=n;i+=k){
		pre[i]^=v;
		if(!pre[i])--ans;
		if(pre[i]==v)++ans;
	}
	int lst=p%k+(n-p%k)/k*k;
	if(!pre[lst])--flag;
	if(pre[lst]==v)++flag;
}
inline void upd2(int p,int v){
	if(!v)return;
	for(int i=p;bel[i]==bel[p];i+=k){
		if(pre[i]==tag[bel[p]])++ans;
		num[bel[p]][pre[i]]--;
		num[bel[p]][pre[i]^=v]++;
		if(pre[i]==tag[bel[p]])--ans;
	}
	for(int i=bel[p]+1;i<=sz&&L[i]%k==p%k;++i)
		ans+=num[i][tag[i]],ans-=num[i][tag[i]^=v];
	int lst=p%k+(n-p%k)/k*k;
	if(pre[lst]==tag[bel[lst]])--flag;
	if(!(pre[lst]^tag[bel[lst]]^v))++flag;
}
inline void update(int p,int v){
	n/k<B?upd1(p,v^c[p]):upd2(p,v^c[p]);c[p]=v;
}
int main(){
	rd(n),rd(k),rd(q);
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rd(b[i]);++n;
	if(n/k>=B)
		rep(i,1,k)rep(j,0,(n-i)/k){
			if(j%B==0)L[++sz]=i+j*k,num[sz][0]=min(B,(n-i)/k-j+1);
			bel[i+j*k]=sz;
		}
	rep(i,1,n)update(i,a[i]^a[i-1]^b[i]^b[i-1]);
	printf("%d\n",flag?-1:ans);
	while(q--){
		char ch;int p,v;
		cin>>ch;rd(p),rd(v);
		ch=='a'?a[p]=v:b[p]=v;
		update(p,a[p]^a[p-1]^b[p]^b[p-1]);
		if(p^n)update(p+1,a[p+1]^a[p]^b[p+1]^b[p]);
		printf("%d\n",flag?-1:ans);
	}
	return 0;
}