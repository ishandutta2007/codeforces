#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 200001
int N,M,a[MAXN];ll c[MAXN],sum,fc[20];bool vis[20];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(ll x){if(x>=10)put(x/10);putchar(x%10+'0');}
void upd(int x,int v){for(int i=x;i<=N;i+=lowbit(i))c[i]+=v;}ll ask(int x){ll ans=0;for(int i=x;i;i-=lowbit(i))ans+=c[i];return ans;}
void upd1(ll x){For(i,1,N)vis[i]=0;For(i,1,N){int id=0,cnt=0;while(cnt<=x/fc[N-i]){id++;while(vis[id])id++;cnt++;}vis[id]=1,upd(i,id-a[i]),a[i]=id,x%=fc[N-i];}}
void upd2(ll x){For(i,1,15)vis[i]=0;For(i,1,15){int id=0,cnt=0;while(cnt<=x/fc[15-i]){id++;while(vis[id])id++;cnt++;}vis[id]=1,upd(N-15+i,N-15+id-a[N-15+i]),a[N-15+i]=N-15+id,x%=fc[15-i];}}
void sol1(){For(i,1,M){int opt=get(),x=get(),y;opt==1?put(ask(y=get())-ask(x-1)),putchar('\n'),0:(upd1(sum+=x),0);}}
void sol2(){For(i,1,M){int opt=get(),x=get(),y;opt==1?put(ask(y=get())-ask(x-1)),putchar('\n'),0:(upd2(sum+=x),0);}}
int main(){N=get(),M=get();For(i,1,N)a[i]=i,upd(i,i);fc[0]=1;For(i,1,15)fc[i]=fc[i-1]*i;N<=15?sol1():sol2();return 0;}