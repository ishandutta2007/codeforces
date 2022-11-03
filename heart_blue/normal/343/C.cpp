#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
using namespace std;
#define MAX (a,b) ((a)>(b)?(a):(b))
#define MIN (a,b) ((a)<(b)?(a):(b))
#define MEM(a,b) memset((a),(b),sizeof(a))
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e5+10;
LL a[N];
LL b[N];
int n,m;
bool check(LL x)
{
	int i,j;
	i = j = 0;
	int flag = 0;
	LL t = 0;
	while(i < n && j < m)
	{
		if(b[j] <= a[i])
		{
			if(a[i] - b[j] > x) return false;
			if(!flag)
			{
				flag = 1;
				t = a[i] - b[j];
			}
			if(flag) j++;
		}
		else
		{
			if(b[j] > a[i] + x - t*2)
			{
				if(x - t < (b[j] - a[i]) * 2)
				{
					i ++;
					t = 0;
					flag = 0;
				}
				else 
					j++;
			}
			else
			{
				j++;
			}
		}
	}
	return j == m;
}
int main()
{
	//freopen("input.txt","r",stdin);

	cin >> n >> m;
	int maxv = -1;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];

	LL l,r;
	l = 0;
	r = 1e11;
	LL ans;
	while(l <= r)
	{
		LL mid =(l+r)/2;
		if(check(mid)) ans = mid, r = mid-1;
		else l = mid+1;
	}
	cout << ans << endl;


	return 0;
}