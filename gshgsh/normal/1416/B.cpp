#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define Tair pair<Pair,int>
#define F first
#define S second
#define MAXN 10001
int T,N,a[MAXN];vector<Tair>ans;void opt(int x,int y,int v){a[x]-=x*v,a[y]+=x*v,ans.push_back({{x,y},v});}
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();int sum=0;For(i,1,N)sum+=a[i]=get();if(sum%N){cout<<"-1\n";continue;}ans.clear();
		For(i,2,N){if(a[i]%i)opt(1,i,i-a[i]%i);opt(i,1,a[i]/i);}For(i,2,N)opt(1,i,sum/N);cout<<ans.size()<<endl;for(auto i:ans)cout<<i.F.F<<' '<<i.F.S<<' '<<i.S<<endl;
	}
	return 0;
}