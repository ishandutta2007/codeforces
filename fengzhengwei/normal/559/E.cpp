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
	wt(x),pc(op,0);
}
const int xx=105+5;
int n;
struct nod
{
	int id,len;
	bool operator<(const nod&w)const{return id<w.id;}
}e[xx];
int f[xx][xx],g[xx];//gx 
void ad(int &a,int b){a=max(a,b);}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		e[i].id=read(),e[i].len=read();
	sort(e+1,e+n+1);
	// 
	// 
	// 
	memset(f,-0x3f,sizeof(f));
	memset(g,-0x3f,sizeof(g));
	e[0].id=-1e9;
	f[0][0]=0;
	for(int i=0;i<=n;i++)
	{
		if(i)// 
		{
			int tid=0;
			for(int z=i-1;z>=0;z--)if(e[z].id<e[i].id-e[i].len){tid=z;break;}
			//fuck 
			for(int y=i-1;y>=tid;y--)
			{
				for(int z=i-1;z>tid;z--)
				{
					if(y<=z)ad(f[i][y],f[z][y]+e[i].id-e[z].id);
					else ad(f[i][y],g[z]+e[i].id-e[z].id);
				}
			}
			for(int z=i-1;z>tid;z--)ad(f[i][0],g[z]+e[i].id-e[z].id);
			//y 
			int Id=0;
			for(int y=i-1;y>tid;y--)if(!Id||e[y].id+e[y].len>e[Id].id+e[Id].len)Id=y;// 
//			cerr<<i<<" "<<tid<<"AWDSD\n";
			for(int y=tid;y>=0;y--)
			{
				if(e[i].id-e[i].len<=e[y].id+e[y].len)ad(f[i][Id],f[tid][y]+e[i].id-e[tid].id);
				else ad(f[i][Id],f[tid][y]+e[i].len+max(0,e[y].id+e[y].len-e[tid].id));
			}
		}
		if(i!=n)
		{
			for(int j=0;j<=n;j++)
			{
				if(f[i][j]<-1e9)continue;
				// 
				ad(f[i+1][i+1],f[i][j]+max(0,min(e[i+1].id-e[i].id,e[j].id+e[j].len-e[i].id)));
				ad(f[i+1][j],f[i][j]+max(0,min(e[i+1].id-e[i].id,e[j].id+e[j].len-e[i].id)));
				//j 
			}
		}
//		for(int j=0;j<=n;j++)if(f[i][j]>=0)cout<<i<<" "<<j<<' '<<f[i][j]<<"!!\n";
		for(int j=0;j<=n;j++)g[i]=max(g[i],f[i][j]);
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,f[n][i]+max(0,e[i].id+e[i].len-e[n].id));
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}