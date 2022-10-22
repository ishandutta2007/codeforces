#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define inl inline
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define mymax(a,b) ((a)<(b)?a=b,1:0)
#define mymin(a,b) ((a)>(b)?a=b,1:0)
#define lowbit(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define mst0(x) memset(x,0,sizeof(x))
#define debug(x) printf(#x":%d\n",x)
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
const int MAXN = 1e5+10;
char s[MAXN];
int n,q;
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
struct Node{
	int a[26];
}tree[MAXN<<2];
inl int Get(Node x,int res=0){
	for(int i=0;i<26;i++) res+=(x.a[i]>0);
	return res;
}
inl Node Merge(Node x,Node y){
	Node ans;
	for(int i=0;i<26;i++)ans.a[i]=x.a[i]+y.a[i];
	return ans;
}
inl void Update(int root,int l,int r,int Pos,int k,int t){
	if(l==r){tree[root].a[k]+=t;return ;}
	if(Pos<=Mid) Update(lson,l,Mid,Pos,k,t);
	else Update(rson,Mid+1,r,Pos,k,t);
	tree[root]=Merge(tree[lson],tree[rson]);
}
inl Node Query(int root,int l,int r,int L,int R){
	if(l>=L && r<=R) return tree[root];
	if(R<=Mid) return Query(lson,l,Mid,L,R);
	else if(L>Mid) return Query(rson,Mid+1,r,L,R);
	else return Merge(Query(lson,l,Mid,L,R),Query(rson,Mid+1,r,L,R));
} 
inl void Build(int root,int l,int r){
	if(l==r){
		tree[root].a[s[l]-'a']=1;
		return ;
	}Build(lson,l,Mid),Build(rson,Mid+1,r);
	tree[root]=Merge(tree[lson],tree[rson]);
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%s",s+1);n=strlen(s+1);
	Build(1,1,n);scanf("%d",&q);
	while(q--){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int Pos;char c[5];
			scanf("%d%s",&Pos,c+1);
			Update(1,1,n,Pos,s[Pos]-'a',-1);
			s[Pos]=c[1];
			Update(1,1,n,Pos,s[Pos]-'a',1);
		}else {
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",Get(Query(1,1,n,l,r)));
		}
	}
	return 0;
}