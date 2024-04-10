#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>

#define ll long long

using namespace std;

int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k,mindist=200000,x,y;
    cin >> n >> m >> k;
    for(int i=0;i<k;i++)
    {
        cin >> x >> y;
        int cur=min(min(x-1,n-x),min(y-1,m-y));
        if (cur<mindist) mindist=cur;
    }
    if (mindist<5) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}