// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
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

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1005;
int n;
struct node{
	ll x,y;
	int id;
}a[N],b[N];
Finline bool cmp1(const node &a,const node &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
Finline bool cmp2(const node &a,const node &b){return a.y==b.y?a.x<b.x:a.y<b.y;}
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
ll X[N*3],Y[N*3];
pi rx[N*3],ry[N*3];
int Fa[N],tmp[15];
int Find(int x){return x==Fa[x]?x:Fa[x]=find(Fa[x]);}
bool check(int mid)
{
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<n;++i) if(a[i].x==a[i+1].x&&a[i+1].y-a[i].y<=mid) fa[find(a[i].id)]=find(a[i+1].id);
	for(int i=1;i<n;++i) if(b[i].y==b[i+1].y&&b[i+1].x-b[i].x<=mid) fa[find(b[i].id)]=find(b[i+1].id);
	int cnt=0;for(int i=1;i<=n;++i) cnt+=fa[i]==i;
	if(cnt>4) return false;
	if(cnt==1) return true;
	int p1=0,p2=0;
	for(int i=1;i<=n;++i) X[++p1]=a[i].x,X[++p1]=a[i].x-mid,X[++p1]=a[i].x+mid;
	for(int i=1;i<=n;++i) Y[++p2]=a[i].y,Y[++p2]=a[i].y-mid,Y[++p2]=a[i].y+mid;
	std::sort(X+1,X+p1+1),p1=std::unique(X+1,X+p1+1)-X-1;
	std::sort(Y+1,Y+p2+1),p2=std::unique(Y+1,Y+p2+1)-Y-1;
	for(int i=1;i<=p1;++i) rx[i]=mkpr(std::lower_bound(a+1,a+n+1,(node){X[i],-inf,0},cmp1)-a,std::lower_bound(a+1,a+n+1,(node){X[i],inf,0},cmp1)-a-1);
	for(int i=1;i<=p2;++i) ry[i]=mkpr(std::lower_bound(b+1,b+n+1,(node){-inf,Y[i],0},cmp2)-b,std::lower_bound(b+1,b+n+1,(node){inf,Y[i],0},cmp2)-b-1);
	for(int i=1;i<=p1;++i)
	{
		for(int j=1;j<=p2;++j)
		{
			if(rx[i].first>rx[i].second&&ry[j].first>ry[j].second) continue;
			int qwq=0;
			if(rx[i].first<=rx[i].second)
			{
				int p=std::lower_bound(a+rx[i].first,a+rx[i].second+1,(node){X[i],Y[j],0},cmp1)-a;
				if(p<=rx[i].second&&a[p].y-Y[j]<=mid) tmp[++qwq]=find(a[p].id);
				--p;if(p<=rx[i].second&&p>=rx[i].first&&Y[j]-a[p].y<=mid) tmp[++qwq]=find(a[p].id);
			}
			if(ry[j].first<=ry[j].second)
			{
				int p=std::lower_bound(b+ry[j].first,b+ry[j].second+1,(node){X[i],Y[j],0},cmp2)-b;
				if(p<=ry[j].second&&b[p].x-X[i]<=mid) tmp[++qwq]=find(b[p].id);
				--p;if(p<=ry[j].second&&p>=ry[j].first&&X[i]-b[p].x<=mid) tmp[++qwq]=find(b[p].id);
			}
			std::sort(tmp+1,tmp+qwq+1);qwq=std::unique(tmp+1,tmp+qwq+1)-tmp-1;
			if(qwq==cnt) return true;
		}
	}
	return false;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i) read(a[i].x,a[i].y),a[i].id=i,b[i]=a[i];
	std::sort(a+1,a+n+1,cmp1),std::sort(b+1,b+n+1,cmp2);
	int l=1,r=2e9;
	while(l<r)
	{
		int mid=((ll)l+(ll)r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(!check(l)) l=-1;
	printf("%d\n",l);
	return 0;
}