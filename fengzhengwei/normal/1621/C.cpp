#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
const int mod=998244353;
int a[xx];
char s[xx];
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
int n,m,q,k,tt;
int ask(int x)
{
	cout<<"? "<<x<<"\n";
	tt++;
	fflush(stdout);
	return read();
}
int vs[xx],ans[xx];
vector<int>v[xx];
pair<int,int>Id[xx];
//int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
int main(){
	int T=read();
	while(T--)
	{
		n=read();tt=0;
		for(int i=1;i<=n;i++)vs[i]=0,v[i].clear();
		for(int i=1;i<=n;i++)
		{
			int a=ask(i);
			if(vs[a])
			{
				int sz=v[Id[a].first].size();
				ans[i]=v[Id[a].first][((Id[a].second-(tt-2))%sz+sz)%sz];
			}
			else 
			{
				int now=a;
				v[i].push_back(a);
				Id[a]=make_pair(i,v[i].size()-1);
				vs[a]=1;
				while(1)
				{
					a=ask(i);
					if(a==now)break;
					v[i].push_back(a);
					Id[a]=make_pair(i,v[i].size()-1);
					vs[a]=1;
				}
				int sz=v[Id[a].first].size();
				ans[i]=v[Id[a].first][((Id[a].second-(tt-2))%sz+sz)%sz];
			}
		}
		cout<<"! ";
		for(int i=1;i<=n;i++)cout<<ans[i]<<" ";puts("");
		fflush(stdout);
	}
	pc('1',1);
	return 0;
}