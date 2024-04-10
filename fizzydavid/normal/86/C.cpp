//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1000000009;
#define getnum(x) (x=='A'?0:(x=='C'?1:(x=='G'?2:3)))
const char acgt[4]={'A','C','G','T'};
struct ACautomaton
{
	int go[999][4],tot,fail[999],dis[999],fdis[999];
	ll dp[999][11],ndp[999][11];
	bool end[999];
	string s[999];
	void init()
	{
		memset(go,-1,sizeof(go));
		memset(fail,-1,sizeof(fail));
		memset(dp,0,sizeof(dp));
		memset(ndp,0,sizeof(ndp));
		memset(dis,0,sizeof(dis));
		s[0]="";
		tot=1;
	}
	ACautomaton(){init();}
	int get(string s)
	{
		int p=0;
		for(int i=0;i<s.size()&&p!=-1;i++)p=go[p][getnum(s[i])];
		return p;
	}
	bool getend(string s)
	{
		int p=get(s);
		if(p==-1)return 0;else return end[p];
	}
	void insert(string S)
	{
		int p=0;
		for(int i=0;i<S.size();i++)
		{
			int c=getnum(S[i]);
			if(go[p][c]==-1)
			{
				s[tot]=s[p]+S[i];
				go[p][c]=tot++;
				dis[go[p][c]]=dis[p]+1;
			}
			p=go[p][c];
		}
		end[p]=1;
	}
	void build()
	{
		queue<int>q;
		q.push(0);
		fail[0]=-1;
		while(!q.empty())
		{
			int u=q.front();
			if(end[u])fdis[u]=dis[u];else fdis[u]=fdis[fail[u]];
			q.pop();
			for(int i=0;i<4;i++)
			{
				if(go[u][i]!=-1)
				{
					q.push(go[u][i]);
					int p=fail[u];
					while(p!=-1&&go[p][i]==-1)p=fail[p];
					fail[go[u][i]]=(p==-1?0:go[p][i]);
				}else go[u][i]=(u==0?0:go[fail[u]][i]);
			}
		}
	}
	ll DP(int n)
	{
		for(int i=0;i<n;i++)
		{
			if(i==0)dp[0][0]=1;else dp[0][0]=0;
			for(int j=1;j<tot;j++)for(int k=0;k<=dis[j];k++)dp[j][k]=ndp[j][k],ndp[j][k]=0;
			for(int j=0;j<tot;j++)
			{
				for(int k=0;k<=dis[j];k++)
				{
					if(dp[j][k]==0)continue;
					for(int t=0;t<4;t++)
					{
						int nxt=go[j][t];
						if(nxt==-1)continue;
						if(fdis[nxt]>=k+1)
						{
							ndp[nxt][0]+=dp[j][k];if(ndp[nxt][0]>=mod)ndp[nxt][0]-=mod;
						}
						else
						{
							ndp[nxt][k+1]+=dp[j][k];if(ndp[nxt][k+1]>=mod)ndp[nxt][k+1]-=mod;
						}
					}
				}
			}
		}
		ll ans=0;
		for(int j=1;j<tot;j++)
		{
			ans+=ndp[j][0];
			if(ans>=mod)ans-=mod;
		}
		return ans;
	}
}ac;
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		string s;
		cin>>s;
		ac.insert(s);
	}
	ac.build();
	cout<<ac.DP(n)<<endl;
	return 0;
}