#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

char D[5001][5001]={0};
bool used[5001][5001]={0};

int dx[]={-1,0,1,0},
    dy[]={0,1,0,-1};

int move(int x,int y)
{
    if (D[x][y]=='U') return 0;
    if (D[x][y]=='R') return 1;
    if (D[x][y]=='D') return 2;
    if (D[x][y]=='L') return 3;
        return -1;
}

int n,m;

int calc(int x,int y)
{
    used[x][y]=true;
    int t=move(x,y);
    while(x+dx[t]>=0&&x+dx[t]<n&&y+dy[t]>=0&&y+dy[t]<m)
    {
        if (D[x+dx[t]][y+dy[t]]!='.'&&!used[x+dx[t]][y+dy[t]])
        {
            return 1+calc(x+dx[t],y+dy[t]);
        }
        x+=dx[t]; y+=dy[t];
    }
    return 1;
}

bool op(char a,char b)
{
    if (a=='L'&&b=='R') return true;
    if (a=='R'&&b=='L') return true;
    if (a=='U'&&b=='D') return true;
    if (a=='D'&&b=='U') return true;
    return false;
}

int calc1(int x,int y)
{
    int ret=1;
    int lx=x,ly=y; bool need=false;
    while(true)
    {
        used[x][y]=true;
        int t=move(x,y);
        bool finded=false;
//      lx+=dx[t]; ly+=dy[t];
        int px=x,py=y;
        if (need) x=lx,y=ly;
        lx=px; ly=py;
        need=false;
        while(x+dx[t]>=0&&x+dx[t]<n&&y+dy[t]>=0&&y+dy[t]<m)
        {
            if (D[x+dx[t]][y+dy[t]]!='.'&&!used[x+dx[t]][y+dy[t]])
            {
                ret++;
                finded=true;
                if (op(D[lx][ly],D[x+dx[t]][y+dy[t]])) need=true;
                x+=dx[t]; y+=dy[t];
                break;
            }
            x+=dx[t]; y+=dy[t];
        }
        if (!finded) break;
    }
    return ret;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;i++)
        gets(D[i]);
    int mx=0,cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            for(int ii=0;ii<n;ii++)
                for(int jj=0;jj<m;jj++)
                    used[ii][jj]=0;
            if (D[i][j]!='.')
            {
                int val=calc1(i,j);
                if (val==mx) cnt++;
                if (val > mx) mx=val,cnt=1;
            }
        }
    cout << mx << " " << cnt << endl;
/*  int n=70,m=70;
    cout << n << "  " << m << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int t=rand()%5;
            if (t==0) cout << ".";
            if (t==1) cout << "U";
            if (t==2) cout << "R";
            if (t==3) cout << "D";
            if (t==4) cout << "L";
        }
        cout << endl;
    }*/
/*  cout << "1 1000" << endl;
    for(int i=0;i<500;i++)
        cout << "R";
    for(int i=0;i<500;i++)
        cout << "L";
    cout << endl;*/
    return 0;
}