#include<bits/stdc++.h>
#define ll long long
#define LL __int128
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
const int xx=2e6+5;
char id[305][305];
int get(int x,int y){return (&id[x][y]-&id[0][0]);}
int fa[xx];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
//int fa[xx];
int s[305][305],n,m,q;
struct pr{int a,b,c,pr;}qu[xx];
int ans[xx],sum,an[xx],vis[xx];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
signed main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=q;i++)
	{
		int a=read(),b=read(),c=read();
		qu[i]={a,b,c,s[a][b]};
		s[a][b]=c;
	}
	int mx=qu[q].c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)fa[get(i,j)]=get(i,j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(i+dx[k]&&j+dy[k]&&i+dx[k]<=n&&j+dy[k]<=m)
				{
					if(s[i][j]==s[i+dx[k]][j+dy[k]])
					{
						if(find(get(i,j))!=find(get(i+dx[k],j+dy[k])))fa[find(get(i,j))]=get(i+dx[k],j+dy[k]);
					}
				}
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(find(fa[get(i,j)])==get(i,j))sum++,an[s[i][j]]++;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)cout<<s[i][j]<<" \n"[j==m];
	for(int i=q;i>=1;i--)
	{
		int x=qu[i].a,y=qu[i].b,c=qu[i].c,pr=qu[i].pr;
		if(!vis[c])vis[c]=1,sum-=an[c];
//	cout<<sum<<"@\n";
		ans[i]=sum;
		if(pr!=c)
		{
			sum++,an[pr]++;
			s[x][y]=pr;
			fa[get(x,y)]=get(x,y);
			for(int k=0;k<4;k++)
			{
				if(x+dx[k]&&y+dy[k]&&x+dx[k]<=n&&y+dy[k]<=m)
				{
					if(s[x][y]==s[x+dx[k]][y+dy[k]])
					{
						if(find(get(x,y))!=find(get(x+dx[k],y+dy[k])))fa[find(get(x,y))]=get(x+dx[k],y+dy[k]),sum--,an[pr]--;
					}
				}
			}
		}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)cout<<s[i][j]<<" \n"[j==m];
//		puts("");
		
	}
//	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
//	puts("");
	memset(s,-1,sizeof(s));
	for(int i=1;i<=q;i++)
	{
		int j=i;
		while(j+1<=q&&qu[j+1].c==qu[i].c)j++;
		for(int k=i;k<=j;k++)
		{
			int x=qu[k].a,y=qu[k].b;
			fa[get(x,y)]=get(x,y);
			s[x][y]=0;
		}
		sum=0; 
		for(int k=i;k<=j;k++)
		{
			int x=qu[k].a,y=qu[k].b;
			if(s[x][y]!=qu[i].c)
			{
				sum++,s[x][y]=qu[i].c;
				for(int k=0;k<4;k++)
				{
					if(x+dx[k]&&y+dy[k]&&x+dx[k]<=n&&y+dy[k]<=m)
					{
						if(s[x][y]==s[x+dx[k]][y+dy[k]])
						{
	//						cerr<<x<<' '<<y<<" "<<x+dx[k]<<" "<<y+dy[k]<<" "<<find(get(x,y))<<" "<<find(get(x+dx[k],y+dy[k]))<<"#$#$\n";
	//						cerr<<x<<' '<<y<<" "<<x+dx[k]<<" "<<y+dy[k]<<" "<<find(get(x,y))<<" "<<find(get(x+dx[k],y+dy[k]))<<"#$#$\n";
							if(find(get(x,y))!=find(get(x+dx[k],y+dy[k])))fa[find(get(x,y))]=get(x+dx[k],y+dy[k]),sum--;
						}
					}
				}
			}
			
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)cout<<s[i][j]<<" \n"[j==m];
//		puts("");
		
//			cerr<<sum<<" "<<k<<" "<<ans[10]<<"@#@#\n";
			ans[k]+=sum;
		}
//		cerr<<i<<" "<<j<<"@@\n";
		i=j;
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}