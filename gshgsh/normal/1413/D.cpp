#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,cnt,tot,s[MAXN],ans[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
char getc(){char c=getchar();while(c!='+'&&c!='-')c=getchar();return c;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int main(){N=get();For(i,1,N*2)if(getc()=='+')s[++tot]=++cnt;else {int x=get();if(!tot||x<ans[s[tot]+1]){cout<<"NO\n";return 0;}ans[s[tot--]]=x;}cout<<"YES\n";For(i,1,N)put(ans[i]),putchar(' ');return 0;}