#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#define fr first
#define sc second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
const int N=4101;
int n,m,k,cas;
int a[30],f[200020];
char s[200020];
int main()
{
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d%d",&n,&m,&k);
		scanf("%s",s);
		for (int i=0;i<26;i++) a[i]=0;
		for (int i=0;i<k;i++) a[s[i]-'A']++;
		for (int i=0;i<=k;i++) f[i]=0;
		f[0]=1;
		for (int i=0;i<26;i++)
		for (int j=k;j>=a[i];j--)
			f[j]+=f[j-a[i]];
		int flag=0;
		for (int i=n;i<=k-m;i++)
		if (f[i]>0) 
		{
			flag=1;
			puts("0\n");
			break;
		}
		if (flag) continue;
		int ans=n*m;
		for (int i=0;i<26;i++)
		if (k-a[i]<n+m)
		{
			for (int j=a[i];j<=k;j++) f[j]-=f[j-a[i]];
			for (int j=n;j>=n-a[i]&&j>=0;j--)
			if (f[j]>0&&m+j-k+a[i]>0)
			{
				ans=min(ans,(n-j)*(m+j-(k-a[i])));
			}
			for (int j=k;j>=a[i];j--) f[j]+=f[j-a[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}