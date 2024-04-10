#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 31;
int n,m,minp=1000*1000*1000,maxp;
int r;

int main() {
    scanf("%d%d%d",&n,&m,&r);
    for(int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		minp=min(minp,x);
	}
	for(int i=0; i<m;i++) {
		int x;
		scanf("%d",&x);
		maxp=max(maxp,x);
	}
	int b = maxp - minp;
	if(b<=0) {
		printf("%d",r);
		return 0;
	}
	int cnt = r/minp;
	r -= cnt*minp;
	r+=maxp*cnt;
	printf("%d",r);
}