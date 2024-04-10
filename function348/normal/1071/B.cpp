#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
const int N=4010,p=1000000007;
typedef long long LL;
typedef pair<int,int> PII;
char a[N][N];
int f[N][N];
PII b[N],c[N];
int n,m,mx,k;
int main()
{
//	freopen("dividing.in","r",stdin);
//	freopen("dividing.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		char ch;
		while ((ch=getchar())<=32);
		a[i][j]=ch;
	}
	if (k>=2*n-1) 
	{
		for (int i=1;i<=n*2-1;i++) putchar('a');
		puts("");
		return 0;
	}
	f[1][1]=k;
	if (a[1][1]!='a') f[1][1]--;
	if (f[1][1]>=0) mx=max(mx,1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (i!=1||j!=1)
	{
		f[i][j]=-10000;
		if (i>1) upmax(f[i][j],f[i-1][j]);
		if (j>1) upmax(f[i][j],f[i][j-1]);
		if (a[i][j]!='a') f[i][j]--;
		if (f[i][j]>=0) mx=max(mx,i+j-1);
//		printf("%d%c",f[i][j],j<n?' ':'\n');
	}
	for (int i=1;i<=mx;i++) putchar('a');
	int cnt=0,len=0;
	if (mx<=n)
	{
		for (int i=1;i<=mx;i++)
		if (f[i][mx+1-i]>=0) b[++cnt]=MP(i,mx+1-i);
	}
	else
	{
		for (int i=mx-n+1;i<=n;i++)
		if (f[i][mx+1-i]>=0) b[++cnt]=MP(i,mx+1-i);
	}
	if (mx==0)
	{
		mx++;
		putchar(a[1][1]);
		cnt=1;b[1]=MP(1,1);
	}
	for (int ii=mx+1;ii<=2*n-1;ii++)
	{
		char ch='z';
		for (int j=1;j<=cnt;j++)
		{
			if (b[j].FR<n) ch=min(ch,a[b[j].FR+1][b[j].SC]);
			if (b[j].SC<n) ch=min(ch,a[b[j].FR][b[j].SC+1]);
		}
		putchar(ch);
		len=0;
		for (int j=1;j<=cnt;j++)
		{
			if (b[j].FR<n&&a[b[j].FR+1][b[j].SC]==ch) c[++len]=MP(b[j].FR+1,b[j].SC);
			if (b[j].SC<n&&a[b[j].FR][b[j].SC+1]==ch) c[++len]=MP(b[j].FR,b[j].SC+1);
		}
		sort(c+1,c+1+len);
		cnt=1;b[1]=c[1];
		for (int j=2;j<=len;j++) 
		if (c[j]!=c[j-1]) b[++cnt]=c[j];
	}
	cout<<endl;
	return 0;
}

/*
   f[i][j] > j < (i-1-c[i-1]+j)
   */