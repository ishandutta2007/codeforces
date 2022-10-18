#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <memory.h>
//#pragma comment(linker, "/STACK:60777216")

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,x;
    cin >> n >> m >> x;
    x--;
    int ans=0;
    n-=2*x; m-=2*x; 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if ((i==1||i==n||j==1||j==m)&&(i+j)%2==0) ans++;
    cout << ans << endl;
    return 0;
}