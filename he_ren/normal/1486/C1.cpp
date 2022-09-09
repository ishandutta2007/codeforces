#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline int ask(int l,int r)
{
	if(l == r) return -1;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int l = 1, r = n, pos = ask(1,n);
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(pos <= mid)
		{
			int res = ask(l, mid);
			if(res == pos) r = mid;
			else l = mid+1, pos = ask(mid+1, r);
		}
		else
		{
			int res = ask(mid+1,r);
			if(res == pos) l = mid+1;
			else r = mid, pos = ask(l, mid);
		}
	}
	printf("! %d",l);
	fflush(stdout);
	return 0;
}