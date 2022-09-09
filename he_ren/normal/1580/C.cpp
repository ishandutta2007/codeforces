#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int B = 3e2;
const int MAXB = B + 5;

int a[MAXN], b[MAXN];
int val[MAXB][MAXB], res1[MAXM], res2[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	
	static int lst[MAXN];
	for(int i=1; i<=m; ++i)
	{
		int oper, k;
		scanf("%d%d",&oper,&k);
		if(a[k] + b[k] > B)
		{
			if(oper == 1) lst[k] = i;
			else
			{
				int t = min(a[k] + b[k], 2 * m);
				for(int j=lst[k]; j<i; j+=t)
				{
					int l = j + a[k], r = min(l + b[k], i);
					if(l >= r) continue;
					++res1[l]; --res1[r];
				}
				lst[k] = 0;
			}
		}
		else
		{
			int t = a[k] + b[k], pos;
			if(oper == 1) lst[k] = pos = i + a[k];
			else pos = lst[k];
			
			int dif = oper == 1? 1: -1;
			for(int j=0; j<b[k]; ++j)
				val[t][(pos+j) % t] += dif;
			if(oper == 2) lst[k] = 0;
		}
		
		for(int j=1; j<=B; ++j)
			res2[i] += val[j][i % j];
	}
	
	for(int k=1; k<=n; ++k)
		if(a[k] + b[k] > B && lst[k])
		{
			int t = min(a[k] + b[k], 2 * m);
			for(int j=lst[k]; j<=m; j+=t)
			{
				int l = j + a[k], r = min(l + b[k], m+1);
				if(l >= r) continue;
				++res1[l]; --res1[r];
			}
		}
	
	for(int i=1; i<=m; ++i)
		res1[i] += res1[i-1];
	
	for(int i=1; i<=m; ++i)
		printf("%d\n",res1[i] + res2[i]);
	return 0;
}