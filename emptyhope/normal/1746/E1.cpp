// what is matter? never mind.
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

// modint
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
	friend modint operator +(modint a,modint b){return a+=b;}
	friend modint operator -(modint a,modint b){return a-=b;}
	friend modint operator *(modint a,modint b){return a*=b;}
	friend modint operator /(modint a,modint b){return a/=b;}
	friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
	bool operator <(const modint&b)const{return x<b.x;}
};
inline modint qpow(modint x,int y){return x^y;}

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

#define maxn 300005
#define inf 0x3f3f3f3f

int n;

int get(){
	string s;
	cin>>s;
	return s[0]=='Y';
}


signed main()
{
	cin>>n;
	vi o;
	For(i,1,n)o.pb(i);
	while(o.size()>2){
		if(o.size()==3){
				int len=o.size();
		int mid1=len/3;
		int mid2=(len-mid1)/2+mid1;
		cout<<"? "<<" "<<mid1<<" ";
		For(i,1,mid1)cout<<o[i-1]<<" ";
		cout<<endl;
		int x=get();
		cout<<"? "<<" "<<mid2<<" ";
		For(i,1,mid2)cout<<o[i-1]<<" ";
		cout<<endl;
		int y=get();
		vi oo;
		if(x&&y){
			For(i,1,mid2)oo.pb(o[i-1]);
			o=oo;continue;
		}
		if(!x&&!y){
			For(i,mid1+1,len)oo.pb(o[i-1]);
			o=oo;continue;
		}
		if(x&&!y){
			For(i,1,mid1)oo.pb(o[i-1]);
			For(i,mid2+1,len)oo.pb(o[i-1]);
			o=oo;continue;
		}
		cout<<"? "<<len-mid2<<" ";
		For(i,mid2+1,len)cout<<o[i-1]<<" ";cout<<endl;
		int z=get();
		if(!z){
			For(i,1,mid2)oo.pb(o[i-1]);
			o=oo;continue;
		}
		cout<<"? "<<mid1<<" ";
		For(i,1,mid1)cout<<o[i-1]<<" ";cout<<endl;
		int zz=get();
		if(!zz){
			For(i,mid1+1,len)oo.pb(o[i-1]);
			o=oo;continue;
		}else{
			For(i,1,mid1)oo.pb(o[i-1]);
			For(i,mid2+1,len)oo.pb(o[i-1]);
			o=oo;continue;
		}
			break;
		}
		int len=o.size();
		int mid2=len/2;
		int mid1=mid2/2;
		int mid3=mid2+mid1;
		cout<<"? "<<mid2<<" ";
		For(i,1,mid2)cout<<o[i-1]<<" ";cout<<endl;
		int x=get();
		cout<<"? "<<mid2<<" ";
		For(i,mid1+1,mid2+mid1)cout<<o[i-1]<<" ";cout<<endl;
		int y=get();
		
		if(x==1 && y==0){
			vi oo;
			For(i,1,len)if(i<=mid2 || i>mid3) oo.pb(o[i-1]);
			o=oo;
			continue;
		}
		if(x==0 && y==1){
			vi oo;
			For(i,1,len)if(i>mid1)oo.pb(o[i-1]);
			o=oo;
			continue;
		}
		if(x==0 && y==0){
			vi oo;
			For(i,1,len)if(i<=mid1 || i>mid2)oo.pb(o[i-1]);
			o=oo;
			continue;
		}
		if(x==1 && y==1){
			vi oo;
			For(i,1,len)if(i<=mid3)oo.pb(o[i-1]);
			o=oo;
			continue;
		}
	}
	for(auto x:o){
		cout<<"! "<<x<<endl;
		string s;cin>>s;
		if(s==":)")break;
	}
	return 0;
}

/*
2
5 1
1 2 1 3
6 2 1 5 7
*/