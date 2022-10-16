#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=3e5+5;
int T;
int n,m,a[xx],jl[xx],vs[xx];
signed main(){
	T=read();
	while(T--)
	{
		n=read(),m=read();
		int B=n/3;
		memset(jl,0,sizeof(jl[0])*(n+1));
		for(int i=1;i<=n;i++)a[i]=read(),jl[(n+i-a[i])%n]++;
		vector<int>v;
		for(int i=0;i<n;i++)
		{
			if(jl[i]>=B)
			{
				memset(vs,0,sizeof(vs[0])*(n+1));
				int sl=0;
				for(int j=1;j<=n;j++)
				{
					if(!vs[j])
					{
						vs[j]=1;
						int now=j;
						while(!vs[(a[now]+i-1)%n+1])
						{
							now=(a[now]+i-1)%n+1;
							vs[now]=1;
						}
						sl++;
					}
				}
				if(n-sl<=m)v.push_back(i);
			}
		}
		cout<<v.size()<<" ";
		for(int i=0;i<v.size();i++)cout<<v[i]<<" ";puts("");
	}
	return 0;
}