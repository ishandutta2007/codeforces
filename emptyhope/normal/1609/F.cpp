#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define ll long long
using namespace std;
inline ll read()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define mod 998244353
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
vector<modint> fac,ifac,iv;
inline void initC(int n)
{
    if(iv.empty())fac=ifac=iv=vector<modint>(2,1);
    int m=iv.size(); ++n;
    if(m>=n)return;
    iv.resize(n),fac.resize(n),ifac.resize(n);
    For(i,m,n-1){
        iv[i]=iv[mod%i]*(mod-mod/i);
        fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*iv[i];
    }
}
inline modint C(int n,int m){
    if(m<0||n<m)return 0;
    return initC(n),fac[n]*ifac[m]*ifac[n-m];
}
inline modint sign(int n){return (n&1)?(mod-1):(1);}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 1000005
#define inf 0x3f3f3f3f

ll n,res,a[maxn];int cnt[maxn];
inline int popcnt(ll x){
	int res=0;
	while(x)res++,x^=x&-x;
	return res;
}

int mn[maxn],mx[maxn];
int cntmn[64][2],cntmx[64][2];
int ok[maxn];
void solve(int l,int r)
{
	if(l==r)return void(); 
	int mid=l+r>>1;
	solve(l,mid),solve(mid+1,r);
	
	mn[mid]=mid;
	int now=mid;
	Rep(i,mid-1,l){
		if(a[i]<a[now]) now=i;
		mn[i]=now;
	}
	mx[mid]=mid;
	now=mid;
	Rep(i,mid-1,l){
		if(a[i]>a[now]) now=i;
		mx[i]=now;
	}
	
	now=mid+1;
	mn[mid+1]=mid+1;
	
	For(i,mid+2,r){
		if(a[i]<a[now]) now=i;
		mn[i]=now;
	}
	mx[mid+1]=mid+1;
	now=mid+1;
	For(i,mid+2,r){
		if(a[i]>a[now]) now=i;
		mx[i]=now;
	}
	ok[mid+1]=1,ok[mid]=0;
	For(i,mid+2,r)
		ok[i]=ok[i-1]+(cnt[mx[i]]==cnt[mn[i]]);
	
	int j=mid,k=mid;
	memset(cntmn,0,sizeof cntmn);
	memset(cntmx,0,sizeof cntmx);
	Rep(i,mid,l){
		while(j<r && a[mn[j+1]]>a[mn[i]]) {
			++j;
			cntmn[cnt[mn[j]]][0]++;
			cntmx[cnt[mx[j]]][0]++;
		}
		while(k<r && a[mx[k+1]]<a[mx[i]]) {
			++k;
			cntmn[cnt[mn[k]]][1]++;
			cntmx[cnt[mx[k]]][1]++;
		}
		int w1=min(j,k),w2=max(j,k);
//		if(l==1 && r==2){
//			cout<<i<<' '<<w1<<" "<<w2<<endl;
//		}
		if(w1>mid)
			res+=1ll*(w1-mid)*(cnt[mn[i]]==cnt[mx[i]]);///cout<<"add1 "<<(w1-mid)*(cnt[mn[i]]==cnt[mx[i]])<<endl;
		if(j>w1){
			int nd=cnt[mn[i]];
//			if(l==1&&r==2) cout<<"nd: "<<nd<<" "<<cntmx[j][nd]<<" "<<cntmx[w1][nd]<<endl;
			res+=cntmx[nd][0]-cntmx[nd][1];
//			cout<<"add2 "<<cntmx[j][nd]-cntmx[w1][nd]<<endl;
		}
		if(k>w1){
			int nd=cnt[mx[i]];
			res+=cntmn[nd][1]-cntmn[nd][0];
//			cout<<"add3 "<<cntmn[k][nd]-cntmn[w1][nd]<<endl;
		}
		res+=(ok[r]-ok[w2]);
//		cout<<"add4 "<<ok[r]-ok[w2]<<endl;
	}
//	cout<<"res: "<<l<<' '<<r<<" "<<res-lstres<<endl;
}

signed main()
{
	n=read();
	For(i,1,n)a[i]=read(),cnt[i]=popcnt(a[i]);
	solve(1,n);
	cout<<res+n;
	return 0;
}