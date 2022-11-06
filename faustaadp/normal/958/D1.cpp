#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,I,j;
double A[202020],B[202020],C[202020];
unordered_map<double,ll> me;
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<s.length();j++)
			if(s[j]=='+')
			{
				I=j;
				break;
			}
			else
			{
				A[i]*=10;
				A[i]+=s[j]-'0';
			}
		for(j=I+1;j<s.length();j++)
		{
			if(s[j]==')')
			{
				I=j;
				break;
			}
			else
			{
				B[i]*=10;
				B[i]+=s[j]-'0';
			}
		}
		for(j=I+2;j<s.length();j++)
		{
			C[i]*=10;
			C[i]+=s[j]-'0';
		}
	//	cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<"\n";
		//cout<<(A[i]+B[i])/C[i]<<"\n";
		me[(A[i]+B[i])/C[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		if(i<n)
			cout<<me[(A[i]+B[i])/C[i]]<<" ";
		else
			cout<<me[(A[i]+B[i])/C[i]]<<"\n";
	}
}