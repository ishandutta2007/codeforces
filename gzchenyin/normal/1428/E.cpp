#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
priority_queue<pair<long long,int> > Q;
int n,k;
long long a[100005],ansx[100005],ans;
long long f(long long n,int k)
{
	if(k==0) return 1e17;
	long long ave=n/k;
	long long x2=n-ave*k;
	long long x1=k-x2;
//	printf("f(%lld,%d)=%lld\n",n,k,x1*ave*ave+x2*(ave+1)*(ave+1));
	return x1*ave*ave+x2*(ave+1)*(ave+1);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
        Q.push(make_pair(f(a[i],0)-f(a[i],1),i));
	}
	for(int i=1;i<=k;i++)
    {
        int tmp=Q.top().second;
        Q.pop();
        ansx[tmp]++;
        Q.push(make_pair(f(a[tmp],ansx[tmp])-f(a[tmp],ansx[tmp]+1),tmp));
    }
    for(int i=1;i<=n;i++)
    {
        ans+=f(a[i],ansx[i]);
    }
    printf("%lld\n",ans);
}