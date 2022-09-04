#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
main()
{
    int n,p[100001],first=1,second=1;
    string people[100001][2],t="";
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>people[i][0]>>people[i][1];
        if(people[i][0]>people[i][1])
        swap(people[i][0],people[i][1]);
    }
    for(int i=0;i<n;i++)
    {
    scanf("%d",&p[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(t<people[p[i]][0])
        {
            t=people[p[i]][0];
        }
        else if(t<people[p[i]][1])
        {
            t=people[p[i]][1];
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}