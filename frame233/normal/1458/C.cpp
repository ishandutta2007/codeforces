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

const int N=1005;
int tag[3],pos[3],a[N][N],ans[N][N];
inline int G(int x,int y,int t)
{
	return pos[t]==0?x:pos[t]==1?y:a[x][y];
}
void MAIN()
{
	memset(tag,0,sizeof(tag)),pos[0]=0,pos[1]=1,pos[2]=2;
	int n,m;read(n,m);
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)read(a[i][j]),--a[i][j];
	char opt;
	while(m--)
	{
		do{opt=getchar();}while(!isalpha(opt));
		if(opt=='L') --tag[1];
		else if(opt=='R') ++tag[1];
		else if(opt=='D') ++tag[0];
		else if(opt=='U') --tag[0];
		else if(opt=='C') std::swap(pos[0],pos[2]),std::swap(tag[0],tag[2]);
		else std::swap(pos[1],pos[2]),std::swap(tag[1],tag[2]);
	}
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)
	{
		int A=G(i,j,0),B=G(i,j,1),C=G(i,j,2);
		A=(A+tag[0]%n+n)%n,B=(B+tag[1]%n+n)%n,C=(C+tag[2]%n+n)%n;
		ans[A][B]=C;
	}
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)printf("%d%c",ans[i][j]+1," \n"[j==n-1]);
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}