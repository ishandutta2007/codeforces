#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int i,n,m;
char sir[1000009];
vector < int > v;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(sir+1);
m=strlen(sir+1);
n=m/2+1;
for(i=1;i<=n;i++)
    v.push_back(sir[2*i-1]-48);
sort(v.begin(),v.end());
for(i=0;i<n-1;i++)
    printf("%d+",v[i]);
printf("%d\n",v[n-1]);
return 0;
}