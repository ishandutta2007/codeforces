#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 505;

using namespace std;

int d[N][N];

int solve(int u, int v)
{
        int bal = 0, res = 1, last_shit = 0;
        for(int i = 0; i < 30; i++){
                int x = (u >> i) & 1;
                int y = (v >> i) & 1;
                if(x && !y){
                        bal += 1;
                        last_shit = 1;
                } else if(!x && y){
                        bal -= 1;
                        if(bal < 0){
                                res = 0;
                        }
                        last_shit = 0;
                }
        }
        if(last_shit || !res){
                return 0;
        } else{
                return 1;
        }

}

int bot(int x, int y)
{
        return d[x][y];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        /*
        for(int i = N - 1; i >= 0; i--){
                d[i][i] = 1;
                for(int j = 1; j < N; j++){
                        if((i & j) != j || i + j >= N){
                                continue;
                        }
                        for(int h = 1; h < N; h++){
                                d[i][h] |= d[i + j][h];
                        }
                }
        }

        for(int i = 1; i < N; i++){
                for(int j = 1; j < N; j++){
                        if(bot(i, j) != solve(i, j)){
                                cout << i << " " << j << " " << d[i][j] << "\n";
                                return 0;
                        }
                }
        }
        */

        int q;
        cin >> q;
        while(q--){
                int u, v;
                cin >> u >> v;

                cout << (solve(u, v) ? "YES" : "NO") << "\n";
        }
}