#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll n,i,j,k,hs;
int main()
{
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
		if(s[i]=='Q')
			for(j=i+1;j<n;j++)
				if(s[j]=='A')
					for(k=j+1;k<n;k++)
						if(s[k]=='Q')
							hs++;
	cout<<hs<<"\n";
}