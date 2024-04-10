#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		string S="";
		for(int j=0;j<str[i].size();j++)
		{
			if(str[i][j]=='u')
			{
				S+="oo";
				continue;
			}
			if(str[i][j]=='k')
			{
				int t=j+1;
				while(t<str[i].size()&&str[i][t]=='k') t++;
				if(t==str[i].size()||str[i][t]!='h')
				{
					S+=str[i].substr(j,t-j);
					j=t-1;
					continue;
				}
				else {S+="h"; j=t; continue;}
			}
			else S+=str[i][j];
		}
		str[i]=S;
	}
	sort(str,str+n);
	int cnt=1;
	for(int i=1;i<n;i++)
		if(str[i]!=str[i-1]) cnt++;
	printf("%d\n",cnt);
	return 0;
}