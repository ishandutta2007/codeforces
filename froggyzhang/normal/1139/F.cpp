#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,k) for (register int i=first[k];i;i=last[i])
#define Debug(x) cerr<<#x<<"="<<(x)<<endl
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 1e5+10;
int n,m,l[N],r[N],b[N],p[N],a[N],ans[N];
struct node{
	int l,r,x;
}d[N],D[N];
struct Node{
	int x,y,pos;
}c[N],C[N];
int cnt;
vector<int>v;
inline int Get(int x){return lower_bound(v.begin(),v.begin()+cnt,x)-v.begin()+1;}
int t[N<<2];
inline void Add(int x,int y){for (;x<=cnt;x+=x&-x) t[x]+=y;}
inline void Add(int l,int r,int x){Add(l,x),Add(r+1,-x);}
inline int Query(int x){int ret=0;for (;x;x-=x&-x) ret+=t[x];return ret;}
int main(){
	n=read(),m=read();
	For(i,1,n) l[i]=read(),v.push_back(l[i]);
	For(i,1,n) r[i]=read(),v.push_back(r[i]);
	For(i,1,n) b[i]=read();
	For(i,1,m) p[i]=read(),v.push_back(p[i]);
	For(i,1,m) a[i]=read();
	sort(v.begin(),v.end()),cnt=unique(v.begin(),v.end())-v.begin();//cerr<<cnt<<endl;
	For(i,1,n) d[i]=(node){Get(l[i]),Get(r[i]),b[i]+l[i]},D[i]=(node){Get(l[i]),Get(r[i]),l[i]-b[i]};
	For(i,1,m) c[i]=(Node){Get(p[i]),a[i]+p[i],i},C[i]=(Node){Get(p[i]),p[i]-a[i],i};
	auto solve = [](node *a,Node *b,int x){
		sort(a+1,a+1+n,[](node a,node b){return a.x<b.x;});
		sort(b+1,b+1+m,[](Node a,Node b){return a.y<b.y;});
		memset(t,0,sizeof t);
		int l=1;
		For(i,1,m){
			while (b[i].y>=a[l].x&&l<=n) Add(a[l].l,a[l].r,1),l++;
			ans[b[i].pos]+=Query(b[i].x)*x;
		}
	};
	solve(d,c,1),solve(D,C,1);
	For(i,1,n) d[i]=(node){Get(l[i]),Get(r[i]),0};
	For(i,1,m) c[i]=(Node){Get(p[i]),0,i};
	solve(d,c,-1);
	For(i,1,m) printf("%d ",ans[i]);
}