#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,v;
    double a[200]={0},b[200]={0};
    cin >> n >> v;
    double sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    double x=1.0*v/sum;
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        if (b[i]/a[i]<x) x=b[i]/a[i];
    }
    printf("%.4lf\n",x*sum);
    return 0;
}