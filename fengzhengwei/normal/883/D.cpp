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
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
const int xx=2000005;
char s[xx];
int n;
namespace solve1
{
	void solve()
	{
		int t=0;
		for(int i=1;i<=n;i++)t+=s[i]=='P';
		if(t==1)
		{
			int id=0;
			for(int i=1;i<=n;i++)
				if(s[i]=='P')id=i;
			int mn=1e9,tt1=0;
			for(int i=1;i<=id;i++)
			{
				tt1+=s[i]=='*';
				if(s[i]=='*')mn=min(mn,i);
			}
			int tt2=0,mx=-1e9;
			for(int i=id+1;i<=n;i++)
			{
				tt2+=s[i]=='*';
				if(s[i]=='*')mx=max(mx,i);
			}
			if(tt1>tt2)
			{
				cout<<tt1<<" "<<id-mn<<"\n";
				exit(0);
			}
			if(tt1<tt2)
			{
				cout<<tt2<<" "<<mx-id<<"\n";
				exit(0);
			}
			if(id-mn<mx-id)
			{
				cout<<tt1<<" "<<id-mn<<"\n";
				exit(0);
			}
			cout<<tt2<<" "<<mx-id<<"\n";
			exit(0);
		}
	}
}
#define pr make_pair
#define X first
#define Y second
pair<int,int> q[xx];
int id[xx],tt;
vector<int>v[xx];
// 
bool check(int x)
{
	int l=1,r=0;
	// 
	q[++r]=pr(0,1000000000);
	id[0]=-1e9;
	for(int i=1;i<=tt;i++)
	{
		if(l>r)return false;
		int zz=0;
		for(int j=l;j<=r;j++)
		{
			while(zz<(int)v[i].size()&&v[i][zz]-id[q[j].X]<=x)zz++;
//			cout<<v[i].size()<<"\n";
			if(zz!=(int)v[i].size())q[j].Y=min(q[j].Y,v[i][zz]);
		}
		// 
		int L=-1e9;
		for(int j=l;j<=r;j++)
			if(id[i]-q[j].Y<=x)L=max(L,q[j].X);
		int R=-1e9;
		for(int j=l;j<=r;j++)
			R=max(R,q[j].Y);
		l=r+1;
//		cout<<i<<" "<<L<<" "<<R<<" "<<zz<<"\n";
		if(L!=-1e9)q[++r]=pr(L,1e9);
		if(R!=-1e9&&i!=tt)q[++r]=pr(i,R);
		// 
		// 
		// 
	}
	if(l<=r)
	return true;
	return false;
}
signed main(){
	n=read();
	scanf("%s",s+1);
	solve1::solve();
	int last=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='P')
		{
			tt++;id[tt]=i;
			for(int j=last;j<i;j++)if(s[j]=='*')v[tt].push_back(j);
			last=i+1;
		}
	}
	tt++;id[tt]=1e9;
	for(int j=last;j<=n;j++)if(s[j]=='*')v[tt].push_back(j);
//	cout<<check(2)<<"\n";
//	return 0;
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	int o=0;
	for(int i=1;i<=n;i++)if(s[i]=='*')o++;
	cout<<o<<" "<<ans<<"\n";
	pc('-',1);
	return 0;
}