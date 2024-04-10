#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> v[1010];

int h1[1010],h2[1010],n,m,tt;
char s[1010],s1[1010],bo[1010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool gao()
{
	int t1=0,t2=0;
	for (int i=1;i<=n;i++) if (s[i]=='(') h1[++t1]=i;
	for (int i=n;i;i--) if (s[i]==')') h2[++t2]=i;
	if (!t1||!t2) return false;
	int id=0;
	for (int i=1;i<=min(t1,t2);i++) if (h1[i]<h2[i]) id=i;
	if (!id) return false;
	tt++;
	for (int i=1;i<=id;i++) v[tt].push_back(h1[i]);
	for (int i=id;i;i--) v[tt].push_back(h2[i]);
	return false;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	tt=0;
	while (gao());
	printf("%d\n",tt);
	for (int i=1;i<=tt;i++)
	{
		printf("%d\n",v[i].size());
		for (int t:v[i]) printf("%d ",t);
		puts("");
	}
	return 0;
}