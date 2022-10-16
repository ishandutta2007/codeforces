#include<bits/stdc++.h>
#define ll long long
#define dd double
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
int n;
const int xx=505
;int a[xx],id[xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return a[x]<a[y];});
	vector<int>v;
	int lim=1e9;
	for(int i=n;i>=1;i--)
		if(a[id[i]]>1)v.push_back(id[i]),lim=i-1;
	if(!v.size())puts("NO"),exit(0);
	if(v.size()==n)
	{
		cout<<"YES"<<" "<<n-1<<"\n";
		cout<<n-1<<"\n";
		for(int i=n;i>=2;i--)cout<<id[i]<<" "<<id[i-1]<<"\n";
		exit(0);
	}
	if(v.size()==n-1)
	{
		cout<<"YES"<<" "<<n-1<<"\n";
		cout<<n-1<<"\n";
		for(int i=n;i>=2;i--)cout<<id[i]<<" "<<id[i-1]<<"\n";
		exit(0);
	}
	vector<pair<int,int> >ans;
	for(int i=0;i<v.size()-1;i++)
		ans.push_back(make_pair(v[i],v[i+1]));
	ans.push_back(make_pair(id[1],v[0]));
	ans.push_back(make_pair(id[2],v[v.size()-1]));
	for(auto it:v)a[it]-=2;
	for(int i=3;i<=lim;i++)
	{
		int cr=0;
		for(auto it:v)
		{
			if(a[it])
			{
				ans.push_back(make_pair(id[i],it));
				cr=1,a[it]--;
				break; 
			}
		}
		if(!cr)puts("NO"),exit(0);
	}
	
//	for(auto it:v)
//	{
//		
//	}
	cout<<"YES"<<" "<<v.size()+1<<"\n";
	cout<<ans.size()<<"\n";
	for(auto it:ans)cout<<it.first<<" "<<it.second<<"\n";
	pc('1',1);
	return 0;
}