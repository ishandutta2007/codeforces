#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second


int n,m,k;
int lsize,rsize;
int l[205],r[205];
int len[205],str[205][205],p[205];
int nex[205][25];
int gain[205];
ll dp[2][505][205][2][2];
string al="abcdefghijklmnopqrstuvwxyz";
vector<string >pfx;
void pre()
{
	for(int i=0;i<n;i++)
	{
		string s;
		for(int j=0;j<=len[i];j++)
		{
			pfx.pb(s);
			if(j!=len[i]) s.pb(('a'+str[i][j]));
		}
	}
	sort(pfx.begin(),pfx.end());
	pfx.erase(unique(pfx.begin(),pfx.end()),pfx.end());
	int kk = pfx.size();
	for(int i=0;i<kk;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(pfx[i].size() < len[j]) continue;
			bool ok=true;
			for(int a = 0;a < len[j] ;a++)
			{
				if( ('a'+str[j][len[j]-1-a]) != pfx[i][pfx[i].size()-1-a])
				{
					ok=false; break;
				}
			}
			if(ok) gain[i]+=p[j];
		}
		
		for(int j=0;j<m;j++)
		{
			string s = pfx[i]; s.pb('a'+j);
			int x;
			while(1)
			{
				x = lower_bound(pfx.begin(),pfx.end(),s)-pfx.begin();
				if(x < kk && pfx[x] == s) break;
				s = s.substr(1);
			}
			nex[i][j] = x;
		}
	}
}
ll calcl()
{
	memset(dp,0,sizeof(dp));
	//dp1-index
	int cur=0,nxt=1;
	dp[0][0][0][1][0] = 1;
	for(int i=0;i<lsize;i++)
	{
		memset(dp[nxt],0,sizeof(dp[nxt]));
		for(int j=0;j<=k;j++)
		{
			for(int a=0;a<pfx.size();a++)
			{
				if(!dp[cur][j][a][0][1]) goto nxt;
				for(int ch = 0; ch < m; ch++)
				{
					int tugi = nex[a][ch];
					if(j+gain[tugi] > k) continue;
					dp[nxt][j+gain[tugi]][tugi][0][1] = (dp[nxt][j+gain[tugi]][tugi][0][1]+dp[cur][j][a][0][1])%mod;
				}
				nxt:;
				if(!dp[cur][j][a][1][1]) goto nxt2;
				for(int ch = 0; ch <= l[i]; ch++)
				{
					int tugi = nex[a][ch];
					if(j+gain[tugi] > k) continue;
					dp[nxt][j+gain[tugi]][tugi][ch==l[i]?1:0][1] = (dp[nxt][j+gain[tugi]][tugi][ch==l[i]?1:0][1]+dp[cur][j][a][1][1])%mod;
				}
				nxt2:;
				if(!dp[cur][j][a][0][0]) goto nxt3;
				for(int ch = 0; ch < m; ch++)
				{
					int tugi = nex[a][ch];
					if(ch && j+gain[tugi] <= k)
					{
						dp[nxt][j+gain[tugi]][tugi][0][!!ch] = (dp[nxt][j+gain[tugi]][tugi][0][!!ch]+dp[cur][j][a][0][0])%mod;
					}
					else if(!ch)
					{
						dp[nxt][0][0][0][0] = (dp[nxt][0][0][0][0]+dp[cur][j][a][0][0])%mod;
					}
				}
				nxt3:;
				if(!dp[cur][j][a][1][0]) continue;
				for(int ch = 0; ch <= l[i]; ch++)
				{
					int tugi = nex[a][ch];
					if(ch && j+gain[tugi] <= k)
					{
						dp[nxt][j+gain[tugi]][tugi][ch==l[i]?1:0][!!ch] = (dp[nxt][j+gain[tugi]][tugi][ch==l[i]?1:0][!!ch]+dp[cur][j][a][1][0])%mod;
					}
					else if(!ch)
					{
						dp[nxt][0][0][ch==l[i]?1:0][0] = (dp[nxt][0][0][ch==l[i]?1:0][0]+dp[cur][j][a][1][0])%mod;
					}
				}
			}
		}
		swap(cur,nxt);
	}
	ll res = 0LL;
	for(int j=0;j<=k;j++) for(int a=0;a<pfx.size();a++) res = (res+dp[cur][j][a][0][1]+dp[cur][j][a][1][1])%mod;
	return res;
}

ll calcr()
{
	memset(dp,0,sizeof(dp));
	//dp1-index
	int cur=0,nxt=1;
	dp[0][0][0][1][0] = 1;
	for(int i=0;i<rsize;i++)
	{
		memset(dp[nxt],0,sizeof(dp[nxt]));
		for(int j=0;j<=k;j++)
		{
			for(int a=0;a<pfx.size();a++)
			{
				if(!dp[cur][j][a][0][1]) goto nxtt;
				for(int ch = 0; ch < m; ch++)
				{
					int tugi = nex[a][ch];
					if(j+gain[tugi] > k) continue;
					dp[nxt][j+gain[tugi]][tugi][0][1] = (dp[nxt][j+gain[tugi]][tugi][0][1]+dp[cur][j][a][0][1])%mod;
				}
				nxtt:;
				if(!dp[cur][j][a][1][1]) goto nxtt2;
				for(int ch = 0; ch <= r[i]; ch++)
				{
					int tugi = nex[a][ch]; 
					if(j+gain[tugi] > k) continue;
					dp[nxt][j+gain[tugi]][tugi][ch==r[i]?1:0][1] = (dp[nxt][j+gain[tugi]][tugi][ch==r[i]?1:0][1]+dp[cur][j][a][1][1])%mod;
				}
				nxtt2:;
				if(!dp[cur][j][a][0][0]) goto nxtt3;
				for(int ch = 0; ch < m; ch++)
				{
					int tugi = nex[a][ch];
					
					if(ch && j+gain[tugi] <= k)
					{
						dp[nxt][j+gain[tugi]][tugi][0][!!ch] = (dp[nxt][j+gain[tugi]][tugi][0][!!ch]+dp[cur][j][a][0][0])%mod;
					}
					else if(!ch)
					{
						dp[nxt][0][0][0][0] = (dp[nxt][0][0][0][0]+dp[cur][j][a][0][0])%mod;
					}
				}
				nxtt3:;
				if(!dp[cur][j][a][1][0]) continue;
				for(int ch = 0; ch <= r[i]; ch++)
				{
					int tugi = nex[a][ch];
					if(ch && j+gain[tugi] <= k)
					{
						dp[nxt][j+gain[tugi]][tugi][ch==r[i]?1:0][1] = (dp[nxt][j+gain[tugi]][tugi][ch==r[i]?1:0][1]+dp[cur][j][a][1][0])%mod;
					}
					else if(!ch)
					{
						dp[nxt][0][0][ch==r[i]?1:0][0] = (dp[nxt][0][0][ch==r[i]?1:0][0]+dp[cur][j][a][1][0])%mod;
					}
				}
				
			}
		}
		swap(cur,nxt);
	}
	
	ll res = 0LL;
	for(int j=0;j<=k;j++) for(int a=0;a<pfx.size();a++) res = (res+dp[cur][j][a][0][1]+dp[cur][j][a][1][1])%mod;
	return res;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d",&lsize);
	for(int i=0;i<lsize;i++) scanf("%d",&l[i]);
	vector<int>vec; l[lsize-1]--;
	for(int i=lsize-1;i>=0;i--)
	{
		if(l[i] == -1)
		{
			l[i] = m-1; l[i-1]--;
		}
		else
		{
			break;
		}
	}
	for(int i=0;i<lsize;i++) vec.pb(l[i]);
	if(vec.size() == lsize)
	{
		//reverse(vec.begin(),vec.end());
		if(!vec[0])
		{
			lsize--;
			for(int i=0;i<lsize;i++) l[i] = vec[i+1];
		}
		else
		{
			for(int i=0;i<lsize;i++) l[i] = vec[i];
		}
	}
	scanf("%d",&rsize);
	for(int i=0;i<rsize;i++) scanf("%d",&r[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&len[i]);
		for(int j=0;j<len[i];j++)
		{
			scanf("%d",&str[i][j]);
		}
		scanf("%d",&p[i]);
	}
	pre();
	
	printf("%lld\n",(calcr()-calcl()+mod)%mod);
}