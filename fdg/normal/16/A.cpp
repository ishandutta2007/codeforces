#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,ok=1;
    char D[101][101]={0};
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> D[i];
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
            if (D[i][j]!=D[i][j-1]) ok=0;
    for(int i=1;i<n;i++)
        if (D[i][0]==D[i-1][0]) ok=0;
    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}