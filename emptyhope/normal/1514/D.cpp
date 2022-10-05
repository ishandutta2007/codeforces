#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
//#define int long long
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

#define mod 1000000007
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
};

#define maxn 300005
#define inf 0x3f3f3f3f
int n,m,a[maxn];

struct node{
	int val,hp;
};
node dat[maxn<<2];
node merge(node a,node b){
	if(a.val==b.val) return (node){a.val,a.hp+b.hp};
	if(a.hp>b.hp) return (node){a.val,a.hp-b.hp};
	swap(a,b); return (node){a.val,a.hp-b.hp};
}
inline void up(int p){
	dat[p]=merge(dat[p<<1],dat[p<<1|1]);
}
void build(int p,int l,int r){
	if(l==r)return dat[p]=(node){a[l],1},void();
	int mid=l+r>>1; build(p<<1,l,mid),build(p<<1|1,mid+1,r),up(p);
}
node res;
void ask(int p,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr){
		if(res.val) res=merge(res,dat[p]);
		else res=dat[p];
		return;
	}int mid=l+r>>1;
	if(ql<=mid)ask(p<<1,l,mid,ql,qr);
	if(qr>mid)ask(p<<1|1,mid+1,r,ql,qr);
}

vector<pii>Q[maxn];
int cnt[maxn],ans[maxn],len[maxn];

signed main()
{
	n=read(),m=read();
	For(i,1,n)a[i]=read(); build(1,1,n);
	For(_,1,m)
	{
		int l=read(),r=read(); len[_]=r-l+1; 
		res=(node){0,0};
		ask(1,1,n,l,r);
		Q[r].pb(mkp(res.val,_));
		if(l>1) Q[l-1].pb(mkp(res.val,-_));
	}
	For(i,1,n){
		++cnt[a[i]];
		for(auto t:Q[i]) {
			if(t.se>0) ans[t.se]+=cnt[t.fi];
			else ans[-t.se]-=cnt[t.fi];
		}
	}
	For(i,1,m)
	{
		if(ans[i]<=(len[i]+1)/2){
			puts("1");
			continue;
		}
		cout<<ans[i]-(len[i]-ans[i])<<endl;
	}
	return 0;
}