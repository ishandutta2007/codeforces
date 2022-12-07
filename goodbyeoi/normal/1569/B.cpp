//AFO countdown:11 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=55;
int n,ans[M][M];
string s;
vector<int>v1,v2;

signed main()
{
	WT
	{
		cin>>n>>s;v1.clear(),v2.clear();
		for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)ans[i][j]=0;
		for (int i=0;i<n;i++)
			if (s[i]=='1')v1.pb(i+1);
			else v2.pb(i+1);int cnt=v2.size();
		if (cnt==1||cnt==2){puts("NO");continue;}puts("YES");
		for (int i=0;i+1<cnt;i++)
			ans[v2[i]][v2[i+1]]=1,ans[v2[i+1]][v2[i]]=2;
		if (cnt!=0)ans[v2[cnt-1]][v2[0]]=1,ans[v2[0]][v2[cnt-1]]=2;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				if (i==j)cout<<'X';
				else if (ans[i][j]==0)cout<<'=';
				else if (ans[i][j]==1)cout<<'+';
				else cout<<'-';puts("");
		}
	}
	return 0;
}