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
const int MAXN = 2e5+10;
int n,m,ans=1e9,a[MAXN];
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
template<class T>struct MemoryPool{
	T buf[MAXN*30],*st[MAXN],*tail;
	int top;
	MemoryPool():top(0),tail(buf){}
	inl T *alloc(){return top?st[top--]:++tail;}
	inl void recycle(T *x){st[++top]=x;}
};
struct _01trie{
	struct Node{
		Node *son[2];
		int size,sum;
		static inl Node *NewNode(MemoryPool<Node> &pool){
			Node *tmp=pool.alloc();
			tmp->son[0]=tmp->son[1]=NULL;tmp->size=0,tmp->sum=0;
			return tmp;
		}
		inl void Insert(MemoryPool<Node> &pool,int k,int dep){
			size++;sum+=dep+1;
			if(size==m) ylmin(ans,sum);
			if(dep==-1)return ;
			if(!son[(bool)(k&(1<<dep))]) son[(bool)(k&(1<<dep))]=NewNode(pool);
			son[(bool)(k&(1<<dep))]->Insert(pool,k,dep-1);
		}
	}*root;
	MemoryPool<Node> pool;
	inl void Init(){
		sort(a+1,a+n+1);
		root=Node::NewNode(pool);
		for(int i=1;i<=n;i++) root->Insert(pool,a[i],log2(a[i]));
	}
}mjy;
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,n) read(a[i]);
	mjy.Init();
	printf("%d\n",ans);
	return 0;
}