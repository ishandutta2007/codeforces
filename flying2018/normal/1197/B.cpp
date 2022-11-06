#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
int a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int i=1;
    for(i=1;i<n;i++)
    if(a[i+1]<a[i]) break;
    for(;i<n;i++)
    if(a[i+1]>a[i]) break;
    puts(i==n?"YES":"NO");
    return 0;
}