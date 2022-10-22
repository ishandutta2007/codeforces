#include<cstdio>
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 2000001
int T,N,f[MAXN];int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>9)put(x/10);putchar(x%10+'0');}
int main(){T=get(),N=MAXN-1;For(i,1,N){if(i%6==3||i%6==5)f[i]=(f[i-1]*2+1)%P;else if(i%6==4)f[i]=(f[i-1]*2-1)%P;else f[i]=f[i-1]*2%P;}while(T--)N=get(),put(1ll*f[N]*4%P),putchar('\n');return 0;}