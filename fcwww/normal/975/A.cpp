/**************************
orz popoqqq
orz wyfcyx
orz jkxing
orz szy
orz xqz
orz GXZlegend
orz CQzhangyu
orz lijinnn
orz Winniechen
***************************/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double f2;
#define mem1(x) memset(x,0,sizeof(x))
#define mem2(x) memset(x,0x3f,sizeof(x))
int fabs(int x){return x>0?x:-x;}
#define N 1030
char s[N];
int n;
bool h[1<<26];
int main() {
	scanf("%d",&n);
	int i,j,ans=0;
	for(i=1;i<=n;i++) {
		scanf("%s",s);
		int re=0;
		for(j=0;s[j];j++) {
			re|=(1<<(s[j]-'a'));
		}
		if(h[re]==0) ans++;
		h[re]=1;
	}
	printf("%d\n",ans);
}
/*
******************************
suika
******************************
*/