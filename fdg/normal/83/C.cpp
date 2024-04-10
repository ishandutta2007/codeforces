#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int n,m,k,sx,sy,fx,fy;
char D[52][52]={0};
int F[52][52]={0};
string best="";
bool was=false;

char sym[256]={0};

void solve()
{
    int used[52][52]={0};
    used[sx][sy]=1;
    vector <int> x(1,sx),y(1,sy);
    int dx[]={-1,0,0,1},
        dy[]={0,-1,1,0};
    for(int i=0;i<x.size();i++)
    {
        for(int t=0;t<4;t++)
        {
            int cx=x[i]+dx[t],cy=y[i]+dy[t];
            if (cx>=0&&cx<n&&cy>=0&&cy<m)
            {
                if (!used[cx][cy]&&F[cx][cy])
                {
                    used[cx][cy]=used[x[i]][y[i]]+1;
                    x.push_back(cx);
                    y.push_back(cy);
                }
            }
        }
    }
    if (used[fx][fy])
    {
        int curx=fx,cury=fy;
        string res="";
        x.clear(); y.clear();
        x.push_back(fx);
        y.push_back(fy);
        vector <int> nx,ny;
        while(true)
        {
            char c='z';
            for(int i=0;i<x.size();i++)
            {
                curx=x[i]; cury=y[i];
                for(int t=0;t<4;t++)
                {
                    int cx=curx+dx[t],cy=cury+dy[t];
                    if (cx>=0&&cx<n&&cy>=0&&cy<m&&used[cx][cy]==used[curx][cury]-1) c=min(c,D[cx][cy]);
                }
            }
            bool poss[52][52]={0};
            if (c!='T') res+=c;
            for(int i=0;i<x.size();i++)
            {
                curx=x[i]; cury=y[i];
                for(int t=0;t<4;t++)
                {
                    int cx=curx+dx[t],cy=cury+dy[t];
                    if (cx>=0&&cx<n&&cy>=0&&cy<m&&used[cx][cy]==used[curx][cury]-1&&D[cx][cy]==c&&!poss[cx][cy])
                    {
                        poss[cx][cy]=true;
                        nx.push_back(cx);
                        ny.push_back(cy);
                    }
                }
            }
            x=nx; y=ny;
            nx.clear(); ny.clear();
            if (c=='T') break;
        }
        if (!was||res.size()<best.size()||res.size()==best.size()&&res<best) best=res;
        was=true;
//      cout << res << endl;
    }
}

void fill(int left = k,char last = 'a'-1)
{
    if (left==0)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if (D[i][j]=='S'||D[i][j]=='T'||sym[D[i][j]]) F[i][j]=1;
                else F[i][j]=0;
        solve();
        return;
    }
    for(char a=last+1;a<='z';a++)
    {
        sym[a]=true;
        fill(left-1,a);
        sym[a]=false;
    }
}
int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        cin >> D[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (D[i][j]=='T') sx=i,sy=j;
            if (D[i][j]=='S') fx=i,fy=j;
        }
    }
    fill();
    if (was) cout << best << endl;
    else cout << -1 << endl;
    return 0;
}