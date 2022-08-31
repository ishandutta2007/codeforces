#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string S,Q,str[MAXN];
bool revealed[26],valid[26],dd[26];
int main()
{
	scanf("%d",&n);
	cin>>S;
	memset(revealed,false,sizeof(revealed));
	for(int i=0;i<n;i++)
		if(S[i]>='a'&&S[i]<='z') revealed[S[i]-'a']=true;
	scanf("%d",&m);
	int t=0;
	for(int i=0;i<m;i++)
	{
		cin>>Q;
		bool f=true;
		for(int j=0;j<n;j++)
		{
			if(S[j]=='*'&&revealed[Q[j]-'a']||(S[j]!='*'&&S[j]!=Q[j]))
			{
				f=false;
				break;
			}
		}
		if(f) str[t++]=Q;
	}
	int cnt=0;
	memset(valid,true,sizeof(valid));
	for(int i=0;i<26;i++)
		if(revealed[i]) valid[i]=false;
	for(int i=0;i<t;i++)
	{
		memset(dd,false,sizeof(dd));
		for(int j=0;j<n;j++)
			if(S[j]=='*') dd[str[i][j]-'a']=true;
		for(int j=0;j<26;j++) valid[j]=valid[j]&&dd[j];
	}
	for(int i=0;i<26;i++)
		if(valid[i]) cnt++;
	printf("%d\n",cnt);
	return 0;
}