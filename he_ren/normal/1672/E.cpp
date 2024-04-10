#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;

inline int ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res == 0? inf: res;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int len;
	{
		int l = 1, r = n * 2000;
		while(l<r)
		{
			int mid = (l+r)>>1;
			if(ask(mid) == 1) r = mid;
			else l = mid+1;
		}
		len = l + 1;
	}
	
	int ans = len - 1;
	for(int i=2; i<=n; ++i)
		for(int j=len-i; j<ans; ++j) if(j % i == 0)
			if(ask(j / i) <= i)
				ans = j;
	
	printf("! %d",ans);
	fflush(stdout);
	return 0;
}