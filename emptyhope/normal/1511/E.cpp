#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
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
#define maxn 300005
modint f[maxn][2],p[maxn][2],inv2=((mod+1)/2);
int n,m;
string s[maxn];
signed main()
{
//	int n=read();
	f[1][0]=0,f[1][1]=0;
	p[1][0]=p[1][1]=inv2;
//	cout<<(inv2*inv2).x<<endl;
	For(i,2,300000){
		f[i][0]+=inv2*(f[i-1][0]+f[i-1][1]);
		f[i][0]+=inv2*(f[i-1][1]+p[i-1][1]);
		f[i][1]+=inv2*f[i-1][0];
		p[i][0]=p[i-1][0]*inv2+p[i-1][1];
		p[i][1]=1-p[i][0];
	//	modint pw=(modint(2)^i);
	//	cout<<p[i][0].x<<" "<<p[i][1].x<<endl;
	//	cout<<i<<" "<<(f[i][0]*pw).x<<" "<<(f[i][1]*pw).x<<endl;
	}
//	modint ans=(f[2][0]+f[2][1])*(modint(2)^2);
//	cout<<ans.x;
	n=read(),m=read();
	For(i,0,n-1)cin>>s[i];
	modint res=0;
	int cnt=0;
	For(i,0,n-1){
		int l=0;
		For(j,0,m-1){
			if(s[i][j]=='*'){
				if(l) res+=(f[l][0]+f[l][1]);
				l=0;
			}
			else ++l,++cnt;
		}
		if(l) res+=(f[l][0]+f[l][1]);
	}
	For(j,0,m-1){
		int l=0;
		For(i,0,n-1){
			if(s[i][j]=='*'){
				if(l) res+=f[l][0]+f[l][1];
				l=0;
			}else ++l;
		}
		if(l)res+=f[l][0]+f[l][1];
	}
	res*=(modint(2)^cnt);
	cout<<res.x; 
	return 0;
}