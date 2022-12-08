#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl;
const int sz = 1e5;

int n,m;
long long h[sz], p[sz];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,0,n)
		cin >> h[i];
	rep(i,0,m)
		cin >> p[i];
	long long low = 0;
	long long up = abs(h[0]-p[0])+abs(p[0]-p[m-1]);
	while(low<up)
	{
		long long mid = (up+low)/2;
		//debug(mid);
		int i=0, j=0;
		while(i<n && j<m)
		{
			if(h[i]<=p[j])
			{
				while(j<m && p[j]-h[i]<=mid)
					j++;
			}
			else
			{
				long long t=h[i]-p[j];
				if(t<=mid)
				{
					while(j<m && p[j]<=h[i])
						j++;
					while(j<m && t+min(2*(p[j]-h[i]),t+p[j]-h[i])<=mid)
						j++;
				}
			}
			i++;
		}
		//debug(j);
		if(j<m)
			low = mid+1;
		else
			up = mid;
	}
	cout << low<<endl;
}