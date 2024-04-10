#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
#define maxn 100005
using namespace std;
int n, m;
int tp[maxn]; 
vector<int> nm[maxn];
int l[maxn];	
bool flag = 1;
int q[maxn], fr, ed;
bool inq[maxn];
void set(int a, int b)
{
//	cout<<"SET"<<a<<" "<<b<<endl;
	if(tp[a] != -1 && tp[a] != b) 
		flag = 0;	
	tp[a] = b;
	if(!inq[a]) 
		inq[a] = 1, q[ed++] = a;
}
vector<int> in[maxn], out[maxn];

// out[i] = j : i' j 
int main()
{
	memset(tp, -1, sizeof(tp));
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &l[i]);
		for(int j = 0; j < l[i]; j++)
		{
			int num;
			scanf("%d", &num);
			nm[i].push_back(num);
		}
	}

	for(int i = 0; i < n - 1; i++)
	{
	//	cout<<"CHECK"<<i<<endl;
		int fdf = maxn;
		for(int j = 0; j < min(l[i], l[i + 1]); j++)
			if(nm[i][j] != nm[i + 1][j])
			{
				fdf = j;
				break;
			}
		
		if(fdf == maxn) 
		{
			if(l[i] > l[i + 1]) 
				flag = 0;
		}
		else 
		{
			int n1 = nm[i][fdf], n2 = nm[i + 1][fdf];
			if(n1 < n2)
				out[n2].push_back(n1), 
				in[n1].push_back(n2);
			//	cout<<"IN"<<n1<<" "<<n2<<endl;
			else
				set(n2, 0), set(n1, 1);
		}
	}
	if(!flag)
	{
		printf("No\n");
		return 0;
	}
//	cout<<ed<<endl;
//	cout<<fr<<" "<<ed<<endl;
	while(fr < ed)
	{
		if(!flag)
		{
			printf("No\n");
			return 0;
		}
	//	cout<<"NS"<<q[fr]<<" "<<tp[q[fr]]<<" "<<in[q[fr]].size()<<endl;
		if(tp[q[fr]])
			for(int i = 0; i < out[q[fr]].size(); i++)
				set(out[q[fr]][i], 1);
		else
			for(int i = 0; i < in[q[fr]].size(); i++)
				set(in[q[fr]][i], 0);
		fr++;
	}
	if(!flag)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	int ans = 0;
	for(int i = 1; i <= m; i++)
		if(tp[i] == 1)
			ans++;
	printf("%d\n", ans);
	for(int i = 1; i <= m; i++)
		if(tp[i] == 1)
			printf("%d ", i); 
	return 0;
}