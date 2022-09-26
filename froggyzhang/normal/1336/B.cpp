#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,na,nb,nc;
ll a[N],b[N],c[N];
inline ll calc(ll x,ll y,ll z){
	return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}
int main(){
	T=read();
	while(T--){
		na=read(),nb=read(),nc=read();
		for(int i=1;i<=na;++i)a[i]=read();
		for(int i=1;i<=nb;++i)b[i]=read();
		for(int i=1;i<=nc;++i)c[i]=read();
		sort(a+1,a+na+1);
		sort(b+1,b+nb+1);
		sort(c+1,c+nc+1);
		ll ans=5e18;
		for(int i=1;i<=na;++i){
			int l=lower_bound(b+1,b+nb+1,a[i])-b;
			int r=upper_bound(c+1,c+nc+1,a[i])-c-1;
			if(l>=1&&r>=1&&l<=nb&&r<=nc)ans=min(ans,calc(a[i],b[l],c[r]));
			l=lower_bound(c+1,c+nc+1,a[i])-c;
			r=upper_bound(b+1,b+nb+1,a[i])-b-1;
			if(l>=1&&r>=1&&l<=nc&&r<=nb)ans=min(ans,calc(a[i],c[l],b[r]));
		}
		for(int i=1;i<=nb;++i){
			int l=lower_bound(a+1,a+na+1,b[i])-a;
			int r=upper_bound(c+1,c+nc+1,b[i])-c-1;
			if(l>=1&&r>=1&&l<=na&&r<=nc)ans=min(ans,calc(b[i],a[l],c[r]));
			l=lower_bound(c+1,c+nc+1,b[i])-c;
			r=upper_bound(a+1,a+na+1,b[i])-a-1;
			if(l>=1&&r>=1&&l<=nc&&r<=na)ans=min(ans,calc(b[i],c[l],a[r]));
		}
		for(int i=1;i<=nc;++i){
			int l=lower_bound(a+1,a+na+1,c[i])-a;
			int r=upper_bound(b+1,b+nb+1,c[i])-b-1;
			if(l>=1&&r>=1&&l<=na&&r<=nb)ans=min(ans,calc(c[i],a[l],b[r]));
			l=lower_bound(b+1,b+nb+1,c[i])-b;
			r=upper_bound(a+1,a+na+1,c[i])-a-1;
			if(l>=1&&r>=1&&l<=nb&&r<=na)ans=min(ans,calc(c[i],b[l],a[r]));
		}
		printf("%I64d\n",ans);
	}
	return 0;
}