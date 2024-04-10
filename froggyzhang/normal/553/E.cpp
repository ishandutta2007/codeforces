#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const double eps=1e-7;
const double inf=0x3f3f3f3f;
const double PI=acos(-1.0);
#define N 80070
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,t,X,tr[N];
struct Edge{
	int x,y,z;
}L[110]; 
double dis[55][55],p[110][40020],dp[55][N],h[105][N];
int FFT_init(int n){
	int lim=1;
	while(lim<n)lim<<=1;
	for(int i=0;i<lim;++i){
		tr[i]=((tr[i>>1]>>1)|((i&1)?lim>>1:0));
	}
	return lim;
}
struct Complex{
	double x,y;
	Complex(double _x=0,double _y=0){x=_x,y=_y;}
	inline Complex operator +(const Complex b)const{
		return Complex(x+b.x,y+b.y);
	}
	inline Complex operator -(const Complex b)const{
		return Complex(x-b.x,y-b.y);
	}
	inline Complex operator *(const Complex b)const{
		return Complex(x*b.x-y*b.y,x*b.y+y*b.x);
	}
};
void FFT(Complex *f,int flag,int n){
	for(int i=0;i<n;++i){
		if(i<tr[i])swap(f[i],f[tr[i]]);
	}
	for(int p=2;p<=n;p<<=1){
		int len=(p>>1);
		Complex wn(cos(2*PI/p),sin(2*PI/p));
		if(!flag)wn.y*=-1;
		for(int k=0;k<n;k+=p){
			Complex buf(1,0);
			for(int i=k;i<k+len;++i){
				Complex tmp=f[i+len]*buf;
				f[i+len]=f[i]-tmp;
				f[i]=f[i]+tmp;
				buf=buf*wn;
			}
		}
	}
	if(!flag){
		for(int i=0;i<n;++i){
			f[i].x/=n;
		}
	}
}
void Mul(Complex *_f,Complex *_g,Complex *p,int n,int m){
	int lim=FFT_init(n+m);
	static Complex f[N],g[N];
	for(int i=0;i<n;++i)f[i]=_f[i];
	for(int i=0;i<m;++i)g[i]=_g[i];
	for(int i=n;i<lim;++i)f[i]=0;
	for(int i=m;i<lim;++i)g[i]=0;
	for(int i=0;i<lim;++i)p[i]=0;
	FFT(f,1,lim),FFT(g,1,lim);
	for(int i=0;i<lim;++i){
		p[i]=f[i]*g[i];
	}
	FFT(p,0,lim);
}
inline void calc(int l,int r){
	int mid=(l+r)>>1;
	for(int e=1;e<=m;++e){
		static Complex f[N],g[N],myh[N];
		for(int i=1;i<=r-l;++i){
			f[i]=Complex(p[e][r-l-i+1],0);
		} 
		for(int i=mid+1;i<=r;++i){
			g[i-mid-1]=Complex(dp[L[e].y][i],0);
		}
		Mul(f,g,myh,r-l+1,r-mid);
		for(int i=l;i<=mid;++i){
			h[e][i]+=myh[i-l+r-mid].x;
		}
	}
} 
void Solve(int l,int r){
	if(l==r){
		for(int i=1;i<=m;++i){
			dp[L[i].x][l]=min(dp[L[i].x][l],h[i][l]+L[i].z);
		}
		return;
	}
	int mid=(l+r)>>1;
	Solve(mid+1,r);
	calc(l,r);
	Solve(l,mid);
}
int main(){
	n=read(),m=read(),t=read(),X=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;++i){
		L[i].x=read(),L[i].y=read(),L[i].z=read();
		dis[L[i].x][L[i].y]=min(dis[L[i].x][L[i].y],L[i].z*1.0);
		for(int j=1;j<=t;++j){
			p[i][j]=read()/100000.0;
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=t+1;i<=(t<<1);++i){
		dp[n][i]=X;
	}
	for(int i=1;i<n;++i){
		for(int j=0;j<=t;++j){
			dp[i][j]=inf;
		}
		for(int j=t+1;j<=(t<<1);++j){
			dp[i][j]=dis[i][n]+X;
		}
	}
	calc(1,t<<1);
	Solve(0,t);
	printf("%.8lf\n",dp[1][0]);
	return 0;
}