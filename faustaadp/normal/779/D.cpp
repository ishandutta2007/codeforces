#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a[300000],l,r,c,n2,hs;
bool b;
string s1,s2;
bool rmtb(string sr)
{
	long long i2,ta;
	ta=0;
	for(i2=0;i2<n;i2++)
	{
		if(sr[i2]==s2[ta])
		{
			ta++;
		}
	}
	if(ta<n2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
bool rmta(long long rc)
{
	string st;
	st=s1;
	long long ii;
	for(ii=1;ii<=rc;ii++)
	{
		st.replace(a[ii]-1,1,"0");	
	}	
	return rmtb(st);
}
int main()
{
	cin>>s1;
	cin>>s2;
	n=s1.length();
	n2=s2.length();
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	l=0;
	r=n;
	while(l<=r)
	{
		c=(l+r)/2;
		b=rmta(c);
		if(b)
		{
			if(c<n)
			{
				if(rmta(c+1)==0)
				{
					hs=c;
					break;
				}
				else
				{
					l=c+1;
				}
			}
			else
			{
				l=c+1;
			}
		}
		else
		{
			r=c-1;
		}
	}
	cout<<hs<<endl;
}