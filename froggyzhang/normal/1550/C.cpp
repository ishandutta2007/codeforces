#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,L1[N],L2[N],a[N],st1[N],st2[N],top1,top2;
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		L1[i]=L2[i]=0;
	}
	top1=top2=0;
	for(int i=1;i<=n;++i){
		while(top1&&a[st1[top1]]>a[i])--top1;
		while(top2&&a[st2[top2]]<a[i])--top2;
		L1[i]=st1[top1];
		L2[i]=st2[top2];
		st1[++top1]=i;
		st2[++top2]=i;
	}
	ll ans=0;
	top1=top2=0;
	for(int r=1,l=1;r<=n;++r){
		while(top1&&a[st1[top1]]<=a[r]){
			while(l<=L1[st1[top1]])++l;
			--top1;
		}
		while(top2&&a[st2[top2]]>=a[r]){
			while(l<=L2[st2[top2]])++l;
			--top2;
		}
		st1[++top1]=r;
		st2[++top2]=r;
		ans+=r-l+1;
	}
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}