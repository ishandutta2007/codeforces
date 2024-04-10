#include<bits/stdc++.h>
using namespace std;

bitset<2010> bs[65536];

vector<int> v[110];

int num[110],n,m;

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
	for (int i=1;i<=n;i++) num[i]=rd();
	int sum=0;
	for (int i=1;i<=n;i++) sum+=num[i];
	bs[0][0]=1;
	for (int i=0;i<(1<<n);i++)
	{
		for (int j=sum/m;j;j--) bs[i][j]=bs[i][j]|bs[i][j*m];
		for (int j=1;j<=n;j++) if (!((1<<(j-1))&i)) bs[i|(1<<(j-1))]|=(bs[i]<<num[j]);
	}
	if (!bs[(1<<n)-1][1]) { puts("NO");return 0; }
	int now1=(1<<n)-1,now2=1;
	int tt=0;
	while (now1>0)
	{
		bool flag=false;
		for (int j=1;j<=n;j++) if ((1<<(j-1))&now1)
		{
			int hh=tt;
			for (int k=now2;k<=sum;k*=m)
			{
				if (k>now2) hh++;
				if (k<num[j]) continue;
				if (!bs[now1][k]) break;
				if (bs[now1^(1<<(j-1))][k-num[j]])
				{
					tt=hh;v[tt].push_back(num[j]);
					now1^=(1<<(j-1));now2=k-num[j];
					flag=true;break;
				}
			}
			if (flag) break;
		}
	}
	puts("YES");
	for (int i=100;~i;i--) if (v[i].size()>1)
	{
		for (int j=0;j<v[i].size();j+=2)
		{
			int h1=v[i][j],h2=v[i][j+1];
			int hh=h1+h2,tt=i;
			printf("%d %d\n",h1,h2);
			while (hh%m==0) hh/=m,tt--;
			v[tt].push_back(hh);
		}
	}
	return 0;
}