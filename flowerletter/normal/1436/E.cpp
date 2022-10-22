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
const int MAXN = 1e5 + 10;
const int block = sqrt(1e5); 
int n,a[MAXN],rev[MAXN],L[MAXN],R[MAXN];
int cnt[MAXN],sum[MAXN],size[MAXN];
vector<int> pos[MAXN]; 
struct Pro{
	int l,r,expect;
	int ans;
};
vector<Pro> q;
inl bool cmp1(Pro a,Pro b){
	if(rev[a.l]==rev[b.l]) return a.r<b.r;
	else return rev[a.l]<rev[b.l];
}
inl bool cmp2(Pro a,Pro b){
	return a.expect<b.expect;
}
inl void del(int x){
	if(--cnt[x]==0) sum[rev[x]]--;
}
inl void add(int x){
	if(cnt[x]++==0) sum[rev[x]]++;
}
inl bool query(int x){
	if(!x) return true;
	if(x==n+1) return false; 
	int pre=rev[x]-1;
	rep(i,1,pre) if(sum[i]!=size[i]) return false;
	rep(i,L[rev[x]],x) if(!cnt[i]) return false;
	return true; 
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(a[i]),pos[a[i]].push_back(i);
	int flag=1;
	rep(i,1,n) if(a[i]^1) flag=0;
	if(flag){
		puts("1");
		return 0;
	}
	int num=(n%block==0)?n/block:(n/block+1);
	rep(i,1,num) {
		L[i]=R[i-1]+1;
		R[i]=min(L[i]+block,n);
		size[i]=R[i]-L[i]+1;
		rep(j,L[i],R[i]) rev[j]=i;
	}
	rep(i,1,n+2) {
		int last=1;
		for(auto s:pos[i]) {
			if(last<=s-1) q.push_back((Pro){last,s-1,i-1,0});
			last=s+1;
		}
		if(last<=n) q.push_back((Pro){last,n,i-1,0});
	}
	sort(all(q),cmp1);
	int l=1,r=0;
	for(auto &s:q){
		while(l>s.l) add(a[--l]);
		while(r<s.r) add(a[++r]);
		while(l<s.l) del(a[l++]);
		while(r>s.r) del(a[r--]);
		s.ans=query(s.expect);
	}
	sort(all(q),cmp2);
	for(int l=0,r=0;l<size(q);l=r+1){
		while(r+1<size(q) && q[r+1].expect==q[l].expect) r++;
		int flag=0;
		rep(i,l,r) flag|=q[i].ans;
		if(!flag) {
			printf("%d\n",q[l].expect+1);
			return 0;
		}
	}
	return 0;
}