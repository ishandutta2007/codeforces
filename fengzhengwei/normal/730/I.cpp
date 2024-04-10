#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int mod=1e9+7,xx=1e7+5;
int n,p,c,a[xx],b[xx];
multiset<pair<int,int> >s[4];
//remAremBdltadltb 
//dlta=-a+b
int to[4][2]={0,0,1,1,0,2,1,3};
int bel[xx];
ll ans;
void cg(int x,int y)
{
	if(bel[x]==-1)
	{
		if(y==0)ans+=a[x],p--;
		if(y==1)ans+=b[x],c--;
		s[0].erase(s[0].find(make_pair(a[x],x)));
		s[1].erase(s[1].find(make_pair(b[x],x)));
		if(y==0)s[2].insert(make_pair(b[x]-a[x],x));
		if(y==1)s[3].insert(make_pair(a[x]-b[x],x));
		bel[x]=y;
	}
	else 
	{
		if(bel[x]==0)p++,c--,ans+=b[x]-a[x],s[2].erase(s[2].find(make_pair(b[x]-a[x],x))),s[3].insert(make_pair(a[x]-b[x],x));
		if(bel[x]==1)p--,c++,ans+=a[x]-b[x],s[3].erase(s[3].find(make_pair(a[x]-b[x],x))),s[2].insert(make_pair(b[x]-a[x],x));
	}
}
signed main(){
	memset(bel,-1,sizeof(bel));
	n=read(),p=read(),c=read();
	for(int i=1;i<=n;i++)a[i]=read(),s[0].insert(make_pair(a[i],i));
	for(int i=1;i<=n;i++)b[i]=read(),s[1].insert(make_pair(b[i],i));
	
	while(1)
	{
		int mx=0,Lid=0,Rid=0;
		for(int i=0;i<4;i++)
		{
//			cout<<i<<"ASDSADF "<<to[i][0]<<" "<<to[i][1]<<" "<<s[3].size()<<"!!\n";
			if(!s[to[i][0]].size()||!s[to[i][1]].size())continue;
			if(to[i][0]==to[i][1])
			{
				if(to[i][0]==0&&p)mx=max(mx,(--s[to[i][0]].end())->first);
				if(to[i][0]==1&&c)mx=max(mx,(--s[to[i][0]].end())->first);
			}
			else 
			{
				if(to[i][0]==0&&c)mx=max(mx,(--s[to[i][0]].end())->first+(--s[to[i][1]].end())->first);
				if(to[i][0]==1&&p)mx=max(mx,(--s[to[i][0]].end())->first+(--s[to[i][1]].end())->first);
			}
		}
//		exit(0);
		if(mx==0)break;
		int To=0;
		for(int i=0;i<4;i++)
		{
			if(!s[to[i][0]].size()||!s[to[i][1]].size())continue;
			if(to[i][0]==to[i][1])
			{
				if(to[i][0]==0&&p)
				{
					To=0;
					if(mx==(--s[to[i][0]].end())->first)
					{
						Lid=(--s[to[i][0]].end())->second;
						Rid=0;break;
					}
				}
				if(to[i][0]==1&&c)
				{
					To=1;
					if(mx==(--s[to[i][0]].end())->first)
					{
						Lid=(--s[to[i][0]].end())->second;
						Rid=0;break;
					}
				}
			}
			else 
			{
				if(to[i][0]==0&&c)
				{
					To=0;
					if(mx==(--s[to[i][0]].end())->first+(--s[to[i][1]].end())->first)
					{
						Lid=(--s[to[i][0]].end())->second;
						Rid=(--s[to[i][1]].end())->second;break;
					}
				}
				if(to[i][0]==1&&p)
				{
					To=1;
					if(mx==(--s[to[i][0]].end())->first+(--s[to[i][1]].end())->first)
					{
						Lid=(--s[to[i][0]].end())->second;
						Rid=(--s[to[i][1]].end())->second;break;
					}
				}
			}
		}
//		cout<<mx<<" "<<Lid<<" "<<Rid<<" "<<p<<" "<<c<<" "<<s[0].size()<<" "<<s[1].size()<<" "<<s[2].size()<<" "<<s[3].size()<<"!!\n";
		if(!Rid)cg(Lid,To);
		else cg(Rid,0),cg(Lid,To);
	}
	cout<<ans<<"\n";
	for(auto it:s[2])cout<<it.second<<" ";puts("");
	for(auto it:s[3])cout<<it.second<<" ";puts("");
	pc('1',1);
	return 0;
}