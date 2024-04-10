// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=505;
char s[N][N];
struct qry{int x1,y1,x2,y2,id;}q[600005],t[600005];
bool ans[600005];
int n,m;
std::bitset<N> a[N][N],b[N][N];
void solve(int l,int r,int L,int R)
{
	if(l>r||L>R) return;
	int mid=(l+r)>>1;
	for(int i=m;i>=1;--i) if(s[mid][i]!='#') a[mid][i]=a[mid][i+1],a[mid][i].set(i);
	for(int i=mid-1;i>=l;--i) for(int j=m;j>=1;--j) if(s[i][j]!='#') a[i][j]=a[i+1][j]|a[i][j+1];
	for(int i=1;i<=m;++i) if(s[mid][i]!='#') b[mid][i]=b[mid][i-1],b[mid][i].set(i);
	for(int i=mid+1;i<=r;++i) for(int j=1;j<=m;++j) if(s[i][j]!='#') b[i][j]=b[i-1][j]|b[i][j-1];
	int p1=L,p2=R;
	for(int i=L;i<=R;++i)
	{
		int x1=q[i].x1,y1=q[i].y1,x2=q[i].x2,y2=q[i].y2;
		if(x1<=mid&&x2>=mid) ans[q[i].id]=(a[x1][y1]&b[x2][y2]).any();
		else if(x1<mid&&x2<mid) t[p1++]=q[i];
		else if(x1>mid&&x2>mid) t[p2--]=q[i];
	}
	for(int i=L;i<p1;++i) q[i]=t[i];
	for(int i=R;i>p2;--i) q[i]=t[i];
	solve(l,mid-1,L,p1-1),solve(mid+1,r,p2+1,R);
}
int main()
{
	read(n,m);
	for(int i=1;i<=n;++i) read_str(s[i]+1);
	int _;read(_);
	int x1,y1,x2,y2;
	for(int i=1;i<=_;++i) read(x1,y1,x2,y2),q[i]={x1,y1,x2,y2,i};
	solve(1,n,1,_);
	for(int i=1;i<=_;++i) puts(ans[i]?"Yes":"No");
	return 0;
}