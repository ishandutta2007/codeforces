#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stack>
#include <fstream>

#define ll long long

using namespace std;

char D[1001][1001]={0};
char I[1001][1001]={0};
int S[1001][1001]={0};
int F[1001][1001]={0};
int n,m,cur=1;
int dx[]={0,0,1,-1},
    dy[]={-1,1,0,0};
char ans[1001][1001]={0};

int step(int x,int y)
{
    if (D[x][y]!='.') return -1;
    int cnt=0;
    for(int t=0;t<4;t++)
    {
        if (x+dx[t]>=0&&x+dx[t]<n&&y+dy[t]>=0&&y+dy[t]<m)
            if (D[x+dx[t]][y+dy[t]]=='.') cnt++;
    }
    return cnt;
}

vector <int> x,y;
bool was[10]={0};
vector <int> cx,cy;

void dfs(int x,int y)
{
    cx.push_back(x);
    cy.push_back(y);
    for(int t=0;t<4;t++)
    {
        if (x+dx[t]>=0&&x+dx[t]<n&&y+dy[t]>=0&&y+dy[t]<m)
        {
            if (ans[x+dx[t]][y+dy[t]]!='#'&&ans[x+dx[t]][y+dy[t]]!='\0') was[ans[x+dx[t]][y+dy[t]]-'0']=true;
            else
            {
                bool ok=true;
                for(int i=0;i<cx.size();i++)
                    if (cx[i]==x+dx[t]&&cy[i]==y+dy[t])
                    {
                        ok=false;
                        break;
                    }
                if (ok&&F[x+dx[t]][y+dy[t]]==F[x][y])
                {
                    dfs(x+dx[t],y+dy[t]);
                }
            }
        }
    }
}

int total=0;

void fill()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (F[i][j]>0&&ans[i][j]=='\0')
            {
                for(int t=0;t<10;t++) was[t]=false;
                cx.clear(); cy.clear();
                dfs(i,j);
                char c='q';
                for(int t=0;t<10;t++)
                    if (!was[t])
                    {
                        c='0'+t;
                        break;
                    }
                if (cx.size()>1)
                    for(int t=0;t<cx.size();t++)
                        ans[cx[t]][cy[t]]=c;
            }
            if (F[i][j]==-1) ans[i][j]='#';
        }
    }
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> D[i];
        memcpy(I[i],D[i],sizeof(D[i]));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            S[i][j]=step(i,j);
    }
    x.clear();
    y.clear();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (D[i][j]!='.') continue;
            int cnt=0;
            for(int t=0;t<4;t++)
                if (i+dx[t]>=0&&i+dx[t]<n&&j+dy[t]>=0&&j+dy[t]<m)
                    if (step(i+dx[t],j+dy[t])==1) cnt++;
            if (cnt>0)
            {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    int dx1[]={-3,-2,-2,-1,-1,0,0,1,1,2,2,3,-2,-1,1,2,-1,0,1,-1,0,1,0,0},
        dy1[]={0,-1,1,-2,2,-3,3,-2,2,-1,1,0,0,0,0,0,1,1,1,-1,-1,-1,2,-2};
    while(true)
    {
        for(int r=0;r<x.size();r++)
        {
            if (D[x[r]][y[r]]!='.') continue;
            int cnt=0;
            for(int t=0;t<4;t++)
                if (x[r]+dx[t]>=0&&x[r]+dx[t]<n&&y[r]+dy[t]>=0&&y[r]+dy[t]<m)
                    if (step(x[r]+dx[t],y[r]+dy[t])==1) cnt++;
            if (cnt>0)
            {
                F[x[r]][y[r]]=cur;
                vector <int> tmpx(1,x[r]),tmpy(1,y[r]);
                for(int t=0;t<4;t++)
                    if (x[r]+dx[t]>=0&&x[r]+dx[t]<n&&y[r]+dy[t]>=0&&y[r]+dy[t]<m)
                        if (step(x[r]+dx[t],y[r]+dy[t])==1)
                        {
                            F[x[r]+dx[t]][y[r]+dy[t]]=cur;
                            tmpx.push_back(x[r]+dx[t]);
                            tmpy.push_back(y[r]+dy[t]);
                        }
                for(int t=0;t<tmpx.size();t++)
                    D[tmpx[t]][tmpy[t]]='#';
                cur++;
                for(int e=0;e<24;e++)
                {
                    int cnt=0;
                    if (x[r]+dx1[e]>=0&&x[r]+dx1[e]<n&&y[r]+dy1[e]>=0&&y[r]+dy1[e]<m&&D[x[r]+dx1[e]][y[r]+dy1[e]]=='.')
                    {
                        for(int t=0;t<4;t++)
                            if (x[r]+dx1[e]+dx[t]>=0&&x[r]+dx1[e]+dx[t]<n&&y[r]+dy1[e]+dy[t]>=0&&y[r]+dy1[e]+dy[t]<m)
                                if (step(x[r]+dx1[e]+dx[t],y[r]+dy1[e]+dy[t])==1) cnt++;
                        if (cnt>0)
                        {
                            x.push_back(x[r]+dx1[e]);
                            y.push_back(y[r]+dy1[e]);
                        }
                    }
                }
            }
        }
        break;
        x.clear();
        y.clear();
        bool finded=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (D[i][j]=='.')
                {
//                  cout << cur << endl;
//                  if (cur>=90) break;
                    finded=true;
                    F[i][j]=cur;
                    D[i][j]='#';
                    for(int t=0;t<4;t++)
                        if (i+dx[t]>=0&&i+dx[t]<n&&j+dy[t]>=0&&j+dy[t]<m&&D[i+dx[t]][j+dy[t]]=='.')
                        {
                            F[i+dx[t]][j+dy[t]]=cur;
                            D[i+dx[t]][j+dy[t]]='#';
                            break;
                        }
                    cur++;
                    break;
                }
            }
            if (finded) break;
        }
        if (!finded) break;
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if (D[i][j]!='.') continue;
                    int cnt=0;
                    for(int t=0;t<4;t++)
                        if (i+dx[t]>=0&&i+dx[t]<n&&j+dy[t]>=0&&j+dy[t]<m)
                            if (step(i+dx[t],j+dy[t])==1) cnt++;
                    if (cnt>0)
                    {
                        x.push_back(i);
                        y.push_back(j);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (D[i][j]=='.')
            {
                if (D[i][j+1]=='.')
                {
                    D[i][j]=D[i][j+1]='#';
                    F[i][j]=F[i][j+1]=cur++;
                }
            }
        }
    }
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if (D[i][j]=='.'&&D[i+1][j]=='.')
            {
                D[i][j]=D[i+1][j]='#';
                F[i][j]=F[i+1][j]=cur++;
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if (D[i][j]=='.')
            {
                for(int t=0;t<4;t++)
                    if (i+dx[t]>=0&&i+dx[t]<n&&j+dy[t]>=0&&j+dy[t]<m)
                    {
                        if (F[i+dx[t]][j+dy[t]]>0)
                        {
                            F[i][j]=F[i+dx[t]][j+dy[t]];
                            D[i][j]='#';
                            break;
                        }
                    }
            }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (I[i][j]=='#') F[i][j]=-1;
//          cout << F[i][j] << "    ";
        }
//      cout << endl;
    }
    fill();
    bool ok=true;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if (ans[i][j]=='q'||ans[i][j]=='\0') ok=false;
    if (ok)
    {
        for(int i=0;i<n;i++)
            cout << ans[i] << endl;
    }
    else cout << -1 << endl;
    return 0;
}