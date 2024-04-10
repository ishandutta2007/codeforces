#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int B1=97LL;
Int B2=103LL;
Int MOD1=1000000007LL;
Int MOD2=1000000021LL;

Int Pows1[1000111];
Int Pows2[1000111];

int n;
char p1[1000111];
char p2[1000111];

int ToInt(char ch)
{
    if (ch=='N')
    return 0;
    else if (ch=='W')
    return 1;
    else if (ch=='S')
    return 2;
    else
    return 3;
}

int main()
{
    int i;
    Int v;
    pair<Int,Int> H1,H2;
    int cp;

    Pows1[0]=1;
    Pows2[0]=1;

    for (i=1;i<=1000000;i++)
    {
        Pows1[i]=(Pows1[i-1]*B1)%MOD1;
        Pows2[i]=(Pows2[i-1]*B2)%MOD2;
    }

    scanf("%d",&n);

    scanf("%s",p1+1);
    scanf("%s",p2+1);

    H1=make_pair(0,0);
    H2=make_pair(0,0);

    cp=0;
    for (i=n-1;i>=1;i--)
    {
        v=(Int)ToInt(p1[i]);

        H1.first=(H1.first+Pows1[cp]*v)%MOD1;
        H1.second=(H1.second+Pows2[cp]*v)%MOD2;

        v=(Int)(ToInt(p2[i])+2)%4;

        H2.first*=B1;

        H2.first+=v;
        H2.first%=MOD1;

        H2.second*=B2;
        H2.second+=v;
        H2.second%=MOD2;

        if (H1.first==H2.first && H1.second==H2.second)
        {
            printf("NO\n");
            return 0;
        }

        cp++;
    }

    printf("YES\n");

    return 0;
}