#include<bits/stdc++.h>
using namespace std;

vector<int> v[100010];
set<int> st;

int n,m;
bool inq[100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	inq[1]=true;printf("%d ",1);
	for (int i=0;i<v[1].size();i++)
	{
		int t=v[1][i];
		if (inq[t]) continue;
		st.insert(t);inq[t]=true;
	}
	while (!st.empty())
	{
		int x=*st.begin();st.erase(x);
		printf("%d ",x);
		for (int i=0;i<v[x].size();i++)
		{
			int t=v[x][i];
			if (inq[t]) continue;
			st.insert(t);inq[t]=true;
		}
	}
	puts("");
	return 0;
}