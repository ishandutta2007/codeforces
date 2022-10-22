#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,cnt;long long N,x,id;
ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(ll x){if(x>=10)put(x/10);putchar(x%10+'0');}
int main(){T=get();while(T--){x=N=get();cnt=0;for(ll i=2;i*i<=N;i++)if(N%i==0){int tot=0;while(N%i==0)tot++,N/=i;if(tot>cnt)cnt=tot,id=i;}if(N>1&&!cnt)cnt=1,id=N;put(cnt);putchar('\n');For(i,1,cnt-1)put(id),x/=id,putchar(' ');put(x),putchar('\n');}return 0;}