#include<bits/stdc++.h>
using namespace std;
int d[1010][1010],n,m,i,j,l[1010],r[1010],rj;
char a[1010][1010];
bool b;
int rmt(int ra,int rm)
{
	if(d[ra][rm]==0)
	{
		int ths=0;
		if(rm==rj)
		{
			if(ra==0)
			{
				ths=r[rj];
			}
			else
			{
				ths=m-l[rj]+1;
			}
		}
		else
		{
			if(ra==0)
			{
				ths=min(r[rm]*2+1+rmt(0,rm-1),2+m+rmt(1,rm-1));
			}
			else
			{
				ths=min((m-l[rm]+1)*2+1+rmt(1,rm-1),2+m+rmt(0,rm-1));
			}
		}
//		cout<<ra<<" "<<rm<<" "<<ths<<endl;
		d[ra][rm]=ths;
	}
	return d[ra][rm];
}
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=m+1;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		b=0;
		l[i]=m+1;
		r[i]=0;
		for(j=0;j<=m+1;j++)
		{
			if(a[i][j]=='1')
			{
				if(b==0)
				{
					b=1;
					l[i]=j;
				}
				r[i]=j;
			}
		}
	//	cout<<l[i]<<r[i]<<endl;
	}
	rj=n;
	for(i=n;i>=1;i--)
	{
		if(l[i]!=m+1||r[i]!=0)
			rj=i;
	}
//	cout<<rj<<endl;
	cout<<rmt(0,n)<<endl;
}