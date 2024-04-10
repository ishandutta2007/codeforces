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
int T,n,a[N],c[N],p[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		c[i]=read();
		a[i]=0;
		p[i]=i;
		for(int j=0;j<c[i];++j){
			a[i]=max(a[i],(int)read()-j+1);				
		}
	}
	int ans=0;
	sort(p+1,p+n+1,[&](int i,int j){return a[i]<a[j];});
	for(int i=1,now=0;i<=n;++i){
		ans=max(ans,a[p[i]]-now);now+=c[p[i]];
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}