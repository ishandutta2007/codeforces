#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll b[1010],n,i,d[1010];
string s;
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	b['a']=1;
	b['i']=1;
	b['u']=1;
	b['e']=1;
	b['o']=1;
	b['y']=1;
	cin>>n;
	cin>>s;
	for(i=1;i<n;i++)
	{
		if(b[s[i]]==1&&b[s[i-1]]==1)
			d[i]=1;
	}
	for(i=0;i<n;i++)
		if(d[i]==0)
			cout<<s[i];
	cout<<"\n";
}