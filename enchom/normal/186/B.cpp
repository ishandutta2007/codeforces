#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct participantt
{
    int number;
    double growth;
};

bool SortEm(participantt a,participantt b)
{
    if (a.growth>b.growth)
    return true;
    else if (a.growth<b.growth)
    return false;
    else
    {
        return (a.number<b.number);
    }
}

double MAX(double a,double b)
{
    if (a>b)
    return a;
    else
    return b;
}

participantt dwarvess[1001];

int main()
{
    double t1,t2,k;
    double a,b;
    int i,n;
    
    cin>>n>>t1>>t2>>k;
    
    for (i=1;i<=n;i++)
    {
        cin>>a>>b;
        dwarvess[i].number=i;
        dwarvess[i].growth=MAX( ( a*t1*(100-k) )/100+b*t2 , ( b*t1*(100-k) )/100+a*t2 );
    }
    sort(dwarvess+1,dwarvess+1+n,SortEm);
    for (i=1;i<=n;i++)
    {
        printf("%d %4.2f\n",dwarvess[i].number,dwarvess[i].growth);
    }
    return 0;
}