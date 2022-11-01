#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<ctime>
#include<algorithm>
#define For(i,j,k)  for(register ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(register ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
#define eps 1e-8
#define pa pair<ll,ll>
#define fir first
#define sec second
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
double a,v,l,d,w,ans;
inline void spe(double v1)
{
	double res=l-d;
	w=v1;
	double t2=(v-w)/a;
	if(t2*(v+w)/2<=res)
	{
		res-=t2*(v+w)/2;
		ans+=t2+res/v;
	}else
	{
		ans+=(-2*w+sqrt(4*w*w+8*res*a))/(2*a);	
	}	
	printf("%.9lf",ans);
}
int main()
{
	a=read();v=read();
	l=read();d=read();w=read();
	if(w>v)
	{
		double dis=0;	
		double ans=0;
		dis=v*v/(2*a);
		double t=sqrt(2*l/a);
//		cout<<dis<<' '<<(v/a)<<' '<<(l-dis)/v<<endl;
		if(t*a>v)	ans=(v/a)+(l-dis)/v;
		else	
		{
			ans=sqrt(2*l/a);
		}
		printf("%.9lf\n",ans);
		return 0;
	}
	ans=0;
	double t=sqrt(2*d/a);
	if(t*a<=w)	ans+=t,spe(t*a);
	else
	{
		double t2=sqrt((2*d+w*w/a)/(2*a));
		if(t2*a<=v)
		{
			ans+=t2+(t2-w/a);
		}else
		{
			double x=0;
			double t1=0,t3=0;
			t1=v/a;x+=(v/2*t1);
			t3=(v-w)/a;x+=(v+w)/2*t3;
			ans+=(d-x)/v+t1+t3;
		}	
		double res=l-d;
		t2=(v-w)/a;
		if(t2*(v+w)/2<=res)
		{
			res-=t2*(v+w)/2;
			ans+=t2+res/v;
		}else
		{
			ans+=(-2*w+sqrt(4*w*w+8*res*a))/(2*a);	
		}	
		printf("%.9lf",ans);
	}	
}
/*
5744 5873
3706 1656 8898
*/