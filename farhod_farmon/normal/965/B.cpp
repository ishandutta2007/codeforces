#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int Q = 1000010;

using namespace std;

int n;
int k;
int score[N][N];
string s[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 0; i < n; i++){
                cin >> s[i];
        }

        int best_x = 0, best_y = 0, best = 0;

        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        if(s[i][j] == '#'){
                                continue;
                        }
                        bool good = true;
                        for(int h = 0; h < k; h++){
                                //i, j + h
                                if(j + h >= n || s[i][j + h] == '#'){
                                        good = false;
                                }
                        }
                        if(good){
                                for(int h = 0; h < k; h++){
                                        score[i][j + h] += 1;
                                }
                        }

                        good = true;
                        for(int h = 0; h < k; h++){
                                //i, j + h
                                if(i + h >= n || s[i + h][j] == '#'){
                                        good = false;
                                }
                        }
                        if(good){
                                for(int h = 0; h < k; h++){
                                        score[i + h][j] += 1;
                                }
                        }
                }
        }

        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        if(score[i][j] > score[best_x][best_y]){
                                best_x = i;
                                best_y = j;
                        }
                }
        }

        cout << best_x + 1 << " " << best_y + 1 << "\n";
}