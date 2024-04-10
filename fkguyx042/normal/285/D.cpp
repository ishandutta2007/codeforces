#include<cstdio>
using namespace std;
int n;
const int ans[17]={0,1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,695720788,0,150347555,0};
int main()
{ scanf("%d",&n);
  printf("%d\n",ans[n]);
}