#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];
char s[MAXN];

int res[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	scanf("%s",s+1);
	
	sort(a+1,a+n+1);
	if(s[n] == 'R')
	{
		for(int i=n-1; i>=1; i-=2)
			a[i] = -a[i];
	}
	else
	{
		for(int i=n; i>=1; i-=2)
			a[i] = -a[i];
	}
	
	int l = 1, r = n;
	for(int i=n; i>1; --i)
	{
		if(s[i-1] == s[i]) res[i] = a[l++];
		else res[i] = a[r--];
	}
	res[1] = a[l];
	
	for(int i=1; i<=n; ++i)
		printf("%d %c\n",abs(res[i]),"LR"[res[i] > 0]);
	return 0;
}