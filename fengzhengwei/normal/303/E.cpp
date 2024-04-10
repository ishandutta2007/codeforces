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
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
// 
const int xx=205;
struct nod{int l,r;}e[xx<<1];
int n,A,lsh[xx],tt,L[xx],R[xx];
//len=r-l 
dd p[xx][xx],f[xx],g[82][82],cf[xx];
dd ans[82][82],cur[82][82][82];
int N=0;
// 
void solve(int l,int r,int d)
{
//	cout<<A<<" "<<l<<" "<<r<<" "<<d<<"ASD\n";
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			cur[d][i][j]=g[i][j];
	if(l==r)
	{
		int i=l;
//		cout<<i<<" "<<A<<"SDF\n";
		if(!(L[i]<=A&&A<R[i]))return;
//		cout<<i<<" "<<A<<"SDF\n";
		memset(f,0,sizeof(f));
		for(int I=0;I<n;I++)
			for(int J=0;J<n;J++)
			{
				if(g[I][J]<1e-9)continue;
				dd dlt=g[I][J]*1.0l/(J+1)*(lsh[A+1]-lsh[A])/(e[i].r-e[i].l);
//				cout<<i<<" "<<A<<" "<<I<<" "<<J<<" "<<g[I][J]<<" "<<dlt<<"!!\n";
				cf[I]+=dlt,cf[I+J+1]-=dlt;
			}
		for(int j=1;j<=n;j++)cf[j]+=cf[j-1];
		for(int j=0;j<=n;j++)f[j]+=cf[j];
//		for(int j=0;j<=n;j++)cout<<i<<" "<<j<<" ss "<<f[j]<<"!!\n";
		for(int j=0;j<=n;j++)cf[j]=0;
		for(int j=0;j<=n;j++)ans[i][j]+=f[j];
		return;
	}
	int pn=N;
	int mid=l+r>>1;
	for(int j=mid+1;j<=r;j++)
	{
		dd Psm=max(0.0l,1.0l*(min(lsh[A],e[j].r)-e[j].l)/(e[j].r-e[j].l)),Peq=0;
		if(L[j]<=A&&A<R[j])Peq=1.0l*(lsh[A+1]-lsh[A])/(e[j].r-e[j].l);
		dd rem=(1.0l-Psm-Peq);
		//~Peq0IJ+1 
		//a 
		///fn 
		for(int I=n;I>=0;I--)
		{
			for(int J=n;J>=0;J--)
			{
				g[I+1][J]+=g[I][J]*Psm;
				g[I][J+1]+=g[I][J]*Peq;
				g[I][J]*=rem;
			}
		}
		++N;
	}
	solve(l,mid,d+1);
	N=pn;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)g[i][j]=cur[d][i][j];
	for(int j=l;j<=mid;j++)
	{
		dd Psm=max(0.0l,1.0l*(min(lsh[A],e[j].r)-e[j].l)/(e[j].r-e[j].l)),Peq=0;
		if(L[j]<=A&&A<R[j])Peq=1.0l*(lsh[A+1]-lsh[A])/(e[j].r-e[j].l);
		dd rem=(1.0l-Psm-Peq);
		//~Peq0IJ+1 
		//a 
		for(int I=n;I>=0;I--)
		{
			for(int J=n;J>=0;J--)
			{
				g[I+1][J]+=g[I][J]*Psm;
				g[I][J+1]+=g[I][J]*Peq;
				g[I][J]*=rem;
			}
		}
		++N;
	}
	solve(mid+1,r,d+1);
	N=pn;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)g[i][j]=cur[d][i][j];
	//a 
}
int main(){
	// 120 
	
//	freopen("b.out","w",stdout);
//	mt19937 G(218);
	n=read();
	for(int i=1;i<=n;i++)e[i].l=read(),e[i].r=read(),lsh[++tt]=e[i].l,lsh[++tt]=e[i].r;
//	for(int i=1;i<=n;i++)e[i].l=i,e[i].r=i+G()%100,lsh[++tt]=e[i].l,lsh[++tt]=e[i].r;
//	for(int i=1;i<=n;i++)cout<<e[i].l<<" "<<e[i].r<<"ASDSAD\n";
	sort(lsh+1,lsh+tt+1);
	tt=unique(lsh+1,lsh+tt+1)-lsh-1;
	for(int i=1;i<=n;i++)
	{
		L[i]=lower_bound(lsh+1,lsh+tt+1,e[i].l)-lsh;
		R[i]=lower_bound(lsh+1,lsh+tt+1,e[i].r)-lsh;
	}
	//n 
	//1/8 
	//k 
	//n*n*
	//fijij 
	// 
	//80^5 a 
	// 
	// 
	// 
	// 
	//20 
	// 
	for(A=1;A<tt;A++)
	{
		memset(g,0,sizeof(g));
		g[0][0]=1;
		solve(1,n,0);
	}
		
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<fixed<<setprecision(6)<<(long double)ans[i][j]<<" ";
		puts("");
	}
	pc('1',1);
	return 0;
}