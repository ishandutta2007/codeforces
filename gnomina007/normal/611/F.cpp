#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
long long n, p, a[1000020], c[1000020], d[1000020], b[1000020], i, k, ans, xx, yy, xx1, yy1, kt, h, v, p1, p2, a1, pos1, pos2, pos3, rb, lb, mid, j, sa[1000020], sb[1000020], sd[1000020], sc[1000020], yy2, yy3, pc, m1, m2, m3, m4;
string t;
int main()
{
	p=1000000007;
	cin>>n>>h>>v;
	cin>>t;
	for(i=1; i<999999; i++)
	{
		a[i]=99999999999999999+i;
		b[i]=9999999999999999+i;
		c[i]=9999999999999999+i;
		d[i]=9999999999999999+i;
	}	
	p1=0; 
	p2=0;
	for(i=0; i<n; i++)
	{
		if(t[i]=='U')
		{
			p1++;
		}
		if(t[i]=='D')
		{
			p1--;
		}
		if(t[i]=='L')
		{
			p2++;
		}
		if(t[i]=='R')
		{
			p2--;
		}
		if(p1>0)
		{
			if(c[p1]>999999999999)
			{
				c[p1]=i+1;
				m1=p1;
			}
		}
		if(p1<0)
		{
			if(d[(-1)*p1]>999999999999)
			{
				d[(-1)*p1]=i+1;
				m2=(-1)*p1;
			}
		}
		if(p2>0)
		{
			if(a[p2]>999999999999)
			{
			    a[p2]=i+1;
				m3=p2;
			}
		}
		if(p2<0)
		{
			if(b[(-1)*p2]>999999999999)
			{
				b[(-1)*p2]=i+1;
				m4=(-1)*p2;
			}
		}
	}
	//cout<<p1<<' '<<p2<<endl;
	//cout<<b[1]<<endl;
	if(p1==0)
	{
		if(p2==0)
		{
			if((m1+m2)<h)
			{
				if((m3+m4)<v)
				{
					a1++;
					ans=-1;
				}
			}
		}
	}
	if(a1==0)
	{
	for(i=0; i<500005; i++)
	{
		if(p1>0)
		{
			c[i+p1]=min(c[i]+n, c[i+p1]);
		}
		if(p1<0)
		{
			d[i-p1]=min(d[i]+n, d[i-p1]);
		}
		if(p2>0)
		{
			a[i+p2]=min(a[i]+n, a[i+p2]);
		}
		if(p2<0)
		{
			b[i-p2]=min(b[i]+n, b[i-p2]);
		}
	}
	for(i=1; i<=999989; i++)
	{
		sa[i]=(sa[i-1]+a[i])%p;
		sb[i]=(sb[i-1]+b[i])%p;
		sc[i]=(sc[i-1]+c[i])%p;
		sd[i]=(sd[i-1]+d[i])%p;
	}
	//cout<<c[1]<<endl;
	for(i=0; i<h; i++)
	{
		xx=c[i+1];
		xx1=d[h-i];
		yy=min(xx, xx1);
		rb=0;
		lb=v;
		for(j=0; j<30; j++)
		{
			mid=(rb+lb+j%2)/2;
			if(a[mid+1]>b[v-mid])
			{
				lb=mid;
			}
			else
			{
				rb=mid;
			}
		}
		yy1=mid;
		//cout<<i<<' '<<mid<<' '<<yy<<endl;
		rb=0;
		lb=yy1;
		for(j=0; j<30; j++)
		{
			mid=(rb+lb+j%2)/2;
			if(a[mid+1]>yy)
			{
				lb=mid;
			}
			else
			{
				rb=mid;
			}
		}
		yy2=mid;
		//cout<<i<<' '<<yy2<<endl;
		rb=v;
		lb=yy1;
		for(j=0; j<30; j++)
		{
			mid=(rb+lb+j%2)/2;
			if(b[v-mid]>yy)
			{
				lb=mid;
			}
			else
			{
				rb=mid;
			}
		}
		yy3=mid;
	    ans=(ans+sa[yy2]+(yy3-yy2)*yy+sb[(v-yy3)])%p;
		//cout<<ans<<endl;
	}
	ans=ans%p;
	}
	cout<<ans;
}