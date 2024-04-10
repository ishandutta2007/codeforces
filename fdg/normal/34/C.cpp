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
    bool used[1003]={0};
    int a;
    while(scanf("%d,",&a)==1)
    {
        used[a]=true;
    }
    bool first=true;
    int f=-1;
    for(int i=1;i<=1001;i++)
    {
        if (used[i]&&used[i-1]==false) f=i;
        if (used[i-1]&&used[i]==false)
        {
            if (!first) printf(",");
            if (i-1==f) printf("%d",f);
            else printf("%d-%d",f,i-1);
            first=false;
        }
    }
    printf("\n");
    return 0;
}