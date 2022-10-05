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

#define maxn 200005
#define inf 0x3f3f3f3f

int n,m,B;
int x[maxn],y[maxn],now[maxn];
int tmp[555][555];

int bel[maxn],L[666],R[666],mx;
int sblk[666],tr[maxn];
inline void add(int x,int y){
	int bx=bel[x];
	sblk[bx]+=y,tr[x]+=y;
}
inline int ask(int x){
	int res=0;
	For(i,1,bel[x]-1) res+=sblk[i];
	For(i,L[bel[x]],x) res+=tr[i];
	return res;
}

signed main()
{
	n=read(),m=read();
	B=sqrt(200000);
	For(i,1,200000) bel[i]=(i-1)/B+1;
	For(i,1,bel[200000]) L[i]=(i-1)*B+1,R[i]=min(200000,i*B);
	mx=bel[200000];
	
	For(i,1,n){
		x[i]=read(),y[i]=read();
		now[i]=-1;
	}
	int sums=0,tmpres=0;
	For(i,1,m)
	{
		int op=read(),k=read();
		if(op==1){
			// add
			++sums;
			now[k]=i;
			// ( time - now[k] ) % x+y  <  x
			if(x[k]+y[k]>B){
				for(int j=i;j<=m;j+=(x[k]+y[k])){
					add(j,1);
					if(j+x[k]<=m)add(j+x[k],-1);
					//cout<<"add del "<<j<<" "<<j+x[k]<<endl;
				}
			}else{
				For(d,0,x[k]-1)
					tmp[x[k]+y[k]][(now[k]+d)%(x[k]+y[k])]++;
			}
		}else{
			--sums;
			if(x[k]+y[k]>B){
				for(int j=now[k];j<=m;j+=(x[k]+y[k])){
					add(j,-1);
					if(j+x[k]<=m)add(j+x[k],1);
				}
			}else{
				For(d,0,x[k]-1)
					tmp[x[k]+y[k]][(now[k]+d)%(x[k]+y[k])]--;
			}
			now[k]=-1;
		}
		int res=ask(i);
		For(j,2,B){
			res+=tmp[j][i%j];
		//	if(tmp[j][i%j])cout<<j<<' '<<i%j<<" "<<tmp[j][i%j]<<endl;
		}
		printf("%d\n",sums-res);
	}
	return 0;
}