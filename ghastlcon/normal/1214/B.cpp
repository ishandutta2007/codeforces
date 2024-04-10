#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
const int oo=2139063143;
const int N=1010000;
const int P=1000000007;
using namespace std;
typedef long long LL;
typedef double db;
//char buf[1<<24],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
typedef int DATA1;
typedef int DATA2;
inline void sc (DATA1 &x)
{
    x=0; static int p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
}
inline void print (DATA2 x)
{
	if (x< 0) putchar('-'),x=-x;
	if (x>=10) print(x/10);
	putchar(x%10+'0');
}
inline void pr (DATA2 x) { print(x),putchar('\n'); }

int main()
{
	// freopen (".in","r",stdin);
	// freopen (".out","w",stdout);
	int a,b,n; sc(a),sc(b),sc(n);
	int ans=0;
	for (int i=0; i<=n; i++)
	{
		int A=i,B=n-i;
		if (A<=a&&B<=b) ++ans;
	}
	pr(ans);
	return 0;
}