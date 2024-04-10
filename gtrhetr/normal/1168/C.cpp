#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<pii> v[300010];

int d[40][40];
int num[300010],n,m;
bool ans[300010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void printyes() { putchar('S');putchar('h');putchar('i');putchar('\n'); }
inline void printno() { putchar('F');putchar('o');putchar('u');putchar('\n'); }

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=20;i++) for (int j=1;j<=20;j++) d[i][j]=n+1;
	for (int i=1;i<=20;i++) d[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		v[x].push_back(pii(y,i));
	}
	for (int i=n;i;i--)
	{
		for (int j=1;j<=20;j++) for (int k=1;k<=20;k++) if (((1<<(j-1))&num[i])&&((1<<(k-1))&num[i])) d[j][k]=min(d[j][k],i);
		for (int j=1;j<=20;j++) if (!((1<<(j-1))&num[i]))
		{
			int mn=n+1;
			for (int k=1;k<=20;k++) if ((1<<(k-1))&num[i]) mn=min(mn,d[k][j]);
			for (int k=1;k<=20;k++) if ((1<<(k-1))&num[i]) d[k][j]=mn;
		}
		for (int j=0;j<v[i].size();j++)
		{
			pii hh=v[i][j];
			int y=hh.first,id=hh.second;
			for (int k=1;k<=20;k++) for (int l=1;l<=20;l++) if (((1<<(k-1))&num[i])&&((1<<(l-1))&num[y])&&d[k][l]<=y) { ans[id]=true;break; }
		}
	}
	for (int i=1;i<=m;i++) if (ans[i]) printyes();else printno();
	return 0;
}