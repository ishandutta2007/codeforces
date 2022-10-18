#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:1760777216")

#define ll long long

using namespace std;

char str[100002],res[1000002];
int l;

bool gen(int i,int n4,int n7,bool large)
{
    if (i==l)
    {
        res[i]='\0';
        puts(res);
        return true;
    }
    if (large)
    {
        if (n4)
        {
            res[i]='4';
            return gen(i+1,n4-1,n7,large);
        }
        else
        {
            res[i]='7';
            return gen(i+1,n4,n7-1,large);
        }
    }
    else
    {
        res[i]='4';
        if (n4&&str[i]<='4'&&gen(i+1,n4-1,n7,str[i]<'4')) return true;
        res[i]='7';
        if (n7&&str[i]<='7'&&gen(i+1,n4,n7-1,str[i]<'7')) return true;
    }
    return false;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str); l=strlen(str);
    if (l%2==1||!gen(0,l/2,l/2,false))
    {
        l=l/2+1;
        for(int i=0;i<l;i++)
            printf("4");
        for(int i=0;i<l;i++)
            printf("7");
        printf("\n");
    }
    return 0;
}