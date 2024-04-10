#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;

char s[100111];
int n;
int F[100111][2];
int sz[2]={2,3};

int Can(int k,int tp)
{
    if (F[k][tp]!=-1)
    return F[k][tp];

    if (k+sz[tp]-1==n)
    return 1;
    if (k+sz[tp]-1>n)
    return 0;

    ///Try 0

    F[k][tp]=0;
    if (tp==0)
    {
        if (s[k]==s[k+2] && s[k+1]==s[k+3])
        {
            if (Can(k+2,1))
            F[k][tp]=1;
        }
        else
        {
            if (Can(k+2,0))
            F[k][tp]=1;
            else if (Can(k+2,1))
            F[k][tp]=1;
        }
    }
    else
    {
        if (s[k]==s[k+3] && s[k+1]==s[k+4] && s[k+2]==s[k+5])
        {
            if (Can(k+3,0))
            F[k][tp]=1;
        }
        else
        {
            if (Can(k+3,0))
            F[k][tp]=1;
            else if (Can(k+3,1))
            F[k][tp]=1;
        }
    }

    return F[k][tp];
}

set<string> myset;
set<string>::iterator myit;

string str;

int main()
{
    int i,j;

    memset(F,-1,sizeof(F));

    scanf("%s",s+1);
    n=strlen(s+1);

    s[n+1]='z'+1;
    s[n+2]='z'+1;
    s[n+3]='z'+1;

    for (i=6;i<=n;i++)
    {
        str.clear();

        if (i+1<=n)
        {
            if (Can(i,0))
            {
                str.push_back(s[i]);
                str.push_back(s[i+1]);

                myset.insert(str);
            }
        }

        str.clear();

        if (i+2<=n)
        {
            if (Can(i,1))
            {
                str.push_back(s[i]);
                str.push_back(s[i+1]);
                str.push_back(s[i+2]);

                myset.insert(str);
            }
        }
    }

    printf("%d\n",(int)myset.size());

    for (myit=myset.begin();myit!=myset.end();myit++)
    {
        str=(*myit);

        for (j=0;j<str.length();j++)
        {
            printf("%c",str[j]);
        }
        printf("\n");
    }

    return 0;
}