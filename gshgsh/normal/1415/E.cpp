#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 500001
int N,K,a[MAXN];ll ans;priority_queue<ll>h;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'?f=-1:0,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main(){N=get(),K=get();For(i,0,K)h.push(0);For(i,1,N)a[i]=get();sort(a+1,a+N+1,greater<int>());For(i,1,N){ll x=h.top();h.pop();ans+=x;h.push(x+a[i]);}cout<<ans<<endl;return 0;}