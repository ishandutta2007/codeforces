/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
int n;char s[5],t[5];
template<class T>inl void ylmin(T &a,T b){a=a<b?a:b;}
template<class T>inl void ylmax(T &a,T b){a=a>b?a:b;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
inl bool check(char *s,char *t){
	return s[0]==t[0] && s[1]==t[1];
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%s%s",&n,s,t);
	puts("YES");
	if(s[0]==s[1] || t[0]==t[1]){
		if(t[0]!=t[1]) {
			char tmp[5]={s[0],s[1]};
			s[0]=t[0],s[1]=t[1],t[0]=tmp[0],t[1]=tmp[1];
		}
        if((s[0]=='a' && s[1]=='b') || (s[0]=='b' && s[1]=='c') || (s[0]=='c' && s[1]=='a')) rep(i,1,n) printf("acb");
		else rep(i,1,n) printf("abc");
        
	}else {
		char tmp[5]={'a','b','c'};
		do if(!(check(tmp,s) || check(tmp,t) || check(tmp+1,s) || check(tmp+1,t))) break; while(next_permutation(tmp,tmp+3));
		rep(i,0,2) rep(j,1,n) putchar(tmp[i]);	
	}
	return 0;
}