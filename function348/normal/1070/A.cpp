#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
const int N=4000001;
int v[510][5100];
PII q[N];int pre[N],g[N];
int h,t,p,s;
void print(int i)
{
	if (i==0) return;
	print(pre[i]);
	putchar(g[i]+48);
}
int main()
{
	scanf("%d%d",&p,&s);
	if (s<=9&&s%p==0)
	{
		printf("%d\n",s);
		return 0;
	}
	int h=1,t=0;
	for (int i=1;i<=9;i++)
	if (i<=s) 
	{
		q[++t]=MP(i%p,s-i);
		pre[t]=0;g[t]=i;
		v[i%p][s-i]=1;
	}
	int flag=0;
	while (h<=t)
	{
		PII now=q[h];h++;
		for (int i=0;i<=9;i++)
		{
			if (i>now.SC) continue;
			int x=(now.FR*10+i)%p,y=now.SC-i;
			if (v[x][y]) continue;
			v[x][y]=1;
			if (x==0&&y==0)
			{
				flag=1;
				print(h-1);
				printf("%d\n",i);
				break;
			}
			q[++t]=MP(x,y);
			pre[t]=h-1;g[t]=i;
		}
		if (flag) break;
	}
	if (!flag) printf("-1\n");
}