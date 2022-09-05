#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int n,m;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d%d",&n,&m);
if(min(n,m)&1) printf("Akshat\n");
else printf("Malvika\n");
return 0;
}