#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s,S1,S2,S3,Q1,Q2,Q3;
ll n,i,A[101010],B[101010];
int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		ll X=i;
		X%=26;
		Q1+=char(X+'a');
	}
	for(i=0;i<n;i++)
	{
		ll X=i/26;
		X%=26;
		Q2+=char(X+'a');
	}
	for(i=0;i<n;i++)
	{
		ll X=i/(26*26);
		X%=26;
		Q3+=char(X%26+'a');
	}
	cout<<"? "<<Q1<<endl;cin>>S1;
	cout<<"? "<<Q2<<endl;cin>>S2;
	cout<<"? "<<Q3<<endl;cin>>S3;
	for(i=0;i<n;i++)
		A[i]=(S3[i]-'a')*26*26+(S2[i]-'a')*26+(S1[i]-'a');
	cout<<"! ";
	for(i=0;i<n;i++)B[A[i]]=i;
	for(i=0;i<n;i++)
		cout<<s[B[i]];
	cout<<endl;
}