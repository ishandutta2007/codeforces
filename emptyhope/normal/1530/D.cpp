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

#define maxn 200005 
#define inf 0x3f3f3f3f
int n,a[maxn],b[maxn],pos[maxn];
set<int>s;
bool OK(){
	For(i,1,n)
		if(a[i]==b[i])return 0;
	return 1;
}
void work()
{
	vector<int>o; 
	n=read();s.clear();
	For(i,1,n)pos[i]=b[i]=a[i]=0;
	For(i,1,n){
		a[i]=read();
		if(!s.count(a[i]))b[i]=a[i],pos[b[i]]=i,s.insert(a[i]);
		else o.pb(i);
	}
	cout<<s.size()<<endl;
	
	vector<int>vec,v;
	For(i,1,n)if(!s.count(i))vec.pb(i);
	for(int i=0;i<o.size();++i) {
	//	cout<<"o,vec "<<o[i]<<" "<<vec[i]<<endl;
		b[o[i]]=vec[i];
		if(o[i]==vec[i]) v.pb(o[i]);
	}
	
	if(v.size()==1){
		int p=pos[a[v[0]]];
		swap(b[v[0]],b[p]);
	}else if(v.size()>=2){
		for(int i=0;i<v.size();++i)
			b[v[i]]=v[(i+1)%v.size()];
	}
	
	For(i,1,n) cout<<b[i]<<" "; puts(""); 
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}
/*
5
0 0 0 0 0
100 100 100 100 100
*/