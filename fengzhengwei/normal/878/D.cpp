#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;else if(c==EOF)return -1;
	int ans=c-'0';
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
const int xx=1e5+30;
int n,k,q,a[14][xx];
int tl[xx],tr[xx],cr[xx];
vector<pair<int,int> >v[5005];
int id[14],to[xx][14];
int re[xx*14],ans[xx],isq[xx],An[xx];
signed main(){
	n=read(),k=read(),q=read();
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)a[i][j]=read();
	int cn=k,cst=0;
	//1max0min 
	for(int i=1;i<=q;i++)
	{
		int op=read();
		if(op==1)
			++cn,tl[cn]=read(),tr[cn]=read(),cr[cn]=1;
		if(op==2)
			++cn,tl[cn]=read(),tr[cn]=read(),cr[cn]=0;
		if(op==3)
		{
			int X=read(),Y=read();
			isq[i]=Y;
			for(int j=1;j<=k;j++)id[j]=j;
			sort(id+1,id+k+1,[&](int x,int y){return a[x][Y]<a[y][Y];});
			int now=(1<<k)-1;
			v[now].push_back(make_pair(X,++cst));
			to[i][0]=cst;
//			cout<<now<<"\n";
			for(int j=1;j<=k;j++)
			{
				now-=(1<<(id[j]-1));
//			cout<<now<<" "<<id[k]<<"\n";
				v[now].push_back(make_pair(X,++cst));
				to[i][j]=cst;
			}
		}
	}
	for(int i=0;i<(1<<k);i++)
	{
		for(int j=1;j<=k;j++)An[j]=(i>>(j-1)&1);
		for(int j=k+1;j<=cn;j++)
		{
			if(cr[j]==1)An[j]=max(An[tl[j]],An[tr[j]]);
			if(cr[j]==0)An[j]=min(An[tl[j]],An[tr[j]]);
		}
		for(auto it:v[i])re[it.second]=An[it.first];
	}
	for(int i=1;i<=q;i++)
	{
		if(isq[i])
		{
			for(int j=1;j<=k;j++)id[j]=j;
			sort(id+1,id+k+1,[&](int x,int y){return a[x][isq[i]]<a[y][isq[i]];});
			for(int j=0;j<=12;j++)
			{
				if(!re[to[i][j+1]])
				{
//					cerr<<re[to[i][j]]<<"\n";
					cout<<a[id[j+1]][isq[i]]<<"\n";
					break;
				}
			}
		}
	}
	
	pc('1',1);
	return 0;
}