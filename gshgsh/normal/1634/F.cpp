#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 500001
int N,Q,P,a[MAXN],b[MAXN],c[MAXN],d[MAXN],f[MAXN],cnt;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
char getc(){char c=getchar();while(c!='A'&&c!='B')c=getchar();return c;}
void add(int x,int v){if(x<=N)cnt-=d[x]==0,d[x]=(d[x]+v)%P,cnt+=d[x]==0;}
int main()
{
	N=get(),Q=get(),P=get();f[1]=f[2]=1;For(i,3,N)f[i]=(f[i-1]+f[i-2])%P;
	For(i,1,N)a[i]=get();For(i,1,N)b[i]=get();For(i,1,N)c[i]=(a[i]-b[i]+P)%P;d[1]=c[1],d[2]=(c[2]-c[1]+P)%P;For(i,3,N)d[i]=(c[i]-c[i-1]-c[i-2]+P*2ll)%P;For(i,1,N)cnt+=d[i]==0;
	while(Q--)
	{
		char opt=getc();int l=get(),r=get();
		if(opt=='A')add(l,1),add(r+1,P-f[r-l+2]),add(r+2,P-f[r-l+1]);
		else add(l,P-1),add(r+1,f[r-l+2]),add(r+2,f[r-l+1]);cout<<(cnt==N?"YES\n":"NO\n");
	}
}