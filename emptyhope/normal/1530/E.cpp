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
int n,cnt[28];
string s,t;
inline void pc(int x){
	putchar(x+'a');
}
void work()
{
	cin>>s; n=s.size(); memset(cnt,0,sizeof cnt);
	For(i,0,n-1)cnt[s[i]-'a']++;
	int mx=0,id=-1;
	
	// bd=0 ?
	// 2 letter a bd = 1 
	// aaaxxxxxaa 
	// aaaxxxxxa 
	// aaaxxxxxaaa
	
	For(i,0,25)
		if(cnt[i]==1){
			pc(i),--cnt[i];
			For(j,0,25)
				while(cnt[j]--)pc(j);
			puts("");
			return;
		}
	
	For(i,0,25)
		if(cnt[i]>=2){
			id=i;
			break;
		}
	
	if(cnt[id]-(n-cnt[id])<=2){
		pc(id),pc(id),cnt[id]-=2;
		vector<int>o;
		Rep(i,25,0)
			if(i!=id){
				while(cnt[i]--) o.pb(i);
			}
		while(o.size()){
			pc(o.back()),o.pop_back();
			if(cnt[id])pc(id),--cnt[id];
		}
	}
	else{
	//	puts("TAT");
		int fir=-1;
		vector<int>o;
		For(i,0,25)
			if(cnt[i]&&i!=id){
				if(fir==-1) fir=i;
				else{
					while(cnt[i]--)
						o.pb(i);
				}
			}
		if(o.empty()){
	//		puts("QAQ");
			pc(id),--cnt[id];
			if(fir!=-1)while(cnt[fir]--)pc(fir);
			while(cnt[id]--)pc(id); 
		}else{
			pc(id),--cnt[id];
			pc(fir),--cnt[fir];
			while(cnt[id]--)pc(id);
			reverse(o.begin(),o.end());
			pc(o.back()),o.pop_back();
			while(cnt[fir]--)pc(fir);
			while(o.size())pc(o.back()),o.pop_back();
		}
	}
	
	puts("");
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