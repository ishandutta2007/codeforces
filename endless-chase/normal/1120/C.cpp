#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a,b;
string s;
struct SAM
{
	int edge[20002][26],len[22222],fa[22222],cnt,last;
	void extend(int i,char c)
	{
		int r=++cnt,p=last;
		len[r]=i+1;
		fa[r]=1;
		while(p>0 && !edge[p][c-'a']) 
		{
			edge[p][c-'a']=r;
			p=fa[p];
		}
		if (p)
		{
			int q=edge[p][c-'a'];
			if (len[q]==len[p]+1) fa[r]=q;
			else
			{
				int qq=++cnt;
				for (int j=0;j<26;j++) edge[qq][j]=edge[q][j];
				len[qq]=len[p]+1;
				fa[qq]=fa[q];
				fa[q]=qq;
				fa[r]=qq;
				while(p && edge[p][c-'a']==q) 
				{
					edge[p][c-'a']=qq;
					p=fa[p];
				}
			}
		}
		last=r;
	}
	void Init()
	{
		last=1;cnt=1;
	}
}sam;
bool f[5555][5555];
int dp[5555];
int main()
{
	cin>>n>>a>>b;
	cin>>s;
	sam.Init();
	for (int i=0;i<n;i++)
	{
		sam.extend(i,s[i]);
		int pos=1;
		for (int j=i+1;j<n;j++)
		{
			if (!sam.edge[pos][s[j]-'a']) break;
			pos=sam.edge[pos][s[j]-'a'];
			f[i][j]=1;
		}
	}
	dp[0]=a;
	for (int i=1;i<n;i++)
	{
		dp[i]=dp[i-1]+a;
		for (int j=0;j<i;j++)
		{
			if (f[j][i]) dp[i]=min(dp[i],dp[j]+b);
		}
	}
	printf("%d\n",dp[n-1]);
	return Accepted;
}