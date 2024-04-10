#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long t,top=1,x,ans=1;
bool notp[1005];
long long f[20]={0,1},g[20];
vector<long long> vec;
int main()
{
	for(int i=2;i<=660;i++)
	{
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0) notp[i]=true;
		}
		if(!notp[i])
		{
			if(f[top]<=1e18/i) f[top]=f[top]*i;
			else f[++top]=i;
		}
	}
//	for(int i=1;i<=top;i++)
//	{
//		printf("%lld\n",f[i]);
//	}
	scanf("%d",&t);
	while(t--)
	{
		ans=1;
		vec.clear();
		for(int i=1;i<=17;i++)
		{
			printf("? %lld\n",f[i]);
			fflush(stdout);
			scanf("%lld",&x);
			for(int j=2;j<=660;j++)
			{
				if(!notp[j] && (x%j==0)) vec.push_back(j);
			} 
		}
		for(int i=0;i<vec.size();i++)
		{
			long long tmp=1ll;
			while(tmp*vec[i]<=1e9) tmp*=vec[i];
			g[i]=tmp;
		}
		for(int i=0;i<vec.size();i+=2)
		{
			long long t;
			if(i==vec.size()-1) t=g[i];
			else t=g[i]*g[i+1];
			printf("? %lld\n",t);
			fflush(stdout);
			scanf("%lld",&x);
			long long tmp=1;
			while(x%vec[i]==0)
			{
				x/=vec[i];
				tmp++;
			}
			ans*=tmp;
			if(i==vec.size()-1) continue;
			tmp=1;
			while(x%vec[i+1]==0)
			{
				x/=vec[i+1];
				tmp++;
			}
			ans*=tmp;
		}
		if(!vec.size() || ans==2) printf("! 8\n");
		else printf("! %lld\n",ans*2);
	}
}