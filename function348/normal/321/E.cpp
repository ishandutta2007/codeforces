#include<cstdio>
#include<iostream>
using namespace std;
const int N=4010;
int n,k;
int s[N][N];
int top;int stk[N],id[N];
int f[N],g[N],h[N];
int calc(int i,int j)
{
	return f[j]+s[i][i]-s[i][j]-s[j][i]+s[j][j];
}
inline void read(int &x)
{
    bool fu=0;char c;
    for(c=getchar();!(c>='0'&&c<='9');c=getchar());
    if(c=='-')fu=1,c=getchar();
    for(x=0;c>32;c=getchar())x=x*10+c-'0';
    if(fu)x=-x;
};
int main()
{
//	freopen("data.in","r",stdin);
//	cout<<"Ok\n";
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		read(s[i][j]);
		s[i][j]+=s[i][j-1];
	}
//	cout<<"Ok\n";
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		s[i][j]+=s[i-1][j];
//	cout<<"Ok\n";
	for (int i=1;i<=n;i++) f[i]=1000000000;
	for (int j=1;j<=k;j++)
	{
		top=0;stk[0]=0;
		for (int i=1;i<=n;i++)
		{
			g[i]=max(g[i],g[i-1]);
			h[i]=calc(i,g[i]);
			while (calc(stk[top],i)<calc(stk[top],id[top])&&stk[top]>i) top--;
			int l=max(stk[top],i+1),r=n+1;
			while (l<r)
			{
				int mid=(l+r)>>1;
				if (calc(mid,i)<calc(mid,id[top])) r=mid;else l=mid+1;
			}
			if (r<=n)
			{
				top++;g[l]=i;
				stk[top]=l;id[top]=i;
			}
		}
		for (int i=1;i<=n;i++) f[i]=h[i],g[i]=h[i]=0;
	}
	printf("%d\n",f[n]/2);
	return 0;
}