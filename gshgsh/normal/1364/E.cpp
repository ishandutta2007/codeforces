#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 3001
int N,p[MAXN],ans[MAXN];mt19937 rnd(time(0));
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int ask(int x,int y){cout<<"? "<<x<<' '<<y<<endl;return get();}
int rndnot(int x){int y=rnd()%N+1;if(y!=x)return y;return rndnot(x);}
int getval(int x){int ans=(1<<11)-1;For(i,1,15)ans&=ask(x,rndnot(x));return ans;}
int main()
{
	N=get();For(i,1,N)p[i]=i;shuffle(p+1,p+N+1,rnd);
	int x=p[1],val=getval(x);For(i,2,N)if(ask(x,p[i])==val)x=p[i],val=getval(x);
	For(i,1,N)if(i!=x)ans[i]=ask(x,i);cout<<"! ";For(i,1,N)cout<<ans[i]<<' ';cout<<endl;return 0;
}