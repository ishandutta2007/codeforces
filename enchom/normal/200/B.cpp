#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    double n,percents,answer;
    double sumpercents=0,i;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>percents;
        sumpercents=sumpercents+percents;
    }
    answer=sumpercents/n;
    printf("%4.12f",answer);
    return 0;
}