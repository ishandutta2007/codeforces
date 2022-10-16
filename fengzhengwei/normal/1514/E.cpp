#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
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
vector<int>v;

int g1(int x,int y)
{
	cout<<1<<" "<<x-1<<" "<<y-1<<"\n";
	fflush(stdout);
	return read();
}
int g2(int x,int y)// 
{
	if(y==-1)return 0;
	cout<<2<<" "<<x-1<<" "<<y+1<<" ";
	for(int i=0;i<=y;i++)cout<<v[i]-1<<" ";puts("");
	fflush(stdout);
	return read();
}
const int xx=105;
int bel[xx],a[xx][xx];
signed main(){
//	freopen("a.in","r",stdin);
	T=read();
	while(T--)
	{
		int n=read();
		v.clear();
		memset(bel,0,sizeof(bel));
//		if(n!=4&&n!=21)assert(0);
		if(g1(1,2))v.push_back(1),v.push_back(2);
		else v.push_back(2),v.push_back(1);
		for(int i=3;i<=n;i++)
		{
			if(g1(*--v.end(),i)){v.push_back(i);continue;}
			if(g1(i,*v.begin())){reverse(v.begin(),v.end()),v.push_back(i),reverse(v.begin(),v.end());continue;}
			int l=1,r=v.size();
			while(l<r)
			{
				if(l+1==r)
				{
					vector<int>s;
					while(v.size()>l)s.push_back(*--v.end()),v.pop_back();
					reverse(s.begin(),s.end());
					v.push_back(i);
					for(auto it:s)v.push_back(it);break;
				}
				int mid=l+r>>1;
				if(g1(v[mid-1],i))l=mid;
				else r=mid;
			}
			assert(v.size()==i);
		}
//		assert(v.size()==n)
		int scc=1;
		int l=n,r=n;
		while(r>=1)
		{
			while(l<=r)
			{
				while(l&&g2(v[r-1],l-2))l--;
				
				bel[v[r-1]]=scc;
				r--;
			}
			scc++;
			l=r;
		}
//		if(n!=4&&n!=21&&n!=58)assert(0);
		cout<<3<<"\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(bel[j]<=bel[i])cout<<1;
				else cout<<0;
			}
			puts("");
		}
		puts("");
		fflush(stdout);
		int op;cin>>op;
//		if(T==2)return 0;
	}
	return 0;
}