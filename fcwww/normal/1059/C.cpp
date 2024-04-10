#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;
#define N 1000500
int n,ans[N],id[N];
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		id[i]=i;
	}
	int cnt=1;
	while(1) {
		if(n==3) {
			ans[++ans[0]]=__gcd(id[1],__gcd(id[2],id[3])); ans[++ans[0]]=__gcd(id[2],id[3]); ans[++ans[0]]=id[3]; break;
		}
		if(n==2) {
			ans[++ans[0]]=__gcd(id[1],id[2]); ans[++ans[0]]=id[2];  break;
		}
		if(n==1) {
			ans[++ans[0]]=id[1]; break;
		}
		int tot=0;
		for(i=1;i<=n;i++) {
			if(i%2==0) {
				id[i>>1]=id[i]; tot++;
			}else {
				ans[++ans[0]]=cnt;
			}
		}
		n=tot; cnt*=2;
	}
	for(i=1;i<=ans[0];i++) printf("%d ",ans[i]);
}