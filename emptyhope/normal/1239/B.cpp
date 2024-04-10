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
inline modint qpow(modint a,int b){return a^b;}

#define maxn 300005
int n,top,st[maxn],fa[maxn],id,mn,cnt;
char s[maxn],t[maxn];
int l[maxn],r[maxn],val[maxn];

signed main()
{
	n=read();scanf("%s",s+1);
	For(i,1,n){
		if(s[i]=='(')++top; else --top;
		if(!id || top<mn)mn=top,id=i;
	}
	if(top){
		puts("0"),puts("1 1");
		return 0;
	}
	For(i,id+1,n)t[i-id]=s[i];
	For(i,1,id-1)t[i+n-id]=s[i];
	For(i,1,n){
		if(t[i]=='(')st[++top]=++cnt,l[cnt]=i;
		else {
			r[st[top]]=i,fa[st[top]]=st[top-1];
			--top;
			val[st[top]]++;
		}
	}
	int res=val[0];
	int sl=1,sr=1;
	For(i,1,cnt)
	{
		if(!fa[i] && val[i]+1>res)
			res=val[i]+1,sl=l[i],sr=r[i];
		else if(fa[i] && !fa[fa[i]] && val[i]+val[0]+1>res)
			res=val[i]+val[0]+1,sl=l[i],sr=r[i];
	}
	sl+=id; if(sl>n)sl-=n;
	sr+=id; if(sr>n)sr-=n;
	printf("%d\n%d %d\n",res,sl,sr);
    return 0;
}