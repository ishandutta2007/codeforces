#include<bits/stdc++.h>

using namespace std;

int N, M;
char a[100009], b[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
gets(a+1), gets(b+1), N=strlen(a+1), M=strlen(b+1);
if(N==M)
{
    bool ok=0;
for (int i=1;i<=N;i++)
    if(a[i] != b[i]) ok=1;
    if(ok==0){printf("-1\n"); return 0;}
}
printf ("%d\n", max(N, M));
return 0;
}