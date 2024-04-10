#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define ull unsigned ll 
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
const int xx=1005;
int n,a[xx],prim[xx],cnt;
int f[105][63][1025],s[xx];
void ad(int &x,int y){x=min(x,y);}
int rem[xx],id[xx];
char pr[105][63][1025];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return a[x]<a[y];});
	sort(a+1,a+n+1);
	
	int cnt=0;
	for(int i=2;i<=1000;i++)
	{
		int cr=1;
		for(int j=2;j<i;j++)
			if(i%j==0)cr=0;
		if(cr)prim[++cnt]=i;
	}
	memset(f,0x3f,sizeof(f));
	f[1][1][0]=0;
	//  
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=cnt;j++)
		{
			if(i%prim[j]==0)
			{
				if(prim[j]>30)
				{
					s[i]=-1;
					break;
				}
				s[i]+=(1<<(j-1));
			}
		}
	}
	int ans=1e9,nx=0,ny=0,nz=0;
	for(int i=1;i<=n;i++)
	{
		int j=11;
		for(int k=n-i+1;k<=n;k++)
			rem[i]+=abs(a[k]-prim[j++]);
	}
	for(int i=1;i<=n+1;i++)
	{
//		cerr<<i<<"$$\n";
		for(int j=1;j<=61;j++)
		{
			for(int k=0;k<1024;k++)
			{
				if(f[i][j][k]>=1e9)continue;
				ans=min(ans,f[i][j][k]+rem[n+1-i]);
				if(ans==f[i][j][k]+rem[n+1-i])nx=i,ny=j,nz=k;
				if(i==n+1)continue;
				ad(f[i][j+1][k],f[i][j][k]);
				if(f[i][j+1][k]==f[i][j][k])pr[i][j+1][k]=2;
				if(s[j]!=-1&&((s[j]&k)==0))
				{
					ad(f[i+1][j][k+s[j]],f[i][j][k]+abs(a[i]-j));
					if(f[i+1][j][k+s[j]]==f[i][j][k]+abs(a[i]-j))pr[i+1][j][k+s[j]]=1;
				}
			}
		}
//		cerr<<i<<"$$\n";
	}
//	cerr<<nx<<" "<<ny<<" "<<nz<<" "<<f[nx][ny][nz]<<" "<<(int)pr[nx][ny][nz]<<"%%\n";
	vector<int>te;
	int j=11;
	for(int i=nx;i<=n;i++)te.push_back(prim[j++]);
	while(pr[nx][ny][nz])
	{
//		cerr<<nx<<" "<<ny<<" "<<nz<<"$$\n";
		if(pr[nx][ny][nz]==1)te.push_back(ny),nz-=s[ny],nx--;
		else ny--;
	}
	sort(te.begin(),te.end());
	int lp=0;
	vector<int>ANS(n+2);
	for(int i=1;i<=n;i++)ANS[id[i]]=te[lp++];
	for(int i=1;i<=n;i++)
		cout<<ANS[i]<<" ";
	puts("");
//	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}