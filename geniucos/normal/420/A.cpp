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
int i,n;
char sir[100009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(sir+1);
n=strlen(sir+1);
for(i=1;i<=n;i++)
    if(sir[i]!=sir[n+1-i])
    {
        printf("NO\n");
        return 0;
    }
for(i=1;i<=n;i++)
    if(sir[i]!='A'&&sir[i]!='W'&&sir[i]!='H'&&sir[i]!='M'&&sir[i]!='O'&&sir[i]!='T'&&sir[i]!='U'&&sir[i]!='I'&&sir[i]!='X'&&sir[i]!='V'&&sir[i]!='Y')
    {
        printf("NO\n");
        return 0;
    }
printf("YES\n");
return 0;
}