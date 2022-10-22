#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 400001
int N,a[MAXN],b[MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int work(int l,int r){int ans=0;For(i,1,N-1){int x=lower_bound(b+i+1,b+N+1,l-b[i])-b,y=upper_bound(b+i+1,b+N+1,r-b[i])-b-1;if(y>=x)ans^=y-x+1&1;}return ans;}
int solve(int x){For(i,1,N)b[i]=a[i]&((1<<x+1)-1);sort(b+1,b+N+1);return work(1<<x,(1<<x+1)-1)^work(3<<x,(1<<x+2)-2);}
int main(){N=get();For(i,1,N)a[i]=get();For(i,0,24)ans|=solve(i)<<i;cout<<ans<<endl;return 0;}