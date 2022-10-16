#include<bits/stdc++.h>
#define ll long long
#define dd long double
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
int get(int x1,int y1,int x2,int y2)
{
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
	fflush(stdout);
	return read();
}
int ans[55][55];
struct nod{int x,y;};
queue<nod>q;
int dx[]={-2,2,0,0,1,-1},dy[]={0,0,2,-2,1,-1},n;
void A(int x,int y)
{
//	cout<<x<<" "<<y<<"!!!ASD\n";
	for(int i=0;i<6;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<1||ty<1||tx>n||ty>n)continue;
		if(ans[tx][ty]==-1)
			ans[tx][ty]=ans[x][y]^(!get(min(tx,x),min(ty,y),max(tx,x),max(ty,y))),q.push({tx,ty});
	}
}
int main(){
	memset(ans,-1,sizeof(ans));
	n=read();// 
	ans[1][1]=1,ans[n][n]=0;
	q.push({1,1}),q.push({n,n});
	while(!q.empty())
	{
		int x=q.front().x,y=q.front().y;
		q.pop(),A(x,y);
	}
	int cr=0;
	// 
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(ans[i][j]==-1)continue;
			if(cr)continue;
			if(ans[i][j]!=ans[i-1][j+1])
			{
				cr=1;
				if(j>1)
					ans[i][j+1]=ans[i-1][j-1]^(!get(i-1,j-1,i,j+1));
				else 
					ans[i][j+1]=ans[i-2][j]^(!get(i-2,j,i,j+1));
				q.push({i,j+1});
			}
		}
	}
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			if(ans[i][j]==-1)continue;
			if(cr)continue;
			if(ans[i][j]!=ans[i+2][j+2])
			{
				cr=1;
				if(ans[i][j]!=ans[i+1][j+1])
				{
					int W=get(i,j+1,i+1,j+2);
					if(W==0)
					{
						ans[i+1][j+2]=ans[i][j]^(!get(i,j,i+1,j+2));
						q.push({i+1,j+2});
					}
					else 
					{
						ans[i][j+1]=ans[i+2][j+2]^(!get(i,j+1,i+2,j+2));
						q.push({i,j+1});
					}
				}
				else 
				{
					int W=get(i+1,j,i+2,j+1);
					if(W==0)
					{
						ans[i+1][j]=ans[i+2][j+2]^(!get(i+1,j,i+2,j+2));
						q.push({i+1,j});
//					assert(0);
					}
					else 
					{
						ans[i+2][j+1]=ans[i][j]^(!get(i,j,i+2,j+1));
						q.push({i+2,j+1});
					}
				}
			}
		}
	}
	while(!q.empty())
	{
		int x=q.front().x,y=q.front().y;
		q.pop(),A(x,y);
	}
	puts("!");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<ans[i][j];
		puts("");
	}
	pc('1',1);
	return 0;
}