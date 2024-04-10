#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,x,a[MAXN],b[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(){For(i,1,N)if(a[i]!=b[i])return 0;return 1;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),x=get();For(i,1,N)b[i]=a[i]=get();if(N>=x*2+1){cout<<"YES\n";continue;}sort(b+1,b+N+1);
		vector<int>tmp;For(i,1,N-x)tmp.push_back(a[i]);For(i,1+x,N)tmp.push_back(a[i]);sort(tmp.begin(),tmp.end());
		int now=0;For(i,1,N-x)a[i]=tmp[now++];For(i,1+x,N)a[i]=tmp[now++];cout<<(check()?"YES\n":"NO\n");
	}
	return 0;
}