#include <bits/stdc++.h>

using namespace std;

int N, L, V1, V2, K;

bool solve(double t)
{
    double walk=(double)L/V1;
    if(walk<=t)
        return true;
    double bus=(double)L/V2;
    if(t<bus)
        return false;
    double lo=0.0, mid, hi=t;
    for(int i=0; i<60; i++)
    {
        mid=(lo+hi)/2;
        if(max(0.0, (L-mid*V2))/V1+mid<=t)
            hi=mid;
        else
            lo=mid;
    }
    int trips=(N+K-1)/K;
    double tot=(lo+(lo*(V2-V1))/(V1+V2))*(trips-1)+lo;
    if(tot<=t)
        return true;
    return false;
}

int main()
{
    cin>>N>>L>>V1>>V2>>K;
    double lo=0.0, mid, hi=L;
    for(int i=0; i<60; i++)
    {
        mid=(lo+hi)/2;
        if(solve(mid))
            hi=mid;
        else
            lo=mid;
    }
    printf("%.9f\n", lo);
    return 0;
}