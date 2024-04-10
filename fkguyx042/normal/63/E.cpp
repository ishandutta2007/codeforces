#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int dp[1<<20], can[1<<20], two[20];
vector<int> move;

void dfs(int state){
    if (dp[state] > -1) return;
    dp[state] = 0;
    for (int i = 0; i < move.size(); ++i){
        if (state & move[i]){
            dfs(state ^ move[i]);
            if (dp[state^move[i]] == 0){
                dp[state] = 1;
            }
        }
    }
}

int main(){
   // freopen("in", "r", stdin);

    for (int i = 0; i < 19; ++ i){
        two[i] = (1 << i);
    }
    can[two[0]+two[1]+two[2]] = 1;
    can[two[3]+two[4]+two[5]+two[6]] = 1;
    can[two[7]+two[8]+two[9]+two[10]+two[11]] = 1;
    can[two[12]+two[13]+two[14]+two[15]] = 1;
    can[two[16]+two[17]+two[18]] = 1;
    can[two[0]+two[3]+two[7]] = 1;
    can[two[1]+two[4]+two[8]+two[12]] = 1;
    can[two[2]+two[5]+two[9]+two[13]+two[16]] = 1;
    can[two[6]+two[10]+two[14]+two[17]] = 1;
    can[two[11]+two[15]+two[18]] = 1;
    can[two[2]+two[6]+two[11]] = 1;
    can[two[1]+two[5]+two[10]+two[15]] = 1;
    can[two[0]+two[4]+two[9]+two[14]+two[18]] = 1;
    can[two[3]+two[8]+two[13]+two[17]] = 1;
    can[two[7]+two[12]+two[16]] = 1;

    for (int i = (1 << 19) - 1; i >= 0; -- i){
        for (int j = 0; j < 19; ++ j){
            if ((1 << j) & i){
                can[i^(1<<j)] |= can[i];
                break;
            }
        }
        for (int j = 18; j >= 0; -- j){
            if ((1 << j) & i){
                can[i^(1<<j)] |= can[i];
                break;
            }
        }
    }

    for (int i = 1; i < (1 << 19); ++ i){
        if (can[i]) move.push_back(i);
    }

    dp[0] = 0;
    for (int state = 1; state < (1 << 19); ++ state){
        for (int i = 0; i < move.size(); ++ i){
            if ((state ^ move[i]) == state - move[i] && dp[state^move[i]] == 0){
                dp[state] = 1;
                break;
            }
        }
    }

    char ch[55];
    int now = 0, state = 0;
    for (int i = 0; i < 19; ++ i){
        scanf("%s", ch);
        int m = strlen(ch);
        for (int j = 0; j < m; ++ j){
            if (ch[j] != '.' && ch[j] != 'O') continue;
            state += (ch[j] == 'O') ? (1 << now) : 0;
            now ++;
        }
    }

    if (dp[state]){
        puts("Karlsson");
    } else {
        puts("Lillebror");
    }
    return 0;
}