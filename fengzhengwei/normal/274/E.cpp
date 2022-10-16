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
//(n+m)*24*kOn 
int n,m,k;
const int xx=2e5+10;
// 
struct pr
{
	int x,y;
	pr(){}
	pr(int a,dd b):x(a),y(b){}
	bool operator<(const pr&w)const{return x==w.x?y<w.y:x<w.x;};
	pr operator+(const pr&w)const{return pr(x+w.x,y+w.y);}
};
pair<dd,dd> to(int x,int y)//xy1,1n,m 
{
	return make_pair(y-0.5,n-x+0.5);
}
//90 ()
pr rot(dd x,dd y){return pr((int)(y+x+2),(int)(y-x+100000+5));}
map<pr,int>mp;
vector<int>ro[xx],cl[xx];
void in(pr a)
{
	ro[a.y].push_back(a.x);
	cl[a.x].push_back(a.y);
	mp[a]=1;
}
//0123 
// 
// 
// 
pr d[]={pr(-1,0),pr(1,0),pr(0,1),pr(0,-1)};
int vs=0;
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
pair<pr,int> run(pr x,int id)
{
	if(id==0||id==1)
	{
		pr to;
		if(id==1)to=pr(*lb(ro[x.y],x.x),x.y);
		else to=pr(*--lb(ro[x.y],x.x),x.y);
		int up=0,down=0;
		to=to+d[id^1];// 
		if(mp.find(to+d[2])!=mp.end())up=1;
		if(mp.find(to+d[3])!=mp.end())down=1;
		if((!up&&!down)||(up&&down))return vs=1,make_pair(to,id^1);
		if(up)return make_pair(to,3);
		return make_pair(to,2);
	}
	else
	{
		pr to;
		if(id==2)to=pr(x.x,*lb(cl[x.x],x.y));
		else to=pr(x.x,*--lb(cl[x.x],x.y));
		int left=0,rt=0;
		to=to+d[id^1];// 
		if(mp.find(to+d[0])!=mp.end())left=1;
		if(mp.find(to+d[1])!=mp.end())rt=1;
		if((!left&&!rt)||(left&&rt))return vs=1,make_pair(to,id^1);
		if(left)return make_pair(to,1);
		return make_pair(to,0);
	}
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;i++)
	{
		int a=read(),b=read();
		pair<dd,dd>s=to(a,b);
		pr u=rot(s.first,s.second);
		in(u);
	}
	for(int i=0;i<=n+1;i++)
	{
		in(rot(-0.5,i-0.5));
		in(rot(m+1-0.5,i-0.5));
	}
	for(int i=0;i<=m+1;i++)
	{
		in(rot(i-0.5,-0.5));
		in(rot(i-0.5,n+1-0.5));
	}
	int a=read(),b=read();
	pair<dd,dd>s=to(a,b);
	pr u=rot(s.first,s.second);
	string A;
	cin>>A;
	int id=0;
	if(A=="SW")id=0;
	if(A=="NE")id=1;
	if(A=="SE")id=2;
	if(A=="NW")id=3;
	for(int i=1;i<xx;i++)sort(ro[i].begin(),ro[i].end());
	for(int i=1;i<xx;i++)sort(cl[i].begin(),cl[i].end());
	pair<pr,int> st=run(u,id),ed=st;
	ll ans=0;
	#define fi first
	while(1)
	{
		pair<pr,int>to=run(st.fi,st.second);
		ans+=abs(st.fi.x-to.fi.x)/2+abs(st.fi.y-to.fi.y)/2;
		if(to.fi.x==ed.fi.x&&to.fi.y==ed.fi.y&&to.second==ed.second)break;
		st=to;
	}
	if(vs)ans/=2;
	cout<<ans<<"\n";
	return 0;
}