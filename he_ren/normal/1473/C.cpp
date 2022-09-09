#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXD = 1e5 + 5;

int a[MAXD];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	for(int i=1; i<=d; ++i) a[i] = i;
	reverse(a+1,a+d+1);
	reverse(a+1,a+(n-d+1)+1);
	reverse(a+1,a+d+1);
	for(int i=1; i<=d; ++i) printf("%d ",a[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}