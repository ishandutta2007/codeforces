#include<bits/stdc++.h>
using namespace std;
long long n,nn,i,d,r,dd[2000100],rr[2000100],ti,tii,ur,ud;
bool b[2000100];
string s;
int main()
{
	cin>>n;
	cin>>s;
//	s="SSS";
//	n=s.length();
	for(i=0;i<n;i++)
	{
		if(s[i]=='D')
		{
			d++;
			dd[d]=i;
		}
		else
		{
			r++;
			rr[r]=i;
		}
	}
	ti=-1;
	while(d>0&&r>0)
	{
		ti++;
		ti=ti%n;
		if(b[ti]==0)
		{		
			if(s[ti]=='D')
			{
				if(ud==0)
				{
					r--;
					ur++;
				}
				else
				{
					ud--;
					b[ti]=1;
				}
			}
			else
			{
				if(ur==0)
				{
					d--;
					ud++;
				}
				else
				{
					ur--;
					b[ti]=1;
				}
			}	
		}
	}
	//cout<<d<<r<<endl;
	if(d>0)
		cout<<'D'<<endl;
	else
		cout<<'R'<<endl;
	return 0;
}