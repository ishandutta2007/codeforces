#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

int gcd(int a,int b) {return (b==0) ? a : gcd(b,a%b);}
int lcm(int a,int b) {return a/gcd(a,b)*b;}


int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d",&n);
    vector <int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }
    int mn=labs(v[0]-v[n-1]),ind=n-1;
    for(int i=0;i<n-1;i++)
    {
        if (labs(v[i]-v[i+1])<mn)
        {
            mn=labs(v[i]-v[i+1]);
            ind=i;
        }
    }
    if (ind==n-1) printf("1 %d\n",ind+1);
    else printf("%d %d\n",ind+1,ind+2);
    return 0;
}