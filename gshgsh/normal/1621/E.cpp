#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define eps 1e-9
#define MAXN 100001
int T,N,M,a[MAXN],s0[MAXN],s1[MAXN],s2[MAXN];ll sum[MAXN];double val[MAXN];vector<int>v[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)a[i]=get();For(i,1,M){int k=get();sum[i]=0;v[i].clear();while(k--)v[i].push_back(get()),sum[i]+=v[i].back();}
		sort(a+1,a+N+1,greater<int>());For(i,1,M)val[i]=1.0*sum[i]/v[i].size();sort(val+1,val+M+1,greater<double>());
		For(i,1,M)s0[i]=s0[i-1]+(a[i]<val[i]-eps);//
		For(i,1,M-1)s1[i]=s1[i-1]+(a[i+1]<val[i]-eps);//a
		For(i,1,M-1)s2[i]=s2[i-1]+(a[i]<val[i+1]-eps);//b
		For(i,1,M)for(auto j:v[i])
		{
			double os=1.0*sum[i]/v[i].size(),ns=1.0*(sum[i]-j)/(v[i].size()-1);
			if(abs(os-ns)<=eps){cout<<!s0[M];continue;}
			if(os>ns)
			{
				int x=lower_bound(val+1,val+M+1,os+eps,greater<double>())-val;
				int y=lower_bound(val+1,val+M+1,ns+eps,greater<double>())-val;
				if(x==y){cout<<!s0[i];continue;}
				bool ans=!s0[x-1]&&(!(s2[y-2]-s2[x-1]))&&(a[y-1]>=ns-eps)&&(!(s0[M]-s0[y-1]));cout<<ans;
			}
			else
			{
				int x=lower_bound(val+1,val+M+1,os+eps,greater<double>())-val;
				int y=lower_bound(val+1,val+M+1,ns+eps,greater<double>())-val;
				if(x==y){cout<<(!s0[M]&&a[x]>=ns-eps);continue;}
				bool ans=!s0[y-1]&&(!(s1[x-1]-s1[y-1]))&&(a[y]>=ns-eps)&&(!(s0[M]-s0[x]));cout<<ans;
			}
		}
		cout<<'\n';
	}
	return 0;
}