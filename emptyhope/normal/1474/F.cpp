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
#define l first
#define r second
#define mkp make_pair
#define pb push_back
typedef pair<int,int>pii;

int m;
struct mat{
	modint a[55][55];
	mat(){memset(a,0,sizeof a);}
	modint *operator [](int x){return a[x];}
	void init1(){For(i,0,m)For(j,0,m)a[i][j]=(i==j);} 
	mat operator *(const mat&b)const{
		mat c;
		For(i,0,m)For(k,0,m)For(j,0,m)c[i][j]+=a[i][k]*b.a[k][j];
		return c;
	}
};

int n,a[233],nn;
inline mat qpow(mat a,int b){
	mat res; res.init1();
	for(;b;b>>=1,a=a*a)if(b&1)res=res*a;
	return res;
}

pii s[2333];
int d[2333],k,slen;
modint now[55],orz[55];
void mul(mat t){
	memset(orz,0,sizeof orz);
	For(i,0,m)For(j,0,m)
		orz[j]+=now[i]*t[i][j];
	For(i,0,m)now[i]=orz[i];
}
 
modint calc(int l,int r)
{
	m=r-l+1; slen=k=0;
	int sum=0;
	For(i,l,r){
		s[++slen]=mkp(sum+(a[i]<0?-1:1),sum+a[i]);
		sum+=a[i];
	} s[1].l=0;
	For(i,1,slen){
		d[++k]=s[i].l-1,d[++k]=s[i].l,d[++k]=s[i].l+1;
		d[++k]=s[i].r-1,d[++k]=s[i].r,d[++k]=s[i].r+1;
	}
	sort(d+1,d+k+1);
	k=unique(d+1,d+k+1)-d-1,--k;
	memset(now,0,sizeof now); now[0]=1;
	int lst=-1;
	For(i,1,k){
		mat t;
		For(j,1,slen){
			int mn=min(s[j].l,s[j].r),mx=max(s[j].l,s[j].r);
			if(mn<=lst+1 && mx>=d[i])
			{
				For(k,0,j-1) t[k][j]=1;
				if(s[j].l<s[j].r) t[j][j]=1;
			}
		}
		mul(qpow(t,d[i]-lst)); lst=d[i];
	}
	modint res=0;
	For(i,0,m) res+=now[i];
	return res;
}

signed main()
{
	n=read();read();
	For(i,1,n){
		int x=read();
		if(x)a[++nn]=x;
	}n=nn;
	modint res=0;
	int sum=0,mx=0;
	For(i,1,n){
		int t=sum;
		For(j,i,n)
			t+=a[j],mx=max(mx,t-sum);
		sum+=a[i];
	}
	if(mx==0){
		modint now=1;
		For(i,1,n)now+=(-a[i]);
		cout<<1<<' '<<now.x<<endl;
		return 0;
	}
	For(i,1,n){
		int t=0,r=-1;
		For(j,i,n){
			t+=a[j];
			if(t==mx)r=j;
		}
		if(r!=-1) res+=calc(i,r),i=r;
	}
	cout<<mx+1<<' '<<res.x;
    return 0;
}