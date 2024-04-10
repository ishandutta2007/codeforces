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

const int M=3e5+10;
int n,a[M],b[M],dis[M][3],minn,p[M][3],res[M];
queue<pair<pair<int,int>,int> >q;

signed main()
{
	n=read();minn=n;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)b[i]=read();
	q.push(mp(mp(1,n),1));dis[n][1]=1;
	int ans=-1;
	while(!q.empty())
	{
		int x=q.front().x.x,y=q.front().x.y,step=q.front().y;q.pop();
		if (x==2)
		{
			if (dis[y+b[y]][1]==0)dis[y+b[y]][1]=step,q.push(mp(mp(1,y+b[y]),step)),p[y+b[y]][2]=y;
		}
		else
		{
			if (y-a[y]<=0){ans=step,p[0][1]=y;break;}
			for (int i=y-a[y];i<minn;i++)
				p[i][1]=y,q.push(mp(mp(2,i),step+1));minn=min(minn,y-a[y]);
		}
	} 
	cout<<ans<<endl;
	int cnt=0,now=0;
	for (int i=2;i<=ans;i++)now=p[now][1],res[i]=p[now][2],now=p[now][2];
	for (int i=ans;i>=1;i--)cout<<res[i]<<' ';
	return 0;
}