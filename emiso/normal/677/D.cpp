#include <bits/stdc++.h>

#define INF 987654321

#define MP(a,b) make_pair(a,b)
#define MP3(a,b,c) make_pair(a,make_pair(b,c))

using namespace std;

int n,m,p,ans[303][303],t[303][303],dist[303][303],tr,xr,yr;

vector<pair<int,int> > chest[90090];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool check_bound(int x, int y) {
    if(!x || !y || x > n || y > m) return false;
    return true;
}

int gdis(int x1,int y1,int x2,int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

void bfs(int k) {

    priority_queue <pair<int, pair<int,int> > > pfila;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {

            if(t[i][j] == k) {
                dist[i][j] = ans[i][j];
                pfila.push(MP3(-dist[i][j],i,j));
            }

            else dist[i][j] = INF;
        }
    }

    while(!pfila.empty()) {

        int d = -pfila.top().first;
        int x = pfila.top().second.first;
        int y = pfila.top().second.second;

        pfila.pop();

        if(d <= dist[x][y]) {
            for(int i=0;i<4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(!check_bound(nx,ny) || dist[nx][ny] <= dist[x][y] + 1) continue;

                    dist[nx][ny] = dist[x][y] + 1;
                    pfila.push(MP3(-dist[nx][ny],nx,ny));
            }
        }
    }
}

int main() {
    scanf("%d %d %d",&n,&m,&p);

    for(int i=1;i<=n;i++) {

        for(int j=1;j<=m;j++) {

            scanf("%d",&t[i][j]);

            chest[t[i][j]].push_back(MP(i,j));
            ans[i][j] = INF;

            if(tr < t[i][j]) {
                tr = t[i][j];
                xr = i;
                yr = j;
            }
        }
    }

    for(int P=1;P<=p;P++) {
        if(P == 1) {
            for(int i=0;i<chest[P].size();i++) {

                int x = chest[P][i].first;
                int y = chest[P][i].second;

                ans[x][y] = x + y - 2;
            }
        }

        else if(chest[P].size() * chest[P-1].size() <= 500000) {
            for(int i=0;i<chest[P].size();i++) {

                int x = chest[P][i].first;
                int y = chest[P][i].second;

                for(int j=0;j<chest[P-1].size();j++) {

                    int nx = chest[P-1][j].first;
                    int ny = chest[P-1][j].second;

                    ans[x][y] = min(ans[x][y], ans[nx][ny] + gdis(x,y,nx,ny));
                }
            }
        }

        else {
            bfs(P-1);

            for(int i=0;i<chest[P].size();i++) {

                int x = chest[P][i].first;
                int y = chest[P][i].second;

                ans[x][y] = dist[x][y];
            }
        }
    }

    printf("%d\n",ans[xr][yr]);

    /**
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) printf("%d ",ans[i][j]);
        puts("");
    }
    **/

    return 0;
}