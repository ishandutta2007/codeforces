#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define Pair pair<ll,ll>
#define F first
#define S second
#define MAXN 100001
int N;Pair a[MAXN];ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
bool cmp(Pair a,Pair b){return a.S<b.S;}
int main()
{
	N=get();For(i,1,N)a[i]={get(),get()};sort(a+1,a+N+1,cmp);int l=1,r=N;ll cnt=0,sum=0;
	while(l<=r)
	{
		if(cnt>=a[l].S)cnt+=a[l].F,sum+=a[l].F,l++;
		else{ll x=min(a[r].F,a[l].S-cnt);cnt+=x,a[r].F-=x,sum+=x<<1;if(!a[r].F)r--;}
	}
	cout<<sum<<endl;return 0;
}