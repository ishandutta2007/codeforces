#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
string s;
char s1[2000005];
long long i, j, x, ans, cur, n, k, m, a[2000005], pos[26], p[2000005], lb, rb, och[2000005], ps2[26], pq=1000000007;
int main()
{
	cin>>n>>k;
	cin>>s;
	m=s.length();
	for(i=0; i<m; i++)
	{
		s1[i]=s[i];
		p[i]=pos[s[i]-'a'];
		pos[s[i]-'a']=i+1;
	}
	for(i=0; i<k; i++)
	{
		for(j=0; j<k; j++)
		{
			if(pos[i]>pos[j])
			{
				ps2[i]++;
			}
			if(pos[i]==pos[j])
			{
				if(pos[i]==0)
				{
					if(i>j)
					{
						ps2[i]++;
					}
				}
			}
		}
	}
	for(i=0; i<k; i++)
	{
		och[ps2[i]]=i;
	}
	lb=0; 
	rb=k;
	//cout<<och[0]<<' '<<och[1]<<' '<<och[2]<<endl;
	for(i=0; i<n; i++)
	{
	//	cout<<och[lb]<<endl;
		s1[m+i]=och[lb]+'a';
		//cout<<s1[m+i]<<endl;
		p[m+i]=pos[s1[m+i]-'a'];
		pos[s1[m+i]-'a']=m+i+1;
		och[rb]=och[lb];
		rb++;
		lb++;
	}
	a[0]=0;
	a[1]=1;
	for(i=0; i<8; i++)
	{
		//cout<<p[i]<<' ';
	}
	for(i=0; i<n+m; i++)
	{
		a[i+2]=(2*a[i+1]-a[p[i]]+pq)%pq;
	}
	//cout<<s1[4]<<' '<<s1[5]<<' '<<s1[6]<<endl;
	cout<<(a[n+m+1]+pq)%pq;

}