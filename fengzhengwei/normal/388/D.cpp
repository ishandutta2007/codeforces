#include<bits/stdc++.h>
#define ll long long
using namespace std;
//char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=35;
const int mod=1e9+7;
int f[xx][xx][2];
void add(int &x,ll y){y%=mod,x+=y,x%=mod;}
signed main(){
	n=read();
	int x=n?log2(n):-1;
	x++;
	f[x][0][1]=1;//ij 
	for(int i=x;i>0;i--)
	{
		for(int j=0;j<=x;j++)
		{
			for(int k=0;k<=1;k++)
			{
				if(!f[i][j][k])continue;
				if(!k)
				{
					add(f[i-1][j+1][k],f[i][j][k]);
					add(f[i-1][j][k],f[i][j][k]*(1ll<<j));
				}
				else 
				{
					if(n>>(i-1)&1)
					{
						add(f[i-1][j][0],f[i][j][k]*(1ll<<(j-1+(j==0))));
						add(f[i-1][j][1],f[i][j][k]*((1ll<<j)-(1ll<<(j-1+(j==0)))));
						add(f[i-1][j+1][1],f[i][j][k]);
					}
					else add(f[i-1][j][k],f[i][j][k]*(1ll<<(j-1+(j==0))));
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<=x;j++)
		for(int k=0;k<=1;k++)add(ans,f[0][j][k]);
	cout<<ans<<"\n";
	return 0;
}