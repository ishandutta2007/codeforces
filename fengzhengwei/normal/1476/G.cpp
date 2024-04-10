#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=1e5+5;
int a[xx];
int B;
int bel(int x){return (x-1)/B+1;}
struct node
{
	int l,r,t,k,id;
	bool operator<(const node&w)const{return bel(l)==bel(w.l)?bel(r)==bel(w.r)?(bel(l)+bel(r))&1?t>w.t:t<w.t:r<w.r:l<w.l;}
}e[xx];
int t1[xx],t2[xx];// 
struct nod
{
	int num,cs;
	bool operator<(const nod&w)const{return num<w.num;}
	nod(){}
	nod(int x,int y):num(x),cs(y){}
};
vector<int>s;
int BB;
int uu[xx],vv[xx],res[xx],vis[xx];
void add(int x)
{
	t2[t1[a[x]]]--;
	t1[a[x]]++;
	if(!vis[a[x]])s.push_back(a[x]),vis[a[x]]=1;
	t2[t1[a[x]]]++;
}
void erase(int x)
{
	t2[t1[a[x]]]--;
	t1[a[x]]--;
	t2[t1[a[x]]]++;
}
int l=1,r=0,t=0;
void c(int x)
{
	if(l<=uu[x]&&uu[x]<=r)
	{
		erase(uu[x]);
		swap(a[uu[x]],vv[x]);
		add(uu[x]);
	}
	else swap(a[uu[x]],vv[x]);
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read();m=read();
	B=pow(n,0.666);
	BB=sqrt(n*log2(n));
	for(int i=1;i<=n;i++)a[i]=read();
	int cnt=0,tot=0;
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==1)e[++tot].l=read(),e[tot].r=read(),e[tot].k=read(),e[tot].t=cnt,e[tot].id=tot;
		else uu[++cnt]=read(),vv[cnt]=read();
	}
	sort(e+1,e+tot+1);
	for(int i=1;i<=tot;i++)
	{
		while(r<e[i].r)add(++r);
		while(l>e[i].l)add(--l);
		while(r>e[i].r)erase(r--);
		while(l<e[i].l)erase(l++);
		while(t<e[i].t)c(++t);
		while(t>e[i].t)c(t--);
		vector<nod>v;// 
		for(int j=1;j<=BB;j++)v.push_back((nod){j,t2[j]});// 
		vector<nod>a;
		vector<int>aa;
		for(int j=0;j<s.size();j++)
		{
			if(t1[s[j]]>BB)aa.push_back(s[j]),a.push_back((nod){t1[s[j]],1});
			else vis[s[j]]=0;
		}
//		s.clear();
//		for(int j=0;j<a.size();j++)s.push_back(aa[j]);
		
		swap(aa,s);
		sort(a.begin(),a.end());
		for(int j=0;j<a.size();j++)v.push_back(a[j]);
		int rpos=0,sum=0,minn=2147483647;
		for(int lpos=0;lpos<v.size();lpos++)
		{
			while(sum<e[i].k&&rpos<v.size())sum+=v[rpos++].cs;
			if(sum<e[i].k)break;
			minn=min(minn,v[rpos-1].num-v[lpos].num);
			sum-=v[lpos].cs;
		}
		if(minn==2147483647)minn=-1;
		res[e[i].id]=minn;
	}
	for(int i=1;i<=tot;i++)cout<<res[i]<<"\n";
	return 0;
}