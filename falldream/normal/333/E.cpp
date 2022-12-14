#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MD 12
#define MN 6000
const double pi=acos(-1);
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct P{int x,y;double slop;
	P(){}
	P(int _x,int _y):x(_x),y(_y){slop=atan2(_y,_x);}
	int operator ^ (const P&b){return x*b.y-y*b.x;}
}p[MN+5];
bool cmp(const P&a,const P&b) {return a.slop<b.slop;} 
int X[MN+5],Y[MN+5],n,Lg[MN+5];double ans=0,f[MD+1][MN+5];
inline int sqr(int x){return x*x;}
inline double Query(int l,int r)
{
	int s=Lg[r-l+1];
	return max(f[s][l],f[s][r-(1<<s)+1]);	
}
inline double Calc(int l,int r)
{
	double a=sqr(p[l].x-p[r].x)+sqr(p[l].y-p[r].y);
	//double b=sqr(p[l].x)+sqr(p[l].y);
	//	double c=sqr(p[r].x)+sqr(p[r].y);
	return acos((f[0][l]*f[0][l]+f[0][r]*f[0][r]-a)/2/f[0][l]/f[0][r]); 
}
int main()
{
//	freopen("1.in","r",stdin);
	n=read();Lg[0]=-1;
	for(int i=1;i<=n*2;++i) Lg[i]=Lg[i>>1]+1;
	for(int i=1;i<=n;++i) X[i]=read(),Y[i]=read();
	for(register int ii=1;ii<=n;++ii)
	{
		int top=0;
		for(register int j=1;j<=n;++j) if(ii!=j) p[++top]=P(X[j]-X[ii],Y[j]-Y[ii]);
		sort(p+1,p+top+1,cmp);
	//	cout<<"BeginSolve"<<ii<<endl;
	//	for(int i=1;i<=top;++i) printf("%d %d %.5lf\n",p[i].x,p[i].y,p[i].slop);
		memset(f,0,sizeof(f));
		for(register int i=1;i<=top;++i) p[i+top]=p[i],f[0][i+top]=f[0][i]=sqrt(sqr(p[i].x)+sqr(p[i].y));
		for(int i=1;i<=MD;++i) for(register int j=1;j<=top<<1;++j) if(j+(1<<i)-1<=top<<1) f[i][j]=max(f[i-1][j],f[i-1][j+(1<<i-1)]);
		for(register int i=top+1,j=2,k=2;i<=top<<1;++i)
		{	
			j=max(j,i-top+1);k=max(k,i-top+1);
			while(j<i&&((p[i]^p[j])>0||p[i].slop==p[j].slop)) ++j;
			while(k<i&&((p[i]^p[k])>0||p[i].slop==p[k].slop)) ++k;
			while(j<i&&Calc(j+1,i)>=pi/3) ++j; 
		//	cout<<i<<" "<<k<<" "<<j<<" "<<Calc(j,i)/pi*180<<endl;
			if(f[0][i]>ans&&j<i&&Calc(j,i)>=pi/3&&k<=j) 
			{
			//	if(min(Query(k,j),f[0][i])>=5040.9999*2&&X[1]==-4957)
			//	{
			//		printf("i=%d %d %d %d %d %.10lf [%d %d] %d %d %d %d",i,X[ii],Y[ii],p[i].x,p[i].y,f[0][i],k,j,p[k].x,p[k].y,p[j].x,p[j].y);
			//	}
				ans=max(ans,min(Query(k,j),f[0][i]));
			}
		}
	}
	printf("%.10lf",ans/2);
	return 0;
}