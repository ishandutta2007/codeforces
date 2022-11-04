#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef double db;

const int MAXN = 500005;

struct Set
{
	priority_queue<pair<db,int> > Q,rQ;
	
	void insert(pair<db,int> a)
	{
		Q.push(a);
	}
	
	void erase(pair<db,int> a)
	{
		rQ.push(a);
	}
	
	pair<db,int> MAX()
	{
		while (!rQ.empty() && Q.top() == rQ.top())
		{
			Q.pop();
			rQ.pop();
		}
		return Q.top();
	}
}S;

int n,k,tot;

db ans;
db sum[MAXN];
db f[MAXN];
db pr[MAXN];
db sf[MAXN];

vector<db> val[MAXN];
map<pair<int,int>,vector<db> > A;

int main()
{
	scanf("%d%d",&n,&k);
	for (int x,y,i = 1;i <= n;i++)
	{
		scanf("%d%d",&x,&y);
		int g = __gcd(abs(x),abs(y));
		db len = sqrt((db)x * x + (db)y * y);
		if (!x && !y)
			continue;
		A[make_pair(x / g,y / g)].push_back(len);
	}
	for (map<pair<int,int>,vector<db> >::iterator it = A.begin();it != A.end();it++)
	{
		vector<db> cur = it->second;
		sort(cur.begin(),cur.end());
		sum[0] = 0;
		for (int j = 1;j <= cur.size();j++)
			sum[j] = sum[j - 1] + cur[j - 1];
		pr[0] = 0;
		for (int j = 1;j <= cur.size();j++)
			pr[j] = pr[j - 1] - sum[j - 1] + cur[j - 1] * (j - 1);
		sf[cur.size() + 1] = 0;
		for (int j = cur.size();j >= 1;j--)
			sf[j] = sf[j + 1] - cur[j - 1] * (cur.size() - j) + sum[cur.size()] - sum[j];
		for (int j = 0;j <= cur.size();j++)
		{
			int out = k - j;
			int pre = (j > out ? (j - out) / 2 : 0);
			f[j] = (sum[pre] + sum[cur.size()] - sum[cur.size() - j + pre]) * out + pr[pre] + sf[cur.size() - j + pre + 1] - sum[pre] * (j - pre) + (sum[cur.size()] - sum[cur.size() - j + pre]) * pre;
		}
		for (int j = cur.size();j >= 1;j--)
			f[j] -= f[j - 1];
		tot++;
		for (int j = 1;j <= cur.size();j++)
			val[tot].push_back(f[j]);
		reverse(val[tot].begin(),val[tot].end());
	}
	for (int i = 1;i <= tot;i++)
		S.insert(make_pair(val[i].back(),i));
	for (int i = 1;i < k;i++)
	{
		int top = S.MAX().second;
		S.erase(S.MAX());
		ans += val[top].back();
		val[top].pop_back();
		if (val[top].size())
			S.insert(make_pair(val[top].back(),top));
	}
	int top = S.MAX().second;
	ans += max(0.,val[top].back());
	printf("%.6lf\n",ans);
	return 0;
}