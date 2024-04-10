#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void getres(int x){For(i,1,x)if(x%i==0)cout<<i<<' ';cout<<'\n';}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();vector<int>x;
		For(i,0,29){int cnt=0;For(j,1,N)cnt+=(a[j]>>i)&1;if(cnt)x.push_back(cnt);}
		if(!x.empty()){int ans=x[0];for(auto i:x)ans=__gcd(ans,i);getres(ans);}else For(i,1,N)cout<<i<<" \n"[i==N];
	}
	return 0;
}