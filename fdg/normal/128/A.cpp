#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>
#include <map>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    char D[9][9]={0};
    for(int i=0;i<8;i++)
        cin >> D[i];
    bool can[9][9]={0};
    can[7][0]=1;
    int dx[]={-1,-1,-1,0,0,1,1,1},
        dy[]={-1,0,1,-1,1,-1,0,1};
    for(;;)
    {
        if (can[0][7]) break;
        bool finded=false;
        bool c1[9][9]={0};
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if (can[i][j])
                {
                    finded=true;
                    c1[i][j]=true;
                    for(int t=0;t<8;t++)
                        if (i+dx[t]>=0&&i+dx[t]<8&&j+dy[t]>=0&&j+dy[t]<8&&D[i+dx[t]][j+dy[t]]!='S')
                        {
                            c1[i+dx[t]][j+dy[t]]=true;
                        }
                }
        for(int i=7;i>=0;i--)
            for(int j=0;j<8;j++)
                D[i+1][j]=D[i][j];
        for(int i=0;i<8;i++) D[0][i]='.';
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                can[i][j]=c1[i][j]&&(D[i][j]!='S');
        if (!finded) break;
    }
    cout << (can[0][7] ? "WIN" : "LOSE") << endl;
    return 0;
}