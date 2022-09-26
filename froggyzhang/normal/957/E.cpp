#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 200010
inline int read(){
	int x=0,f=1;
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
int n,m,len,t[N];
struct frac{
	ll a,b;
	bool operator <(const frac y)const{
		return a*y.b<b*y.a;
	}
	bool operator ==(const frac y)const{
		return a*y.b==b*y.a;
	}
};
frac l[N],r[N],b[N];
struct Range{
	int l,r,t;
	bool operator <(const Range b)const{
		return r==b.r?l>b.l:r<b.r;
	}
}a[N];
struct BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void Add(int x,int d){
		while(x<=len){
			b[x]+=d;
			x+=lowbit(x);
		}
	}
	inline int Ask(int x){
		int ans=0;
		while(x){
			ans+=b[x];
			x-=lowbit(x);
		}
		return ans;
	}
}B[2];
ll ans;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		int x=read(),v=read();
		t[i]=(x>0);
		x=abs(x),v=abs(v);
		l[i]={x,v+m};
		r[i]={x,v-m};
		if(r[i]<l[i])swap(l[i],r[i]);
		b[++len]=l[i],b[++len]=r[i];
	}
	sort(b+1,b+len+1);
	len=unique(b+1,b+len+1)-b-1;
	for(int i=1;i<=n;++i){
		a[i].l=lower_bound(b+1,b+len+1,l[i])-b;
		a[i].r=lower_bound(b+1,b+len+1,r[i])-b;
		a[i].t=t[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int p=a[i].t;
		ans+=i-1-B[p].Ask(a[i].l-1);
		B[p].Add(a[i].l,1);
		B[p^1].Add(a[i].r,1);
	}
	printf("%lld\n",ans);
	return 0;
}