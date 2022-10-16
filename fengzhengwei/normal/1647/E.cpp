#include<windows.h>
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
const int xx=1e5+5;
int n,p[xx],a[xx],d[xx],f[xx][31];
set<int>S[xx];//x 
set<int>lin;// 
struct nod
{
	int i;
	mutable int id;
	bool operator<(const nod&w)const{return i<w.i;}
};
int an[xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)p[i]=read(),d[p[i]]++;
	set<nod>s;
	for(int i=1;i<=n;i++)a[i]=read(),s.insert({a[i],i});
	// 
	int cr=0;
	for(int i=1;i<=n;i++)if(d[i]==0)cr++;
	int lun=(((--s.end())->i)-n)/cr;
	for(int i=1;i<=n;i++)f[i][0]=p[i];
	for(int j=1;j<=30;j++)
		for(int i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1];
//	cerr<<lun<<"!!\n";
	for(int i=1;i<=n;i++)
	{
		int x=i;
		for(int j=30;j>=0;j--)
			if(lun>>j&1)x=f[x][j];
		S[x].insert(i);
//		cout<<i<<" "<<x<<"!!\n";
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<" "<<lin.size()<<"!!\n";
		if(s.find({i})!=s.end())
		{
//			puts("ASd");
			int id=s.find({i})->id;
			an[*S[id].begin()]=i;
			for(auto it:S[id])
			{
				if(it==*S[id].begin())continue;
				lin.insert(it);
			}
		}
		else 
		{
			an[*lin.begin()]=i;
			lin.erase(lin.begin());
		}
	}
	for(int i=1;i<=n;i++)cout<<an[i]<<" \n"[i==n];
	pc('1',1);
	return 0;
}