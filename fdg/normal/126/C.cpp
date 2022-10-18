#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>

#define ll long long

using namespace std;

int D[2002][2002];
int row1[2002],col1[2002];
int row2[2002],col2[2002];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,ans=0;
    scanf("%d\n",&n);
    char c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%c",&c);
            D[i][j]=c-'0';
        }
        scanf("\n");
    }
    for(int t=n-1;t>=0;t--)
    {
        for(int j=0;j<t;j++)
            if ((row1[t]+col1[j]+D[t][j])&1)
            {
                ans++,col1[j]++,row1[t]++;
//              cout << t << "  " << j << endl;
            }
        for(int i=0;i<t;i++)
            if ((row2[i]+col2[t]+D[i][t])&1)
            {
                ans++,col2[t]++,row2[i]++;
//              cout << i << "  " << t << endl;
            }
        if ((D[t][t]+row1[t]+col1[t]+row2[t]+col2[t])&1)
        {
            ans++;
//          cout << t << "  " << t << endl;
        }
    }
    cout << ans << endl;
    return 0;
}