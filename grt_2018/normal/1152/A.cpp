#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int n,m,a,b,c,d;

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<n;i++) {
		int x;
		scanf("%d",&x);
		if(x%2==0) a++;
		else b++;
	}
	for(int i=0; i<m;i++) {
		int x;
		scanf("%d",&x);
		if(x%2==0) c++;
		else d++;
	}
	int ans = min(a,d)+min(b,c);
	printf("%d",ans);
}