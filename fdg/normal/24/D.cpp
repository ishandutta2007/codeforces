#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
/*
#ifndef ONLINE_JUDGE
int AA=(int)freopen("input.txt","r",stdin);
int BB=(int)freopen("output.txt","w",stdout);
#endif
*/
#define ll long long

using namespace std;

double a[1001]={0},b[1001]={0},c[1001]={0},l[1001]={0},p[1001]={0};

void TridiagonalSolve(double * a,double * b,double * c,double * l,double * p,int n)
{
    for(int i=0;i<n-1;i++)
    {
        double koef=-a[i]/b[i];
        a[i]=0; b[i+1]+=c[i]*koef;
        l[i+1]+=l[i]*koef;
    }
    p[n-1]=l[n-1]/b[n-1];
    for(int i=n-2;i>=0;i--)
    {
        p[i]=(l[i]-c[i]*p[i+1])/b[i];
    }
}

int main()
{
    int N,M,n,m;
    cin >> N >> M >> n >> m;
    for(int i=0;i<N-n;i++)
    {
        for(int t=0;t<M;t++)
        {
            double cur=2;
            if (t>0) cur++;
            if (t<M-1) cur++;
            b[t]=1.0-1.0/cur;
            a[t-1]=c[t]=-1.0/cur;
            l[t]=p[t]/cur+1.0,p[t]=0;
        }
        TridiagonalSolve(a,b,c,l,p,M);
    }
    cout.precision(20);
    cout << p[m-1] << endl;
    return 0;
}