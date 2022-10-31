#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 100050
typedef long long ll;
char a[N],b[N];
ll ans;
int n,s[10];
int main() {
	int i;
	scanf("%d%s%s",&n,a+1,b+1);
	for(i=1;i<=n;i++) {
		a[i]-='0'; b[i]-='0';
		int tmp=(a[i]<<1)|b[i];
		if(tmp==0) {
			ans+=s[2]+s[3];
		}else if(tmp==1) {
			ans+=s[2];
		}else if(tmp==2) {
			ans+=s[0]+s[1];
		}else {
			ans+=s[0];
		}
		s[tmp]++;
	}
	printf("%lld\n",ans);
}