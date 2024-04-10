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
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
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
const int MAXN = 4e5+10;
int T,n,x,now,flag,id[MAXN];
char s[MAXN],t[MAXN];
inl add(int x,int type){
	if(t[x]==(type^1)+'0') flag=0;
	else if(t[x]=='\0') t[x]=type+'0',now++;
}
inl void left(){
	rep(i,1,n){
		if(s[i]=='1'){
			if(i<=x && i+x<=n) add(i+x,1);
			else if(i>x && t[i-x]=='0' && i+x<=n) add(i+x,1) ;
			if(i>n-x && i-x>=1) add(i-x,1);
			else if(i<=n-x && t[i+x]=='0' && i-x>=1) add(i-x,1);
		}
		else {
			if(i+x<=n) add(i+x,0); 
			if(i-x>=1) add(i-x,0); 
		}
	} 
} 
inl void right(){
	per(i,n,1){
		if(s[i]=='1'){
			if(i<=x && i+x<=n) add(i+x,1);
			else if(i>x && t[i-x]=='0' && i+x<=n) add(i+x,1) ;
			if(i>n-x && i-x>=1) add(i-x,1);
			else if(i<=n-x && t[i+x]=='0' && i-x>=1) add(i-x,1);
		}
		else {
			if(i+x<=n) add(i+x,0); 
			if(i-x>=1) add(i-x,0); 
		}
	} 
}
inl void rnd(){
	random_shuffle(id+1,id+n+1);
	rep(j,1,n){
		int i=id[j];
		if(s[i]=='1'){
			if(i<=x && i+x<=n) add(i+x,1);
			else if(i>x && t[i-x]=='0' && i+x<=n) add(i+x,1) ;
			if(i>n-x && i-x>=1) add(i-x,1);
			else if(i<=n-x && t[i+x]=='0' && i-x>=1) add(i-x,1);
		}
		else {
			if(i+x<=n) add(i+x,0); 
			if(i-x>=1) add(i-x,0); 
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	srand(time(NULL));
	for(scanf("%d",&T);T;T--){
		scanf("%s%d",s+1,&x);
		n=strlen(s+1);flag=1;
		rep(i,1,n) t[i]='1';
		rep(i,1,n) if(s[i]=='0'){
			if(i-x>=1) t[i-x]='0';
			if(i+x<=n) t[i+x]='0';
		}
		rep(i,1,n) if(s[i]=='1'){
			int a=0;
			if(i-x>=1 && t[i-x]=='1') a=1;
			if(i+x<=n && t[i+x]=='1') a=1;
			flag&=a;
		}
		if(flag) {
			rep(i,1,n) putchar(t[i]);
			puts("");
		}
		else puts("-1");
	}
	return 0;
}