#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int n;
LL cnt=9;

int main() {
	scanf("%d",&n);
	while(n>=10) {
		int l = n%10;
		cnt+=(10-l);
		n = (n+(10-l));
		while(n%10==0) {
			n/=10;
		}
	}
	printf("%lld",cnt);
}