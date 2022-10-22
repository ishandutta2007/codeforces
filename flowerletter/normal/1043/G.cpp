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
const int MAXN = 2e5+10;
const int block = sqrt(2e5);
const int inf = 1e9;
const int size = 4e5 + 10 ;
int n,q,l,r,sum[MAXN][26];
char s[MAXN];
vector<int> d[MAXN]; 
struct Sam{
	int Nodecnt=1,last=1;
	int link[size],len[size],next[size][26],pos[size],flag[size];
	inl void insert(int c,int po){
		int p=last,cur=++Nodecnt;
		pos[cur]=po,len[cur]=len[p]+1,flag[cur]=1;
		for(;p && !next[p][c];p=link[p]) next[p][c]=cur;
		if(!p) link[cur]=1;
		else {
			int q=next[p][c];
			if(len[q]==len[p]+1) link[cur]=q;
			else{
				int clone=++Nodecnt;
				len[clone]=len[p]+1;
				link[clone]=link[q];
				pos[clone]=pos[q];
				rep(i,0,25) next[clone][i]=next[q][i];
				for(;p && next[p][c]==q;p=link[p]) next[p][c]=clone;
				link[cur]=clone,link[q]=clone;
			}
		}
		last=cur;
	}
};
struct SA{
	Sam sam;
	int sa[size],rank[size],height[size],st[19][size],lg2[size],dfs_time;
	int next[size][26];
	inl void build(){
		rep(i,2,sam.Nodecnt) next[sam.link[i]][s[sam.pos[i]+sam.len[sam.link[i]]]]=i;
	}
	inl void dfs(int u){
		if(sam.flag[u]) sa[rank[sam.pos[u]]=++dfs_time]=sam.pos[u];
		rep(i,0,25) if(next[u][i]) dfs(next[u][i]);
	}
	inl void init(){
		int len=0;
		rep(i,1,n) {
			len=max(0,len-1);
			while(s[i+len]==s[sa[rank[i]-1]+len]) len++;
			st[0][rank[i]]=height[rank[i]]=len; 
		}
		rep(i,2,n) lg2[i]=lg2[i>>1]+1;
		rep(i,1,17) rep(j,1,n-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	}
	inl int lcp(int l,int r){
		if(l==r) return n-l+1;
		if((l=rank[l])>(r=rank[r])) swap(l,r);
		int k=lg2[r-l]; l++;
		return min(st[k][l],st[k][r-(1<<k)+1]);
	}
}pre,sub;
inl bool check1(int l,int r){
	if(!size(d[2])){
		rep(i,2,n) if(d[i].empty()) 
			for(int j=i;j<=n;j+=i) d[j].pb(i); 
	}
	int len=r-l+1;
	for(auto g:d[len]){
		int tmp=len/g;
		if(pre.lcp(l,l+tmp)>=len-tmp) return true;
	}
	return false;
}
template<size_t size>struct RMQ{
	int st[18][size],lg2[size];
	RMQ(){memset(st,0x3f,sizeof(st));}
	inl void update(int l,int r,int c){
		if(l>r) return ;
		if(!lg2[2]) rep(i,2,n) lg2[i]=lg2[i>>1]+1;
		int k=lg2[r-l+1];
		ylmin(st[k][l],c),ylmin(st[k][r-(1<<k)+1],c);
	}
	inl void init(function<int(int,int)> add,function<int(int,int)> get){
		per(i,17,1)	rep(j,1,n-(1<<i)+1)
			ylmin(st[i-1][j],st[i][j]),ylmin(st[i-1][j+(1<<i-1)],st[i][j]);
		rep(i,1,n) st[0][i]=add(i,st[0][i]);
		rep(i,1,17) rep(j,1,n-(1<<i)+1) st[i][j]=get(st[i-1][j],st[i-1][j+(1<<i-1)]);
	}
	inl int query(int l,int r){
		int k=lg2[r-l+1];
		return min(st[k][l],st[k][r-(1<<k)+1]);
	}
};
RMQ<200005> lrmq,rrmq;
inl void build(){
	rep(i,1,n){
		for(int j=i;j+i<=n;j+=i){
			int p=sub.lcp(n-j+1,n-j-i+1),q=(j+i+1<=n?pre.lcp(j+1,j+i+1):0);
			ylmin(p,i),ylmin(q,i);
			p=j-p+1,q=j+i+q;
			lrmq.update(p,q-2*i+1,i*2);
			rrmq.update(p+2*i-1,q,i*2);
		}
	}
	lrmq.init([](int a,int b){return a+b-1;},[](int a,int b){return min(a,b);});
	rrmq.init([](int a,int b){return a-b+1;},[](int a,int b){return max(a,b);});
}
inl bool check2(int l,int r){
	if(lrmq.st[0][l]<=r || rrmq.st[0][r]>=l) return true;
	int len=min(block,r-l);
	rep(i,1,len) if(pre.lcp(l,r-i+1)>=i) return i*2<=r-l+1;
	if(len!=block) return false;
	int t=n/block+1,lpos=max(1,pre.rank[l]-t),rpos=min(n,pre.rank[l]+t),res=inf;
	rep(i,lpos,rpos)
		if(pre.sa[i]>=l && pre.sa[i]<=r && pre.lcp(l,pre.sa[i])>r-pre.sa[i]) ylmin(res,r-pre.sa[i]+1);
	return res*2<=r-l+1;
}
inl bool check3(int l,int r){
	if(sum[r][s[l]]-sum[l-1][s[l]]>1 || sum[r][s[r]]-sum[l-1][s[r]]>1) return true;
	return lrmq.query(l,r)<=r;
}
inl bool check0(int l,int r){
	bool flag=0;
	rep(i,0,25) flag|=(sum[r][i]-sum[l-1][i]>1);
	return !flag; 
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("myout.txt","w",stdout);
	scanf("%d%s%d",&n,s+1,&q);
	rep(i,1,n) s[i]-='a';s[n+1]=-1;
	rep(i,1,n) rep(j,0,25) sum[i][j]=sum[i-1][j]+(s[i]==j);
	per(i,n,1) pre.sam.insert(s[i],i);
	pre.build(),pre.dfs(1),pre.init();
	reverse(s+1,s+n+1);
	per(i,n,1) sub.sam.insert(s[i],i);
	sub.build(),sub.dfs(1),sub.init();
	reverse(s+1,s+n+1);
	build();
	rep(i,1,q){
		read(l),read(r);
		if(check0(l,r)) puts("-1");
		else if(check1(l,r)) puts("1");
		else if(check2(l,r)) puts("2");
		else if(check3(l,r)) puts("3");
		else puts("4");
	}
	return 0;
}