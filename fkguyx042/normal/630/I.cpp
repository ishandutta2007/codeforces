#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<queue>
#include<cmath>
#define Rep(x,a,b) for (int x=a;x<=b;x++)
#define Drp(x,a,b) for (int x=a;x>=b;x--)
#define Cross(x,a) for (int x=head[a];~x;x=next[x])
#define ll long long
#define oo 2147483647
using namespace std;
inline int IN(){
	int x=0,ch=getchar(),f=1;
	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
	if (ch=='-'){f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
inline void Out(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) Out(x/10),putchar(x%10+'0');
		else putchar(x+'0');
}
bool vis[4];
ll Qpow(int ds,int zs){
	if (zs<0) return 0;
	if (zs==0) return 1;
	ll tmp=Qpow(ds,zs/2);
	if (zs&1) return tmp*tmp*ds;
	else return tmp*tmp;
}
int main(){
	int n=IN();
	printf("%I64d\n",Qpow(4,n-4)*(n-3)*36+Qpow(4,n-3)*24);
}