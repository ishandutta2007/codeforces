#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
int dp[5005];
int main()
{
  int n,m,maxi=0;
  scanf("%d %d",&n,&m);
  vector<int>vec;
  for(int i=0;i<n;i++)
    {
      int g;
      double dr;
      scanf("%d %lf",&g,&dr);
      vec.push_back(g);
    }
  for(int i=0;i<n;i++)
    {
      dp[i]=1;
      for(int j=0;j<i;j++)
	{
	  if(vec[i]>=vec[j])
	    {
	      dp[i]=max(dp[i],dp[j]+1);
	    }
	}
    }
  for(int i=0;i<n;i++)
    {
      maxi=max(maxi,dp[i]);
    }
  printf("%d",n-maxi);
}