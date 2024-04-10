#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int T = 0;
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
		if(l == mid && pos == mid){ l = mid+1; continue;}
		if(mid+1 == r && pos == mid+1){ r = mid; continue;}
		
		if(pos <= mid)
		{
			if(ask(min(pos,l), mid) == pos) r = mid;
			else l = mid+1;
		}
		else
		{
			if(ask(mid+1, max(pos,r)) == pos) l = mid+1;
			else r = mid;
		}
	}
	printf("! %d",l);
	fflush(stdout);
	return 0;
}