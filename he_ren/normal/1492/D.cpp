#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int s[MAXN], t[MAXN];

int main(void)
{
	int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	if(b == 1)
	{
		if(k) printf("No");
		else
		{
			printf("Yes\n");
			cout << 1 << string(a, '0') << endl;
			cout << 1 << string(a, '0') << endl;
		}
		return 0;
	}
	s[0] = t[0] = 1;
	--b;
	int n = a + b;
	if(k+1 > n) return printf("No"), 0;
	
	s[1] = t[k+1] = 1;
	--b;
	for(int i=1; i<=n && b; ++i)
		if(!s[i] && !t[i]) s[i] = t[i] = 1, --b;
	if(b) return printf("No"), 0;
	
	printf("Yes\n");
	for(int i=0; i<=n; ++i) printf("%d",s[i]); printf("\n");
	for(int i=0; i<=n; ++i) printf("%d",t[i]); printf("\n");
	return 0;
}