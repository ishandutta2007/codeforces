#include <stdio.h>
#include <queue>
#include <map>
#define INF 1e9

using namespace std;

int R, C, test[4][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, pieceN;
char field[16][16];
struct State{
    int x[9], y[9];
    bool operator<(const State &other) const{
        for(int i=0; i < pieceN; ++i){
            if(x[i] < other.x[i])
                return 1;
            if(x[i] > other.x[i])
                return 0;
            if(y[i] < other.y[i])
                return 1;
            if(y[i] > other.y[i])
                return 0;
        }
        return 0;
    }
};
queue<State> Q;

bool inside(int x, int y){
    if(x < 0 || y < 0 || x >= C || y >= R)
        return 0;
    return 1;
}

map<State, int> dp;

int main()
{
    scanf("%d%d", &R, &C);
    for(int i=0; i < R; ++i)
        scanf("%s", field[i]);
    State start;
    for(int i=0; i < R; ++i)
        for(int j=0; j < C; ++j){
            if(field[i][j] == '1'){
                start.x[0]=j;
                start.y[0]=i;
                pieceN=1;
                int n=2, X=j, Y=i;
                bool ok=1;
                while(ok){
                    ok=0;
                    for(int k=0; k < 4; ++k){
                        if(!inside(X+test[k][0], Y+test[k][1]))
                            continue;
                        if(field[Y+test[k][1]][X+test[k][0]] == '0'+n){
                            ok=1;
                            X += test[k][0];
                            Y += test[k][1];
                            start.x[n-1]=X;
                            start.y[n-1]=Y;
                            ++pieceN;
                            ++n;
                            break;
                        }
                    }
                }
                dp[start]=1;
                Q.push(start);
            }
        }
    int ans=INF;
    while(!Q.empty() && ans == INF){
        State S=Q.front();
        State New;
        Q.pop();
        if(field[S.y[0]][S.x[0]] == '@'){
            ans=dp[S]-1;
        }
        for(int k=0; k < 4; ++k){
            int X=S.x[0]+test[k][0], Y=S.y[0]+test[k][1];
            if(!inside(X, Y))
                continue;
            if(field[Y][X] == '#')
                continue;
            bool ok=1;
            for(int m=1; m < pieceN-1; ++m){
                if(X == S.x[m] && Y == S.y[m])
                    ok=0;
            }
            if(!ok)
                continue;
            New.x[0]=X;
            New.y[0]=Y;
            for(int m=1; m < pieceN; ++m){
                New.x[m]=S.x[m-1];
                New.y[m]=S.y[m-1];
            }
            if(dp[New] == 0){
                dp[New]=dp[S]+1;
                Q.push(New);
            }
        }
    }
    printf("%d", ans==INF?-1:ans);
    return 0;
}