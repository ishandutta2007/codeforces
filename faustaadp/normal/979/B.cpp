#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,d[101010],j,H[101010],MA,cnt;
string s;
int main()
{
 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=3;i++)
	{
		memset(d,0,sizeof(d));
		cin>>s;
		for(j=0;j<s.length();j++)
			d[s[j]]++;
		for(j='a';j<='z';j++)
		{
			if(d[j]+n<=s.length())
				H[i]=max(H[i],d[j]+n);
			else
			if(d[j]==s.length()&&n==1)
				H[i]=max(H[i],(ll)s.length()-1);
			else
				H[i]=max(H[i],(ll)s.length());
		}
		for(j='A';j<='Z';j++)
		{
			if(d[j]+n<=s.length())
				H[i]=max(H[i],d[j]+n);
			else
			if(d[j]==s.length()&&n==1)
				H[i]=max(H[i],(ll)s.length()-1);
			else
				H[i]=max(H[i],(ll)s.length());
		}
		MA=max(MA,H[i]);
	}
	for(i=1;i<=3;i++)
		if(MA==H[i])
			cnt++;
	if(cnt>1)
		cout<<"Draw\n";
	else
	if(MA==H[1])
		cout<<"Kuro\n";
	else
	if(MA==H[2])
		cout<<"Shiro\n";
	else
		cout<<"Katie\n";
}