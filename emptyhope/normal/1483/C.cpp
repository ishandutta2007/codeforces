#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;
#define maxn 300005
#define inf 0x3f3f3f3f

int n,m;
int h[maxn],b[maxn];
int f[maxn];
int st[maxn],top;

int tag[maxn<<2],val[maxn<<2];
inline void up(int p){
	val[p]=max(val[p<<1],val[p<<1|1]);
}
inline void pt(int p,int v){
	val[p]+=v;
	tag[p]+=v;
}
inline void pd(int p){
	if(tag[p]) pt(p<<1,tag[p]),pt(p<<1|1,tag[p]),tag[p]=0;
}
inline void mdf(int p,int l,int r,int nl,int nr,int v){
	if(l>=nl&&r<=nr)return pt(p,v);
	int mid=l+r>>1; pd(p);
	if(nl<=mid)mdf(p<<1,l,mid,nl,nr,v);
	if(nr>mid)mdf(p<<1|1,mid+1,r,nl,nr,v);
	up(p);
}
inline int ask(int p,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return val[p];
	int mid=l+r>>1,res=-inf; pd(p);
	if(ql<=mid)res=max(res,ask(p<<1,l,mid,ql,qr));
	if(qr>mid)res=max(res,ask(p<<1|1,mid+1,r,ql,qr));
	return res;
}

signed main()
{
	n=read();
	For(i,1,n)h[i]=read();
	For(i,1,n)b[i]=read();
	if(n==1){
		cout<<b[1];
		return 0;
	}
	
	st[top=1]=1;
	f[1]=b[1];
	mdf(1,1,n,2,2,f[1]);
	mdf(1,1,n,1,1,b[1]);
	For(i,2,n){
		while(top && h[st[top]]>h[i]) {
			int L=st[top-1]+1;
		//	cout<<"L,R "<<L<<' '<<st[top]<<endl;
			mdf(1,1,n,L,st[top],-b[st[top]]);
			--top;
		}
		mdf(1,1,n,st[top]+1,i,b[i]);
		f[i]=ask(1,1,n,1,i);
		if(i+1<=n)mdf(1,1,n,i+1,i+1,f[i]);
		st[++top]=i;
//		cout<<i<<' '<<f[i]<<endl;
	}
	cout<<f[n];
    return 0;
}