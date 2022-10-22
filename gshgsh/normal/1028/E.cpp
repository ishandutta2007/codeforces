#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,a[MAXN];ll ans[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();int mx=0;For(i,1,N)mx=max(mx,a[i]);
	int pos=0;For(i,1,N)if(a[i]==mx&&a[(i+N-2)%N+1]<mx){pos=i;break;}
	if(!pos){if(!mx){cout<<"YES\n";For(i,1,N)cout<<"1 ";}else cout<<"NO\n";return 0;}
	int x=pos;ans[x]=a[x]*2;For(i,1,N-1){x--;if(!x)x=N;ans[x]=ans[x%N+1]+a[x];}ans[pos]=a[pos];
	cout<<"YES\n";For(i,1,N)cout<<ans[i]<<" \n"[i==N];return 0;
}