// luogu-judger-enable-o2
// Author -- Frame
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=100005;
const double PI=acos(-1);
struct node{
	double x,y;
	Finline node(const double X=0,const double Y=0):x(X),y(Y){}
	Finline void rotate(const double &a)
	{
		double tmp=x;
		x=cos(a)*x-sin(a)*y;
		y=cos(a)*y+sin(a)*tmp;
	}
};
node point(node a,node b,double y)
{
	double k=(a.y-b.y)/(a.x-b.x);
	double B=a.y-k*a.x;
	double x=(y-B)/k;
	return node(x,k*x+B);
}
double cross(const node &a,const node &b)
{
	return a.x*b.y-a.y*b.x;
}
int main()
{
    double w,h,a;
    scanf("%lf %lf %lf",&w,&h,&a);
    if(a>90.0)
    {
        a=180.0-a;
    }
    int tmp=(int)a;
    if(!(tmp%360))
    {
        printf("%.12lf\n",w*h);
        return 0;
    }
    if(w<h) std::swap(w,h);
    a=a/180.0*PI;
	node a1=node(-w/2.0,-h/2.0),a2=node(w/2.0,-h/2.0),a3=node(w/2.0,h/2.0),a4=node(-w/2.0,h/2.0);
	node b1=a1,b2=a2,b3=a3,b4=a4;
	b1.rotate(a);
	b2.rotate(a);
	b3.rotate(a);
	b4.rotate(a);
    if(b2.y>h/2.0)
    {
	    node c1=point(b1,b2,-h/2.0);
	    node c2=point(b1,b2,h/2.0);
	    node c4=point(b4,b3,-h/2.0);
	    printf("%.12lf\n",cross(node(c2.x-c1.x,c2.y-c1.y),node(c4.x-c1.x,c4.y-c1.y)));
	    return 0;
	}
    double sina=sin(a);
    double cosa=cos(a);
    double x=(h-(w*cosa/sina+w/sina))/(-(cosa/sina)*(1+cosa)-(cosa+1)/sina+sina);
    double y=sina*x;
    double c=w-x-cosa*x;
    double d=c*cosa/sina;
    printf("%.12lf\n",w*h-x*cosa*y-c*d);
    return 0;
}