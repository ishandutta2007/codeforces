#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1050
int n,m,f[N],q;
char S[N],T[N];
int main() { scanf("%d%d%d%s%s",&n,&m,&q,S+1,T+1); int i,j; for(i=1;i<=n-m+1;i++) { int flg=1; for(j=i;j<=i+m-1;j++) { if(S[j]!=T[j-i+1]) { flg=0; break; } } f[i]=flg; } int x,y; while(q--) { scanf("%d%d",&x,&y); if(y-x+1<m) puts("0"); else { int ans=0; y=y-m+1; for(i=x;i<=y;i++) ans+=f[i]; printf("%d\n",ans); } } }