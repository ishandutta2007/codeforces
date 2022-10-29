#include<cstdio>
#include<algorithm>
using namespace std;
int A[1005],n;
char c[1000005];
int main()
{
	  int sum=0;
	  scanf("%d",&n);
	  scanf("%s",c);
	  for (int i=0;i<n-1;++i)
	  {
	  	 A[c[2*i]-'a']++;
	  	 if (!A[c[2*i+1]-'A']) ++sum;
	  	 else A[c[2*i+1]-'A']--;
	  }
	  printf("%d\n",sum);
}