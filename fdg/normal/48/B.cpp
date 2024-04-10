#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b,D[101][101]={0};
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> D[i][j];
    cin >> a >> b;
    int ans=a*b;
    for(int i=1;i<=n-a+1;i++)
        for(int j=1;j<=m-b+1;j++)
        {
            int kol=0;
            for(int q=0;q<a;q++)
                for(int w=0;w<b;w++)
                    kol+=D[i+q][j+w];
            if (kol<ans) ans=kol;
        }
    for(int i=1;i<=n-b+1;i++)
        for(int j=1;j<=m-a+1;j++)
        {
            int kol=0;
            for(int q=0;q<b;q++)
                for(int w=0;w<a;w++)
                    kol+=D[i+q][j+w];
            if (kol<ans) ans=kol;
        }
    cout << ans << endl;
    return 0;
}