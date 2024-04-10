#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=5e5+5;
int fa[xx],size[xx],n,m;
int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
void merge(int a,int b)
{
	if(find(a)==find(b))return;	
	a=find(a),b=find(b);
	size[a]+=size[b];
	fa[b]=a;
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)fa[i]=i,size[i]=1;
	int ans=0;
	int rem=0;
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		if(find(a)==find(b))rem++;
		merge(a,b);
		vector<int>s;
		for(int j=1;j<=n;j++)
		{
			if(fa[j]==j)
				s.push_back(j);
		}
		sort(s.begin(),s.end(),[&](int a,int b){return size[a]>size[b];});
		int ans=0;
//		cout<<s.size()<<"\n";
//		assert(rem==0);
		for(int j=1;j<=n;j++)
		{
			int res=size[find(j)];
			int c=rem;
			for(auto it:s)
			{
				if(it==find(j))continue;
				if(c)
				{
//					cerr<<"!!!\n";
					c--;
					res+=size[it];
				}
			}
			ans=max(ans,res);
		}
		cout<<ans-1<<"\n";
	}
	pc('1',1);
	return 0;
}