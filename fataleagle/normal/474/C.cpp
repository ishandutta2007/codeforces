#include <bits/stdc++.h>

using namespace std;

void rot(int x, int y, int ox, int oy, int& outx, int& outy)
{
    int nx=x-ox, ny=y-oy;
    //nx  ny  cos(M_PI/2) -sin(M_PI/2)
    //        sin(M_PI/2) cos(M_PI/2)
    int nnx=nx*0-ny*1;
    int nny=nx*1+ny*0;
    outx=nnx+ox;
    outy=nny+oy;
}

void rot(pair<int, int> xy, pair<int, int> oxoy, int& outx, int& outy)
{
    rot(xy.first, xy.second, oxoy.first, oxoy.second, outx, outy);
}

long long D(pair<int, int> a, pair<int, int> b)
{
    long long dx=a.first-b.first;
    long long dy=a.second-b.second;
    return dx*dx+dy*dy;
}

void solve()
{
    pair<pair<int, int>, pair<int, int>> moles[4];
    for(int i=0; i<4; i++)
        scanf("%d%d%d%d", &moles[i].first.first, &moles[i].first.second, &moles[i].second.first, &moles[i].second.second);
    long long dist[10];
    pair<int, int> pos[4];
    int ans=0x3f3f3f3f;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            for(int k=0; k<4; k++)
                for(int l=0; l<4; l++)
                {
                    int arr[4]={i, j, k, l};
                    for(int m=0; m<4; m++)
                    {
                        pos[m]=moles[m].first;
                        for(int n=0; n<arr[m]; n++)
                            rot(pos[m], moles[m].second, pos[m].first, pos[m].second);
                    }
                    int o=0;
                    for(int m=0; m<4; m++)
                        for(int n=0; n<m; n++)
                            dist[o++]=D(pos[m], pos[n]);
                    sort(dist, dist+o);
                    if(dist[0]!=0 && dist[0]==dist[1] && dist[1]==dist[2] && dist[2]==dist[3] && dist[0]*2==dist[4] && dist[0]*2==dist[5])
                        ans=min(ans, i+j+k+l);
                }
    printf("%d\n", ans==0x3f3f3f3f?-1:ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}