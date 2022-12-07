#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define int long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int ax,ay,bx,by,cx,cy;
main()
{
	re(ax),re(ay),re(bx),re(by),re(cx),re(cy);
	// cerr<<(ax-by)*(ax-by)+(ay-by)*(ay-by)<<endl;
	// cerr<<(bx-cx)*(bx-cx)+(by-cy)*(by-cy)<<endl;
	if(!((ax*by-ay*bx)+(cx*ay-cy*ax)+(bx*cy-cx*by))
	&&(ax!=bx||bx!=cx||ay!=by||by!=cy))puts("No");
	else puts(((ax-bx)*(ax-bx)+(ay-by)*(ay-by)==(bx-cx)*(bx-cx)+(by-cy)*(by-cy))?"Yes":"No");
}