#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=1010,L=N*30,mo=1000000007;
char s[N],t1[N],t2[N];
int num,n,m,d;
int ch[L][10];int ed[L],g[L];
int f[60][L][2][2][2];
queue<int> Q;
void add(int &a,int b) { a=(a+b)%mo;}
void calc(int i,int j,int b1,int b2,int b3,int x)
{
	if (x==0) return;
//	printf("Now:%d %d %d %d %d %d\n",i,j,b1,b2,b3,x);
	int l=0,r=9;
	if (b1) l=t1[i+1];
	if (b2) r=t2[i+1];
	for (int c=l;c<=r;c++)
	{
		int p=j;
		while (!ch[p][c]&&p) p=g[p];
		if (ch[p][c]) p=ch[p][c];
		int bb1=b1,bb2=b2,bb3=b3;
		if (c>t1[i+1]) bb1=0;
		if (c<t2[i+1]) bb2=0;
		if (ed[p]) bb3=1;
		add(f[i+1][p][bb1][bb2][bb3],x);
	}
}
int main()
{
	scanf("%s",s+1);
	scanf("%s",t1+1);
	scanf("%s",t2+1);
	d=strlen(t1+1);
	n=strlen(s+1);m=d/2;
	for (int i=1;i<=n-m+1;i++)
	{
		int p=0;
		for (int j=i;j<=i+m-1;j++)
		{
			if (!ch[p][s[j]-'0']) ch[p][s[j]-'0']=++num;
			p=ch[p][s[j]-'0'];
		}
		ed[p]=1;
	}
	for (int i=0;i<=9;i++) 
	if (ch[0][i]) Q.push(ch[0][i]);
	while (!Q.empty())
	{
		int p=Q.front();Q.pop();
		for (int i=0;i<=9;i++)
		if (ch[p][i]) 
		{
			int q=ch[p][i];
			Q.push(q);
			int t=g[p];
			while (!ch[t][i]&&t) t=g[t];
			if (ch[t][i]) t=ch[t][i];
			g[q]=t;
		}
	}
	
	
	for (int i=1;i<=d;i++) t1[i]-='0';
	for (int i=1;i<=d;i++) t2[i]-='0';
	f[0][0][1][1][0]=1;
	for (int i=0;i<d;i++)
	for (int j=0;j<=num;j++)
	for (int b1=0;b1<=1;b1++)
	for (int b2=0;b2<=1;b2++)
	for (int b3=0;b3<=1;b3++)
		calc(i,j,b1,b2,b3,f[i][j][b1][b2][b3]);
	
	int ans=0;
	for (int j=0;j<=num;j++)
	for (int b1=0;b1<=1;b1++)
	for (int b2=0;b2<=1;b2++)
		add(ans,f[d][j][b1][b2][1]);
	printf("%d\n",ans);
	return 0;
}