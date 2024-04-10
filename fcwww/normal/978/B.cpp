#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double f2;
int n,a[150];
char s[150];
int main() {
	scanf("%d%s",&n,s+1);
	int i,ans=0,now=1,cnt=0;
	for(i=1;i<=n;i++) {
		if(s[i]!='x') {
			if(cnt>=3)
				ans+=(cnt-2);
			cnt=0;
		}else {
			cnt++;
		}
	}
	if(cnt>=3) ans+=(cnt-2);
	printf("%d\n",ans);
}