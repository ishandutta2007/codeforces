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
#define inf 0x3f3f3f3f

int n;
char a[maxn];
char s[maxn],t[maxn];
bool check(char *s)
{
//	cout<<s+1<<endl;
	int top=0;
	For(i,1,n)
		if(s[i]=='(')++top;
		else{
			if(!top)return 0;
			--top;
		}
	return top==0;
} 
void work()
{
	n=read();
	cin>>a+1;
	int cnt1=0;
	For(i,1,n)cnt1+=(a[i]=='1');
//	cout<<cnt1<<endl;
	if(cnt1%2){
		int now=0;
		For(i,1,n)
			if(a[i]=='0'){
				if(!now)s[i]='(',t[i]=')';
				else s[i]=')',t[i]='(';
				now^=1;
			}
		
	}
	int now=0;
	For(i,1,n){
		if(a[i]=='1'){
			now++;
			if(now<=cnt1/2)
				s[i]=t[i]='(';
			else s[i]=t[i]=')';
		}
	}
	now=0;
	For(i,1,n)
		if(a[i]=='0'){
			if(!now)s[i]='(',t[i]=')';
			else s[i]=')',t[i]='(';
			now^=1;
		}
	if(check(s)&&check(t)){
		puts("YES");
		For(i,1,n)putchar(s[i]);puts("");
		For(i,1,n)putchar(t[i]);puts("");
	}
	else puts("NO");
}

signed main()
{
//	freopen("data","r",stdin);
//	freopen("my","w",stdout);
	int T=read();
	while(T--)work(); 
	return 0;
}