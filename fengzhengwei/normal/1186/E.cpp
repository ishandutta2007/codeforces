#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
int n,m,q;
const int xx=1005;
struct one
{
	int v[xx][xx],sum[xx][xx];
	void pre()
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				sum[i][j]=sum[i][j-1]+sum[i-1][j]+v[i][j]-sum[i-1][j-1];
	}
}a,_a;
struct pr
{
	ll x,y;
	pr(){}pr(ll a,ll b):x(a),y(b){}
	pr operator+(const pr&w)const{return pr(x+w.x,y+w.y);}
	pr operator~()const{return pr(y,x);}
	pr operator-()const{return pr(-x,-y);}
	pr operator*(const pr&w)const{return pr(x*w.x+y*w.y,x*w.y+y*w.x);}
	void print(){cout<<x<<" QwQ "<<y<<"\n";}
};
pr G(int x)//xAA' 
{
	if(!x)return pr(0,0);
	if(x==1)return pr(1,0);
	int w=log2(x);
	return pr((1<<(w-1)),(1<<(w-1)))+~G(x-(1<<w));
}
ll num(int x,int y,pr c){return c.x*a.sum[x][y]+c.y*_a.sum[x][y];}
ll get(int x,int y)
{
	if(!x||!y)return 0;
	if(x<=n&&y<=m)return a.sum[x][y];
	int r=(x-1)/n,c=(y-1)/m;
	pr C=G(c),ny=G(c+1)+(-C);
	pr R=G(r),nx=G(r+1)+(-R);
	//row column
	int X=x-r*n,Y=y-c*m;
	// 
/*	if(!r)return num(X,m,C)+num(X,Y,ny);
	if(!c)return num(n,Y,R)+num(X,Y,nx);*/
	return num(n,m,C*R)+num(X,m,C*nx)+num(n,Y,R*ny)+num(X,Y,nx*ny);
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			while((c=getchar())!='0'&&c!='1');
			a.v[i][j]=c-'0';
			_a.v[i][j]=!(c-'0');
		}
	}
	a.pre();_a.pre();
	while(q--)
	{
		int a=read(),b=read(),c=read(),d=read();
		cout<<get(c,d)+get(a-1,b-1)-get(a-1,d)-get(c,b-1)<<"\n";
	}
	pc('1',1);
	return 0;
}