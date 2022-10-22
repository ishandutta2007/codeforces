#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN],cnt[MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int main(){T=get();while(T--){N=get();For(i,1,N)a[i]=get(),cnt[a[i]]=1;N=unique(a+1,a+N+1)-a-1;ans=N+1;For(i,1,N)cnt[a[i]]++;cnt[a[1]]--,cnt[a[N]]--;For(i,1,N)ans=min(ans,cnt[a[i]]);put(ans),putchar('\n');}return 0;}