#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE],B[SIZE];
P memo[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++) memo[i]=P(-1,-1);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&B[i]);
		memo[A[i]]=max(memo[A[i]],P(B[i],i));
	}
	vector <int> vec;
	for(int i=0;i<n;i++)
	{
		if(memo[A[i]].second!=i) vec.push_back(B[i]);
	}
	sort(vec.begin(),vec.end());
	int cnt=0;
	for(int i=0;i<k;i++) if(memo[i].first==-1) cnt++;
	ll ret=0;
	for(int i=0;i<cnt;i++) ret+=vec[i];
	printf("%lld\n",ret);
	return 0;
}