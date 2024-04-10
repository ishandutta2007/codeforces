#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN];
int a[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	for(int i=1; i<=n; ++i) a[i] = a[i-1] + s[i] - 'a' + 1;
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",a[r] - a[l-1]);
	}
	return 0;
}