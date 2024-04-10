#include<bits/stdc++.h>
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
int T;
const int xx=2e5+5;
struct nod
{
	int id;
	int size;
	vector<int>v;
	bool operator<(const nod&w)const
	{
		if(size!=w.size)return size<w.size;
		for(int i=0;i<size;i++)
		{
			if(v[i]!=w.v[i])return v[i]<w.v[i];
		}
		return 0;
	}
}e[xx];
int ans[xx];
int t[xx];
signed main(){
	T=read();
	while(T--)
	{
		int n,m;
		n=read();
		m=read();
		for(int i=1;i<=n;i++)t[i]=0;
		for(int i=1;i<=m;i++)
		{
			e[i].id=i;
			e[i].size=read();
			e[i].v.clear();
			for(int j=1;j<=e[i].size;j++)e[i].v.push_back(read());
			sort(e[i].v.begin(),e[i].v.end());
		}
		sort(e+1,e+m+1);
		int res=1;
		for(int i=1;i<=m;i++)
		{
			int vis=1;
			for(int j=0;j<e[i].size;j++)
			{
				if(t[e[i].v[j]]<(m+1>>1))
				{
					t[e[i].v[j]]++;
					ans[e[i].id]=e[i].v[j];
					vis=0;
					break;
				}
			}
			if(vis)
			{
				res=0;
				puts("NO");break;
			}
		}
		if(!res)continue;
		puts("YES");
		for(int i=1;i<=m;i++)cout<<ans[i]<<" \n"[i==m];
	}
	return 0;
}