#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s1,s2,hs;
ll n1,n2,i,a[1010],j,bo;
bool rmt()
{
	string z1,z2;
	ll ii,jj;
	for(ii='0';ii<='9';ii++)
	{
		//cout<<a[ii]
		for(jj=1+(ii==j);jj<=a[ii];jj++)
		{
		//	cout<<"sd";
			z1+=char(ii);
		}
	}
	for(ii=i+1;ii<n2;ii++)
		z2+=s2[ii];
	sort(z1.begin(),z1.begin());
//	cout<<"ad";
//	cout<<z1<<" "<<z2<<"\n";
	return z1<=z2;
}
int main()
{
	cin>>s1>>s2;
	n1=s1.length();
	n2=s2.length();
	if(n1<n2)
	{
		sort(s1.begin(),s1.end());
		reverse(s1.begin(),s1.end());
		cout<<s1<<"\n";
		return 0;
	}
	for(i=0;i<n1;i++)
		a[s1[i]]++;
//	cout<<"as";
	for(i=0;i<n2;i++)
	{
		//cout<<i<<"\n";
		for(j='9';j>='0';j--)
		{
			if(i==0&&j=='0')
				continue;
			if(a[j]>0&&(j<s2[i]||bo||(rmt()&&j<=s2[i])))
			{
			//	cout<<"d";
				if(s2[i]!=char(j))
					bo=1;
				a[j]--;
				hs+=char(j);
//				cout<<hs<<"\n";
				break;
			}
		}
	}
	cout<<hs<<"\n";
}