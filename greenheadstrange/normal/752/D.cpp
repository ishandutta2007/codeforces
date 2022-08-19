#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue> 
#define maxn 100005
#define mxhash 10
using namespace std;
int mode[10] = {30012300, 40013223, 12391231, 12309122,73524845, 7136743, 71923764, 5421867, 42793863, 27846273};
struct th
{
	int hash[mxhash];
	int num;
	int id;
	bool operator < (const th &a)const
	{
		for(int i = 0; i < mxhash; i++)
			if(hash[i] != a.hash[i])
				return hash[i] < a.hash[i];
		return num < a.num;
	}
	bool hseq(th a)
	{
		for(int i = 0; i < mxhash; i++)
			if(hash[i] != a.hash[i])
				return false;
		return true;
	}
	int bjhs(th a)
	{	// 0 < 1 = 2 >
		for(int i = 0; i < mxhash; i++)
			if(hash[i] != a.hash[i])
			{
				if(hash[i] < a.hash[i]) 
					return 0;
				else 
					return 2;	
			}
		return 1;
	 } 
}pool[maxn], rev[maxn];
bool have[maxn];
bool self[maxn];//  
int n, k;
int power[mxhash][maxn]; 
char inp[maxn];
int num[maxn];
int main()
{
	int ans = 0;
	scanf("%d%d", &k, &n);
	for(int i = 0 ; i < mxhash; i++)
		power[i][0] = 1;
	for(int j = 0 ; j < mxhash; j++)
		for(int i = 1; i < maxn; i++)
			power[j][i] = power[j][i - 1] * 26, power[j][i] %=  mode[j];
	
	memset(self, false, sizeof(self));
	memset(have, false, sizeof(have));
	for(int i = 0; i < k; i++)
	{
		memset(pool[i].hash, 0, sizeof(pool[i].hash));
		memset(rev[i].hash, 0, sizeof(rev[i].hash));
		scanf("%s", inp);
		pool[i].id = i;
		for(int s = 0; s < mxhash; s++)
		{
			for(int j = 0; j < n; j++)
				pool[i].hash[s] += power[s][j] * (int(inp[j]) - 'a'), pool[i].hash[s] %= mode[s],
				rev[i].hash[s] += power[s][n - 1 - j] * (int(inp[j]) - 'a'), rev[i].hash[s] %= mode[s];
		}
		scanf("%d", &pool[i].num);
		num[i] = pool[i].num;
		bool fl = true;
		for(int j = 0; j < n; j++)
			if(inp[j] != inp[n - 1 - j])
				fl = false;
		if(fl)
			self[i] = true;
	}
	sort(pool, pool + k);
	for(int i = k - 1; i >= 0; i--)
	{
		int nows = pool[i].id; 
		if(have[nows]) 
			continue;
				
		int l = 0, r = k - 1;
		// >=  
		while(l < r)
		{
			int mid = (l + r) / 2;
			if(rev[nows].bjhs(pool[mid]) <= 1)
				r = mid;
			else l = mid + 1; 
		}
		
		if(!pool[l].hseq(rev[nows]) || have[pool[l].id]) 
			continue;
		l = l, r = k - 1;// 
		while(l < r)
		{
			int mid = (l + r) / 2;
			if(pool[mid + 1].hseq(rev[nows]) && !have[pool[mid + 1].id] && mid + 1 != i)
				l = mid + 1;
			else r = mid;
		 } 
		 if(l == i) continue; 
		 if(pool[l].num + num[nows] > 0)
		 	have[nows] = true, have[pool[l].id] = true, ans += pool[l].num + num[nows];
	}
	
	int minj = 0, mxj = 0;//mxj: minj: 
	for(int i = 0; i < k; i++)
	{
		if(!self[i]) continue;
		if(have[i])
			minj = min(minj, num[i]);
		else
			mxj = max(mxj, num[i]);
	}
	ans = max((ans, ans - minj), ans + mxj);
	printf("%d\n", ans);
	return 0;
}