#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e6;

int n, m, q, p[sz], rnk[sz];
bool dif[sz];
void compress(int i)
{
	if(p[i]!=i)
	{
		compress(p[i]);
		dif[i] = dif[i]!=dif[p[i]];
		p[i] = p[p[i]];
	}
}
bool uni(int i, int j, int t)
{
	compress(i);
	compress(j);
	//printf("%d %d\n",p[i],p[j]);
	if(p[i]==p[j])
	{
		//printf("%d %d %d\n",dif[i],dif[j],t);
		return (dif[i]==dif[j])==(t==1);
	}
	else
	{
		bool d = dif[i]!=dif[j];
		i = p[i];
		j = p[j];
		if(rnk[i]<rnk[j])
		{
			p[i] = j;
			dif[i] = (t==2)!=d;
		}
		else if(rnk[j]<rnk[i])
		{
			p[j] = i;
			dif[j] = (t==2)!=d;
		}
		else
		{
			p[j] = i;
			rnk[i]++;
			dif[j] = (t==2)!=d;
		}
		return true;
	}
}

int relation(int i,int j)
{
	compress(i);
	compress(j);
	if(p[i]!=p[j])
		return 3;
	else if(dif[i]==dif[j])
		return 1;
	else
		return 2;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	rep(i,0,n)
	{
		p[i] = i;
		rnk[i] = 0;
		dif[i] = false;
	}
	int k=0;
	unordered_map<string,int> id;
	string s1, s2;
	rep(i,0,n)
	{
		cin >> s1;
		id[s1] = k;
		k++;
	}
	rep(i,0,m)
	{
		int t;
		cin >> t;
		cin >> s1;
		cin >> s2;
		if(uni(id[s1],id[s2],t))
			printf("YES\n");
		else
			printf("NO\n");
	}
	rep(i,0,q)
	{
		cin >> s1;
		cin >> s2;
		printf("%d\n",relation(id[s1],id[s2]));
	}
}