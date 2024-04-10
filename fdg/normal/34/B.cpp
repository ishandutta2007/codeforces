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
    scanf("%d%d",&n,&m);
    vector <int> v(n,0);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        v.push_back(-a);
    }
    sort(v.rbegin(),v.rend());
    int ans=0;
    for(int i=0;i<m;i++)
    {
        if (v[i]<=0) break;
        ans+=v[i];
    }
    printf("%d\n",ans);
    return 0;
}