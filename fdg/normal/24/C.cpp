#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
/*
#ifndef ONLINE_JUDGE
int AA=(int)freopen("input.txt","r",stdin);
int BB=(int)freopen("output.txt","w",stdout);
#endif
*/
#define ll long long

using namespace std;

ll sum1[100005]={0},sum2[100005]={0};
ll x[200006]={0},y[200006]={0};
int main()
{
    int n,Mx,My,sgn=1; ll j;
    cin >> n >> j >> Mx >> My;
    sum1[0]=sum2[0]=0;
    for(int i=0;i<n;i++)
    {
        int Ax,Ay;
        cin >> sum1[i] >> sum2[i];
//      cout << sum1[i] << "    " << sum2[i] << endl;
    }
    x[0]=Mx; y[0]=My;
    for(int i=1;i<=2*n;i++)
    {
        x[i]=2*sum1[(i-1)%n]-x[i-1];
        y[i]=2*sum2[(i-1)%n]-y[i-1];
    }
    cout << x[j%(2*n)] << " " << y[j%(2*n)] << endl;
    return 0;
}