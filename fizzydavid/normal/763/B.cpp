//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int main()
{
	int n;
	puts("YES");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,c=1;
		scanf("%d%d",&x,&y);
		if(x%2==0)c++;
		if(y%2==0)c+=2;
		printf("%d\n",c);
		scanf("%d%d",&x,&y);
	}
	return 0;
}