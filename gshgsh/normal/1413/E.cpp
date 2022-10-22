#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
ll T,a,b,c,d,t;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(ll x){if(x<0)return putchar('-'),put(-x);if(x>=10)put(x/10);putchar(x%10+'0');}
int main(){T=get();while(T--)a=get(),b=get(),c=get(),d=get(),t=(a-1)/b/d,put(a<=1ll*b*c?1ll*(t+1)*a-1ll*b*d*(t+1)*t/2:-1),putchar('\n');return 0;}