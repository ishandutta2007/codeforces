#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
int i,j,n;
char sir[10009];
string s[10];
void prec()
{
    s[1]="vaporeon";
    s[2]="jolteon";
    s[3]="flareon";
    s[4]="espeon";
    s[5]="umbreon";
    s[6]="leafeon";
    s[7]="glaceon";
    s[8]="sylveon";
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d\n",&n);
gets(sir);
prec();
for(i=1;i<=8;i++)
if(n==s[i].length())
{
    for(j=0;j<n;j++)
        if(s[i][j]!=sir[j]&&sir[j]!='.') break;
    if(j==n) break;
}
for(j=0;j<n;j++)
    printf("%c",s[i][j]);
printf("\n");
return 0;
}