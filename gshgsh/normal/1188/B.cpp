#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,P,k,a[MAXN];map<int,int>cnt;ll ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main(){N=get(),P=get(),k=get();For(i,1,N)a[i]=get();For(i,1,N){int x=(1ll*a[i]*a[i]%P*a[i]%P*a[i]-1ll*k*a[i]%P+P)%P;ans+=cnt[x],cnt[x]++;}cout<<ans<<'\n';return 0;}