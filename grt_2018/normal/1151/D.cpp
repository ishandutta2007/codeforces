#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
#define ST first
#define ND second

const int nax = 100*1000+1;
int n;
pii t[nax];
LL ans;

int main() {
	scanf("%d",&n);
	for(int i=0; i<n;i++) {
		scanf("%d%d",&t[i].ND,&t[i].ST);
		t[i].ST -= t[i].ND;
	}
	sort(t,t+n);
	for(int i=0;i<n;i++) {
		ans+=(LL)(n-1)*t[i].ND;
		ans+=(LL)(n-i-1)*t[i].ST;
	}
	printf("%lld",ans);
}