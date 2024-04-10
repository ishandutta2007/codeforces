#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline int ask(int x)
{
	printf("? %d\n",x); fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

int main(void)
{
	srand((unsigned long long)new char);
	
	int n;
	scanf("%d",&n);
	
	int l = 1, r = n;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(ask(mid) < ask(mid+1)) r = mid;
		else l = mid+1;
	}
	
	printf("! %d",l);
	fflush(stdout);
	return 0;
}