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
int i,n,a[10];
long long sol;
char sir[100009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&a[1]);
scanf("%d",&a[2]);
scanf("%d",&a[3]);
scanf("%d\n",&a[4]);
gets(sir+1);
n=strlen(sir+1);
for(i=1;i<=n;i++)
    sol+=a[sir[i]-'0'];
printf("%I64d\n",sol);
return 0;
}