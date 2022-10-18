#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int dx[]={-1,0,1,0},
    dy[]={0,1,0,-1};

char F[52][52];
int n,m;

inline bool in(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m;
}

struct state{
    state(int _x = 0,int _y = 0,int _dp = 1, int _cp = -1) : x(_x), y(_y), dp(_dp), cp(_cp) {};
    int x,y,dp,cp;
};

state next(state & cur)
{
    int cx=cur.x,cy=cur.y;
    while(in(cx+dx[cur.dp],cy+dy[cur.dp])&&F[cx+dx[cur.dp]][cy+dy[cur.dp]]==F[cur.x][cur.y])
        cx+=dx[cur.dp],cy+=dy[cur.dp];
    int nd=(cur.dp+4+cur.cp)%4;
    while(in(cx+dx[nd],cy+dy[nd])&&F[cx+dx[nd]][cy+dy[nd]]==F[cur.x][cur.y])
        cx+=dx[nd],cy+=dy[nd];
    if (in(cx+dx[cur.dp],cy+dy[cur.dp])&&F[cx+dx[cur.dp]][cy+dy[cur.dp]]!='0')
    {
        state ns(cx+dx[cur.dp],cy+dy[cur.dp],cur.dp,cur.cp);
        return ns;
    }
    if (cur.cp==-1)
    {
        state ns(cur.x,cur.y,cur.dp,1);
        return ns;
    }
    state ns(cur.x,cur.y,(cur.dp+1)%4,cur.cp*-1);
    return ns;
}

state nx[51][51][4][2];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> F[i];
    m=strlen(F[0]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int d=0;d<4;d++)
                for(int sgn=0;sgn<=1;sgn++)
                {
                    state st(i,j,d,sgn==0 ? -1 : sgn);
                    nx[i][j][d][sgn]=next(st);
                }
    state cur;
    for(int i=0;i<k;i++)
//  {
        cur=nx[cur.x][cur.y][cur.dp][cur.cp==-1 ? 0 : cur.cp];
        cout << F[cur.x][cur.y] << endl;
//  }
    return 0;
}