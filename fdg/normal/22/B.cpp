#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");
    int n,m;
    cin >> n >> m;
    char D[27][27]={0};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> D[i][j];
    int maxp=0;
    int Sum[27][27]={0};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            Sum[i][j]=D[i][j]-'0'+Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1];
    for(int x1=1;x1<=n;x1++)
        for(int y1=1;y1<=m;y1++)
            for(int x2=x1;x2<=n;x2++)
                for(int y2=y1;y2<=m;y2++)
                    if (Sum[x2][y2]-Sum[x2][y1-1]-Sum[x1-1][y2]+Sum[x1-1][y1-1]==0)
                        if (maxp<2*(x2-x1+1+y2-y1+1)) maxp=2*(x2-x1+1+y2-y1+1);
    cout << maxp << endl;
    return 0;
}