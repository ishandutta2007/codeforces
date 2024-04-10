#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN], b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=n; i>1; --i) a[i] -= a[i-1];
	for(int i=n; i>1; --i) b[i] -= b[i-1];
	vector<int> x(a+2,a+n+1), y(b+2,b+n+1);
	
	sort(x.begin(), x.end()); sort(y.begin(), y.end());
	if(a[1] == b[1] && x == y) printf("Yes");
	else printf("No");
	return 0;
}