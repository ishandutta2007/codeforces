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

int mod;
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

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f
int n;
modint f[405][405][3];
inline void print(int i,int j,int x,int y){
//	cout<<"-> "<<(i)<<' '<<(j)<<' '<<x<<' '<<y<<endl;
}
signed main()
{
//	freopen("my","w",stdout);
	n=read(),mod=read();
	f[0][0][0]=1;
	For(i,0,n-1){
		For(j,0,i)For(x,0,2)if(f[i][j][x].x){
		//	cout<<i<<' '<<j<<" "<<x<<" "<<y<<' '<<z<<" "<<f[i][j][x][y][z].x<<endl; 
			// new:
			modint val=f[i][j][x];
			if(j+1-x>0)
				f[i+1][j+1][x]+=val*(j+1-x);
			if(2-x>0){
				f[i+1][j+1][x+1]+=val*(2-x);
				if(j) f[i+1][j][x+1]+=val*(2-x);
				if(j) f[i+2][j][x+1]+=val*(2-x);
			}
			
			// close: (2)
			if(j){
				int tmp=2*j-x;
				if(tmp>0){
					f[i+1][j][x]+=val*tmp;
					f[i+2][j][x]+=val*tmp;
				}
			}
			if(j>1){
				f[i+2][j-1][x]+=val*(j-1)*2;
				f[i+3][j-1][x]+=val*(j-1);
			}
		}
	}
	cout<<f[n][1][2].x;
//  5,1,2,0
	return 0;
}
/*
i   
j 
k  k=[0,2] 

5 1000000007

*/