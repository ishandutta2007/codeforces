#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int i, n, v[20], loc[20];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
scanf ("%d", &n);
printf ("+------------------------+\n");
for (int i=1; i<=11; i++)
    loc[i] = 3;
loc[1] ++;
for (int i=1; i<=11; i++)
{
    if (n<=loc[i])
    {
        v[i] = n;
        break;
    }
    else
    {
        v[i] = loc[i];
        n-=v[i];
    }
}
for (int i=1; i<=4; i++)
{
    printf ("|");
    char car = '#';
    if (v[1] >= i) car = 'O';
    printf ("%c.", car);
    for (int j=2; j<=11; j++)
    {
        char car = '#';
        if (i==4 && v[j] == 3) car = 'O';
        else
        if (i==4) ;
        else
        if (i==3) car = '.';
        else
        if (i <= v[j]) car = 'O';
        printf ("%c.", car);
    }
    car = '.';
    if (i==1) car = 'D';
    if (i!=3) printf ("|%c|", car);
    else printf (".%c|", car);
    if (i == 1 || i==4) printf (")");
    printf ("\n");
}
printf ("+------------------------+");
return 0;
}