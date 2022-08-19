#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define maxn 100005
using namespace std;
int c[maxn], n;
bool hv[maxn];
int cnt = 0;
int ret[maxn];
int lst[maxn]; //k <= a  
int get(int k)
{
	if(ret[k]) return ret[k];
	memset(hv, 0, sizeof(hv));
	cnt = 0;
	int ans = 1;
	int lpl = 1;
	for(int i = 1; i <= n; i++)
	{
		if(!hv[c[i]]) cnt++;
		hv[c[i]] = 1;
		if(cnt > k) 
		{
			ans++;
			for(int j = lpl; j <= i; j++) hv[c[j]] = 0;
			lpl = i;
			hv[c[i]] = 1, cnt = 1;
		}
	}
	ret[k] = ans;
	return ans;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
//	get(3);
	int dvs = 600;
	
	for(int i = 1; i <= dvs; i++)
		get(i);
	int mxl = n / dvs + 1;
	for(int i = mxl; i >= 1; i--)
	{
		int l = 1, r = n;
		if(i != mxl) l = lst[i + 1];
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(get(mid) <= i) r = mid;
			else l = mid + 1; 
		}
		lst[i] = l;
	}
	for(int i = 1; i <= mxl; i++)
	{
		int nxt = n + 1;
		if(i != 1) nxt = lst[i - 1];
		for(int j = lst[i]; j < nxt; j++)
			ret[j] = i;	
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", ret[i]);
	return 0;
}