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
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
const int xx=2e5+5;
int k,n,m;
ll a[xx];
int mx[xx],mxid[xx];
void upd(int i,int x,int y){if(mx[i]<x)mx[i]=x,mxid[i]=y;}
struct nod
{
	int id,adt;
	bool operator<(const nod&w)const{return adt>w.adt;}
};
vector<nod>v[xx];
struct node
{
	int id;
	double mul;
	bool operator<(const node&w)const{return mul>w.mul;}
};
vector<node>M;
int val[xx];
bool cmp(int a,int b){return val[a]<val[b];}
int main(){
	k=read(),n=read(),m=read();
	for(int i=1;i<=k;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int op=read();
		if(op==1)
		{
			int x=read(),y=read();
			upd(x,y,i);
		}
		if(op==2)
		{
			int x=read(),y=read();
			v[x].push_back((nod){i,y});
		}
		if(op==3)
		{
			int x=read(),y=read();
			M.push_back((node){i,1.0*y});
		}
		val[i]=op;
	}
	for(int i=1;i<=k;i++)
	{
		if(mx[i]-a[i]>0)
		v[i].push_back((nod){mxid[i],mx[i]-a[i]});
	}
	for(int i=1;i<=k;i++)
		sort(v[i].begin(),v[i].end());
	for(int i=1;i<=k;i++)
		for(auto it:v[i])
			M.push_back((node){it.id,(1.0*a[i]+it.adt)/a[i]}),a[i]+=it.adt,assert(it.id<=n);
	sort(M.begin(),M.end());
	vector<int>ans;
	for(int i=0;i<min((int)M.size(),m);i++)ans.push_back(M[i].id);
	cout<<ans.size()<<"\n";
	sort(ans.begin(),ans.end(),cmp);
	for(auto it:ans)cout<<it<<" ";
	puts("");
	pc('1',1);
	return 0;
}