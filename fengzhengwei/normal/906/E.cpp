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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
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
	wt(x),pc(op,0);
}
const int xx=1e6+5;
char s[xx],A[xx],B[xx];
int t[50];
struct nod{int to[26],fail,size,/*dep,*/slink;}e[xx];
int dif(int x){return e[x].size-e[e[x].fail].size;}
int lst,cst;
void add(int x,int id)
{
	int p=lst;
	while(s[id]!=s[id-e[p].size-1])p=e[p].fail;
	if(!e[p].to[x])e[p].to[x]=++cst;
	int now=e[p].to[x];
	e[now].size=e[p].size+2;
	if(e[now].size==1)e[now].fail=2;
	else 
	{
		p=e[p].fail;
		while(s[id]!=s[id-e[p].size-1])p=e[p].fail;
		e[now].fail=e[p].to[x];
	}
	lst=now;
//	e[now].dep=e[e[now].fail].dep+1;
	if(e[now].fail==2||e[now].fail==1)e[now].slink=e[now].fail;
	else if(dif(now)==dif(e[now].fail))e[now].slink=e[e[now].fail].slink;
	else e[now].slink=e[now].fail;
}
struct nd{int v,id;}g[xx],f[xx];
void ad(nd&a,const nd&b){if(a.v>b.v)a=b;}
vector<pair<int,int> >ans;
void out(int n)
{
	if(n==0)return;
	if(f[n].id==n-2)return out(n-2);
	ans.push_back(make_pair(f[n].id+1,n));
	out(f[n].id);
}
nd re(const nd&w){return {w.v+1,w.id};}
signed main(){
	++cst,e[cst].size=-1,e[cst].fail=0;
	++cst,e[cst].size=0,e[cst].fail=1;
	lst=1;
	scanf("%s",A+1),scanf("%s",B+1);
	int n=strlen(A+1);
	for(int i=1;i<=n;i++)t[A[i]-'a']++;
	for(int i=1;i<=n;i++)t[B[i]-'a']--;
	for(int i=0;i<26;i++)if(t[i]!=0)puts("-1"),exit(0);
	int tt=0;
	for(int i=1;i<=n;i++)s[++tt]=A[i],s[++tt]=B[i];
	memset(g,0x3f,sizeof(g));
	memset(f,0x3f,sizeof(f));
	f[0]={0,0};
	for(int i=1;i<=tt;i++)
	{
		add(s[i]-'a',i);
		int x=lst;
		while(x>2)
		{
			if(e[x].fail>2&&dif(x)==dif(e[x].fail))g[x]=g[e[x].fail];
			else g[x]={(int)1e9,(int)1e9};
			ad(g[x],{f[i-e[e[x].slink].size-dif(x)].v,i-e[e[x].slink].size-dif(x)});// 
//			cerr<<x<<" "<<e[x].size<<" "<<i<<" "<<i-e[e[x].slink].size-dif(x)<<" "<<g[x].v<<" "<<g[x].id<<"!!\n";
			x=e[x].slink;
		}
		if(i%2==0)
		{
			if(s[i]==s[i-1])f[i]={f[i-2].v,i-2};
			x=lst;
			while(x>2)
				ad(f[i],re(g[x])),x=e[x].slink;
		}
//		cerr<<i<<" "<<f[i].v<<" qweqe "<<f[i].id<<"!!\n";
	}
	if(f[tt].v<1e9)
	{
		cerr<<f[tt].v<<"\n";
		out(tt);
		cout<<ans.size()<<"\n";
		for(auto it:ans)cout<<(it.first+1>>1)<<" "<<(it.second+1>>1)<<"\n";
	}
	else puts("-1");
	pc('1',1);
	return 0;
}