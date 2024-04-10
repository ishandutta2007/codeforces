#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

///B-G-R

bool HasB=false,HasG=false,HasR=false;
bool F[311][311][311];
int n;
char ch[1011];
int R=0,G=0,B=0;

void Solve(int b,int g,int r)
{
    if (b<0 || g<0 || r<0)
    return;
    if (F[b][g][r])
    return;
    if (b+g+r==1)
    {
        if (b==1)
        HasB=true;
        if (g==1)
        HasG=true;
        if (r==1)
        HasR=true;

        return;
    }

    F[b][g][r]=true;

    Solve(b-1,g-1,r+1);
    Solve(b-1,g+1,r-1);
    Solve(b+1,g-1,r-1);

    if (b>1)
    Solve(b-1,g,r);
    if (g>1)
    Solve(b,g-1,r);
    if (r>1)
    Solve(b,g,r-1);

    return;
}

int main()
{
    int i,j,in;

    memset(F,false,sizeof(F));

    scanf("%d",&n);

    scanf("%s",ch+1);

    for (i=1;i<=n;i++)
    {
        if (ch[i]=='R')
        R++;
        if (ch[i]=='G')
        G++;
        if (ch[i]=='B')
        B++;
    }

    Solve(B,G,R);

    if (HasB)
    printf("B");
    if (HasG)
    printf("G");
    if (HasR)
    printf("R");

    printf("\n");

    return 0;
}