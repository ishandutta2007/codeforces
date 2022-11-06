#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define N 310
using namespace std;
struct node{
	ll x,y;
	node(ll X=0,ll Y=0):x(X),y(Y){}
	node operator +(const node a)const{return node(x+a.x,y+a.y);}
	node operator -(const node a)const{return node(x-a.x,y-a.y);}
	node operator *(const ll a)const{return node(x*a,y*a);}
	ll operator *(const node a)const{return x*a.x+y*a.y;}
	ll operator ^(const node a)const{return x*a.y-y*a.x;}
	bool operator <(const node a)const{return x==a.x?y<a.y:x<a.x;}
}p[N],s[N];
double slope(const node a){return atan2(a.y,a.x);}
double dis(const node a){return sqrt(a.x*a.x+a.y*a.y);}
long long cross(const node a,const node o,const node b){return (a-o)^(b-o);}
bool cmp(const node a,const node b){return slope(a)>slope(b);}
ll f[5][N][N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&p[i].x,&p[i].y);
	sort(p+1,p+n+1);
	ll ans=0;
	for(int u=1;u<=n;u++)
	{
		int pn=0;
		memset(f,0,sizeof(f));
		for(int i=u;i<=n;i++) s[++pn]=p[i]-p[u];
		sort(s+2,s+pn+1,cmp);
		for(int i=2;i<=pn;i++) f[1][i][1]=1;
		for(int l=1;l<=3;l++)
            for(int i=l+1;i<=pn;i++)
	            for(int j=1;j<i;j++)
	            if(f[l][i][j])
	                for(int k=i+1;k<=pn;k++)
						if(cross(s[i],s[j],s[k])<0)
						f[l+1][k][i]+=f[l][i][j];
		for(int i=1;i<=pn;i++)
			for(int j=1;j<i;j++)
				if(cross(s[i],s[j],s[1])<0)
				ans+=f[4][i][j];
	}
	printf("%lld",ans);
	return 0;
}