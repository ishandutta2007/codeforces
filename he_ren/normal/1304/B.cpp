#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

string s[MAXN];
bool vis[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) cin>>s[i];
	
	string ans="", tmp;
	for(int i=1; i<=n; ++i)
	{
		tmp=s[i];
		reverse(tmp.begin(),tmp.end());
		if(tmp==s[i])
		{
			vis[i]=1;
			ans=s[i];
			break;
		}
	}
	for(int i=1; i<=n; ++i) if(!vis[i])
	{
		tmp=s[i];
		reverse(tmp.begin(),tmp.end());
		for(int j=i+1; j<=n; ++j) if(!vis[j])
			if(tmp==s[j])
			{
				ans = s[i] + ans + s[j];
				vis[i]=vis[j]=1;
				break;
			}
	}
	
	cout<<ans.size()<<endl<<ans;
	return 0;
}