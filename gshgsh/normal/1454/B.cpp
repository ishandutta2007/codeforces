#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN],cnt[MAXN],ans,id;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x<0)return putchar('-'),put(-x);if(x>=10)put(x/10);putchar(x%10+'0');}
int main(){T=get();while(T--){N=get();For(i,1,N)cnt[a[i]=get()]++;ans=MAXN;For(i,1,N)if(cnt[a[i]]==1&&a[i]<ans)ans=a[i],id=i;For(i,1,N)cnt[a[i]]=0;put(ans<MAXN?id:-1),putchar('\n');}return 0;}