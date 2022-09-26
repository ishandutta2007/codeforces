#include<bits/stdc++.h>
using namespace std;
#define N 100010
const int mx=1e5+1;
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
int n,m,a[N*10];
int len,blocks,ans[N*5];
struct Query{
	int opt;
	int l,r,x;
}q[N*5];
int f[N],s[N];
inline int getf(int x){
	return f[x]==x?x:f[x]=getf(f[x]);
}
int bin[N],top;
inline void Merge(int x,int y){
	s[x]+=s[y],s[y]=0;
	f[y]=x;
	bin[++top]=y;
}
void Clear(){
	while(top){
		f[bin[top]]=bin[top];
		--top;
	}
}
void Solve(int L,int R){
	int l=0,r=0;
	for(int i=L;i<=R;++i)r=max(r,a[i]);
	for(int i=1;i<=r;++i){
		f[i]=i,s[i]=0;	
	}
	for(int i=L;i<=R;++i){
		++s[a[i]];
	}
	top=0;
	auto rebuild = [&]() -> void{
		for(int i=L;i<=R;++i){
			s[a[i]=getf(a[i])]=0;
			a[i]-=l;
		}
	};
	for(int i=1;i<=m;++i){
		int ql=q[i].l,qr=q[i].r;
		if(ql>R||qr<L)continue;
		if(q[i].opt==1){
			int x=q[i].x;
			if(x+l>=r)continue;
			if(ql<=L&&qr>=R){
				if(2*x>r-l){
					for(int j=x+l+1;j<=r;++j)Merge(j-x,j);
					r-=r-(x+l);
				}
				else{
					for(int j=l+1;j<=x+l;++j)Merge(j+x,j);
					l+=x;
				}
			}
			else{
				rebuild();
				for(int j=max(L,ql);j<=min(R,qr);++j)a[j]=(a[j]>x?a[j]-x:a[j]);
				Clear();
				l=r=0;
				for(int j=L;j<=R;++j)r=max(r,a[j]);
				for(int j=L;j<=R;++j){
					++s[a[j]];
				}
			}
		}
		else{
			int x=q[i].x;
			if(x+l>r)continue;
			if(ql<=L&&qr>=R){
				ans[i]+=s[x+l];
			}
			else{
				rebuild();
				for(int j=max(L,ql);j<=min(R,qr);++j)ans[i]+=a[j]==x;
				Clear();
				l=r=0;
				for(int j=L;j<=R;++j)r=max(r,a[j]);
				for(int j=L;j<=R;++j){
					++s[a[j]];
				}
			}
		}
	}	
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=m;++i){
		q[i].opt=read();
		q[i].l=read(),q[i].r=read(),q[i].x=read();
	}
	len=ceil(sqrt(n));
	blocks=n/len;
	if(n%len)++blocks;
	for(int i=1;i<=blocks;++i){
		Solve((i-1)*len+1,min(n,i*len));
	}
	for(int i=1;i<=m;++i){
		if(q[i].opt==2)printf("%d\n",ans[i]);
	}
	return 0;
}