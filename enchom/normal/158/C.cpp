#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

char directories[20001][201];
Int directL[20001];
Int dir;

int main()
{
    Int n;
    string a,b;
    Int i,j,in;
    char cd[201];
    Int cdL=0;
    char d[201];
    Int dL=0;
    
    dir=1;
    directL[1]=0;
    
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        cin>>a;
        cdL=0;
        dL=0;
        if (a[0]=='c')
        {
            cin>>b;
            if (b[0]=='/')
            {
                dir=1;
                directL[1]=0;
                for (j=1;j<b.length();j++)
                {
                    cdL++;
                    cd[cdL]=b[j];
                }
            }
            else
            {
                for (j=0;j<b.length();j++)
                {
                    cdL++;
                    cd[cdL]=b[j];
                }
            }
            for (j=1;j<=cdL;j++)
            {
                if (cd[j]!='/')
                {
                    dL++;
                    d[dL]=cd[j];
                }
                else
                {
                    if (dL==2 && d[1]=='.' && d[2]=='.')
                    {
                        dir--;
                        dL=0;
                    }
                    else
                    {
                        dir++;
                        directL[dir]=dL;
                        for (in=1;in<=dL;in++)
                        {
                            directories[dir][in]=d[in];
                        }
                        dL=0;
                    }
                }
            }
            if (dL==2 && d[1]=='.' && d[2]=='.')
            {
                dir--;
                dL=0;
            }
            else
            {
                dir++;
                directL[dir]=dL;
                for (in=1;in<=dL;in++)
                {
                    directories[dir][in]=d[in];
                }
                dL=0;
            }
        }
        else
        {
            for (j=1;j<=dir;j++)
            {
                for (in=1;in<=directL[j];in++)
                {
                    printf("%c",directories[j][in]);
                }
                printf("/");
            }
            printf("\n");
        }
    }
}