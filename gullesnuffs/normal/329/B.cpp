#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int r, c;
char field[1005][1005];
pair<int, int> endPos;
queue<pair<int, int> > q;
int dis[1005][1005];
int test[4][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool testInside(int i, int j){
    if(i < 0 || j < 0 || i >= r || j >= c)
        return 0;
    return 1;
}

int main()
{
    scanf("%d%d", &r, &c);
    for(int i=0; i < r; ++i)
        scanf("%s", field[i]);
    for(int i=0; i < r; ++i)
        for(int j=0; j < c; ++j){
            dis[i][j]=10000000;
            if(field[i][j] == 'E'){
                endPos=make_pair(i, j);
                dis[i][j]=0;
            }
        }
    q.push(endPos);
    int playerDis;
    while(!q.empty()){
        pair<int, int> f=q.front();
        q.pop();
        if(field[f.first][f.second] == 'S')
            playerDis=dis[f.first][f.second];
        for(int i=0; i < 4; ++i){
            int y=f.first+test[i][0];
            int x=f.second+test[i][1];
            if(!testInside(y, x))
                continue;
            if(field[y][x] == 'T')
                continue;
            if(dis[y][x] < 10000000)
                continue;
            dis[y][x]=dis[f.first][f.second]+1;
            q.push(make_pair(y, x));
        }
    }
    int ans=0;
    for(int i=0; i < r; ++i)
        for(int j=0; j < c; ++j){
            if(dis[i][j] <= playerDis && field[i][j] >= '0' && field[i][j] <= '9')
                ans += field[i][j]-'0';

        }
    printf("%d\n", ans);
    return 0;
}