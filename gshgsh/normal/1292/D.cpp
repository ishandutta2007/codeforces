#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 5001
int N,M,cnt[MAXN][MAXN],siz[MAXN],mx[MAXN],f[MAXN];ll ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int main()
{
	N=get();For(i,1,N){int x=get();M=max(M,x),siz[x]++;}For(i,1,M){int x=i;For(j,2,i){cnt[i][j]+=cnt[i-1][j];while(x%j==0)x/=j,cnt[i][j]++;if(cnt[i][j])mx[i]=j;ans+=1ll*siz[i]*cnt[i][j];}}
	while(1)
	{
		For(i,1,M)f[i]=0;For(i,1,M)f[mx[i]]+=siz[i];int p=2;For(i,2,M)if(f[i]>f[p])p=i;if(f[p]*2<=N)break;
		ans+=N-f[p]*2;For(i,1,M)if(mx[i]!=p)mx[i]=1;else{cnt[i][mx[i]]--;while(mx[i]>1&&!cnt[i][mx[i]])mx[i]--;}
	}
	cout<<ans<<endl;return 0;
}