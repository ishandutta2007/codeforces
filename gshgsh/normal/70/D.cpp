#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define F first
#define S second
int N;map<int,int>a,b;
ll cross(int x1,int y1,int x2,int y2){return 1ll*x1*y2-1ll*x2*y1;}
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'?f=-1:0,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check1(int x,int y){auto i=a.lower_bound(x);if(i==a.end())return 0;if(i->F==x)return y<=i->S;if(i==a.begin())return 0;auto j=i;j--;return cross(i->F-j->F,i->S-j->S,x-j->F,y-j->S)<=0;}
bool check2(int x,int y){auto i=b.lower_bound(x);if(i==b.end())return 0;if(i->F==x)return y>=i->S;if(i==b.begin())return 0;auto j=i;j--;return cross(i->F-j->F,i->S-j->S,x-j->F,y-j->S)>=0;}
void ins1(int x,int y)
{
	if(check1(x,y))return;a[x]=y;
	auto i=a.lower_bound(x);if(i!=a.begin())i--;while(i!=a.begin()){auto j=i;j--;if(cross(i->F-j->F,i->S-j->S,x-i->F,y-i->S)<0)break;a.erase(i);i=a.lower_bound(j->F);}
	i=a.lower_bound(x);i++;while(i!=a.end()){auto j=i;j++;if(j==a.end())break;if(cross(j->F-i->F,j->S-i->S,i->F-x,i->S-y)>0)break;a.erase(i);i=a.lower_bound(j->F);}
}
void ins2(int x,int y)
{
	if(check2(x,y))return;b[x]=y;
	auto i=b.lower_bound(x);if(i!=b.begin())i--;while(i!=b.begin()){auto j=i;j--;if(cross(i->F-j->F,i->S-j->S,x-i->F,y-i->S)>0)break;b.erase(i);i=b.lower_bound(j->F);}
	i=b.lower_bound(x);i++;while(i!=b.end()){auto j=i;j++;if(j==b.end())break;if(cross(j->F-i->F,j->S-i->S,i->F-x,i->S-y)<0)break;b.erase(i);i=b.lower_bound(j->F);}
}
int main(){N=get();For(i,1,N){int opt=get(),x=get(),y=get();opt&1?ins1(x,y),ins2(x,y),0:(cout<<(check1(x,y)&&check2(x,y)?"YES\n":"NO\n"),0); }return 0;}