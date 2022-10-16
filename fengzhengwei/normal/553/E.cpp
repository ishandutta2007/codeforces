#include<bits/stdc++.h>
#define ll long long 
//#define int long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
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
	wt(x),pc(op,0);
}
const int xx=2e5+50;
int n,m;
struct nod
{
	int next,to,v;
	dd p[xx/10];
}e[105];
int cnt,h[xx];
int add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;return cnt;}// 
struct com
{
	dd x,y;
	com operator+(const com&w)const{return {x+w.x,y+w.y};}
	com operator*(const com&w)const{return {x*w.x-y*w.y,x*w.y+y*w.x};}
	com operator-(const com&w)const{return {x-w.x,y-w.y};}
};
com A[xx];
int rev[xx],N;
int make(int n)
{
	int t=ceil(log2(n));
	N=(1<<t);
	for(int i=1;i<N;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(t-1));
	return N;
}
const dd pi=3.14159265358979323846264338327950288;
com w[xx];
void FFT(com*A,int n,int f)
{
	for(int i=0;i<n;i++)if(rev[i]<i)swap(A[i],A[rev[i]]);
	w[0]={1,0};
	for(int i=1;i<n;i<<=1)
	{
		com c={cos(pi/i),f*sin(pi/i)};
		for(int j=i-2;j>=0;j-=2)w[j]=w[j>>1],w[j|1]=w[j]*c;
		for(int j=0;j<n;j+=(i<<1))
		{
			for(int k=j;k<j+i;k++)
			{
				com x=A[k],y=A[k+i]*w[k-j];
				A[k]=x+y,A[k+i]=x-y;
			}
		}
	}
	if(f==-1)
		for(int i=0;i<n;i++)A[i].x/=n;
}
com U[xx],V[xx],T[xx];
dd out(dd w){return abs(w)<1e-7?0:w;
}
void mul(com*A,com*B,com*C,int n)
{
	make(n);
//	for(int i=0;i<N;i++)
//		cout<<out(A[i].x)<<" ";
//	puts("");
//	for(int i=0;i<N;i++)
//		cout<<out(B[i].x)<<" ";
//	puts("");
	FFT(A,N,1),FFT(B,N,1);
	for(int i=0;i<N;i++)C[i]=A[i]*B[i];
	FFT(C,N,-1);
//	for(int i=0;i<N;i++)
//		cout<<out(C[i].x)<<" ";
//	puts("");
//	puts("");
//	puts("");
//	puts("");
}
com f[55][xx];
int dis[55][55];
int vis[55],X,t;
signed main(){
	memset(dis,0x3f,sizeof(dis));
	n=read(),m=read(),t=read(),X=read();
	//dis 
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		dis[a][b]=min(dis[a][b],c);
		int id=add(b,a,c);
		for(int j=1;j<=t;j++)
			e[id].p[j]=read()/100000.0;
		//add(a,b);
	}
	for(int k=1;k<=n;k++)dis[k][k]=0;
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=t+t;j++)
			f[i][j]={dis[i][n]+X,0};
//			,cerr<<i<<" "<<dis[i][n]<<"$\n";;
		if(i==n)
			for(int j=0;j<=t;j++)f[i][j]={0,0};
		q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();vis[x]=0;
		for(int i=h[x];i;i=e[i].next)
		{
			int to=e[i].to;
			for(int j=0;j<=t+t;j++)
				U[j]=f[x][j];
			for(int j=0;j<=t;j++)
				V[j]={e[i].p[t-j],0};
			for(int j=t+t+1;j<N;j++)U[j]={0,0};
			for(int j=t+1;j<N;j++)V[j]={0,0};
			mul(U,V,T,t+t+t);
			int cr=0;
			for(int j=0;j<=t;j++)
			{
				if(f[to][j].x>T[j+t].x+e[i].v)cr=1;
//				cerr<<T[j+t].x<<" "<<T[j+t].y<<"#\n";
				f[to][j].x=min(f[to][j].x,T[j+t].x+e[i].v);
			}
			if(cr&&!vis[to])vis[to]=1,q.push(to);
		}
	}
	cout<<fixed<<setprecision(6)<<f[1][0].x<<"\n";
	pc('1',1);
	return 0;
}