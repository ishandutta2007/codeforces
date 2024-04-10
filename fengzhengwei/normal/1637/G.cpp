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
int T;
multiset<int>v;
int lb(int x){return x&-x;}
vector<pair<int,int> >ans;
void solve(int n,int a)
{
	if(!n)return;
	if(n==1)return v.insert(a),void();
	int r=n;
	while(r!=lb(r))r-=lb(r);
	v.insert(a*r);
	int num=0;
	for(int i=1;i+r<=n;i++)
	{
		ans.push_back(make_pair((r+i)*a,(r-i)*a));
		v.insert((r+r)*a),num++;
	}
	solve(num,a*2);
	solve(n-num-num-1,a);
}
signed main(){
	T=read();
	while(T--)
	{
		v.clear();
		ans.clear();
		int n=read();
		if(n==2)
		{
			puts("-1");
			continue;
		}
		solve(n,1);
		int to=*--v.end();
		if(v.find(0)==v.end())
		{
			int lst=0;
			for(auto it:v)
			{
				if(it==lst)
				{
					ans.push_back(make_pair(it,lst));
//					cout<<it<<" "<<lst<<"\n";
					break;
				}
				lst=it;
			}
			v.erase(v.find(lst));
			v.erase(v.find(lst));
			v.insert(lst+lst);
			v.insert(0);
		}
		int a=v.count(0);
		v.erase(0);
		for(int i=1;i<a;i++)ans.push_back(make_pair(0,*v.begin())),v.insert(*v.begin());//0 
		for(auto it:v)
		{
			while(it!=to)
			{
				ans.push_back(make_pair(0,it));
				ans.push_back(make_pair(it,it));
//				cout<<0<<" "<<it<<"\n";
//				cout<<it<<" "<<it<<"\n";
				it*=2;
			}
		}
		ans.push_back(make_pair(0,to));
		cout<<ans.size()<<"\n";
		for(auto it:ans)cout<<it.first<<" "<<it.second<<"\n";
//		for(auto it:v)
//		{
//			cout<<it<<"\n";
//		}
	}
	pc('1',1);
	return 0;
}