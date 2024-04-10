#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
int t, s1, s2, i, j, sl, sum[105], kz, sett, kl, ames;
char s[105][105];
int main()
{
	cin>>t;
	for(i=1; i<=t; i++)
	{
		for(j=1; j<=12; j++)
		{
			cin>>s[i][j];
		}
	}
	for(i=1; i<=t; i++)
	{
		for(j=1; j<=12; j++)
		{
			if((12%j)==0)
			{
				for(kz=1; kz<=12/j; kz++)
				{
					for(kl=1; kl<=j; kl++)
					{
						if(s[i][(kl-1)*(12/j)+kz]=='O')
						{
							ames++;
						}
					}
					if(ames==0)
					{
						sett++;
					}
					ames=0;
				}
				if(sett>0)
				{
					sl++;
				}
				sett=0;
			}
		}
		cout<<sl<<' ';
		for(j=1; j<=12; j++)
		{
			if(12%j==0)
			{
				for(kz=1; kz<=12/j; kz++)
				{
					for(kl=1; kl<=j; kl++)
					{
						if(s[i][(kl-1)*(12/j)+kz]=='O')
						{
							ames++;
						}
					}
					if(ames==0)
					{
						sett++;
					}
					ames=0;
				}
				if(sett>0)
				{
					cout<<j<<'x'<<12/j<<' ';
				}
				sett=0;
			}
		}
		cout<<endl;
		sl=0;
	}




}