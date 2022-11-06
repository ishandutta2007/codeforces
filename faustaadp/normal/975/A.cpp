#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,d[266],j,has;
string s;
unordered_map<string,ll>  me;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		memset(d,0,sizeof(d));
		for(j=0;j<s.length();j++)
			d[s[j]]=1;
		string z;
		for(j='a';j<='z';j++)
			if(d[j])
				z=z+char(j);
		if(me[z]==0)
		{
			me[z]=1;
			has++;
		}
	}
	cout<<has<<"\n";
}