#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 20;

using namespace std;

int n;
int m;
string s;
int d[1 << N];
int c[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> s;
        for(int i = 1; i < n; i++){
                int x = s[i - 1] - 'a', y = s[i] - 'a';
                if(x == y){
                        continue;
                }

                c[x][y] += 1;
                c[y][x] += 1;
        }

        vector < int > A, B;
        for(int i = 1; i < (1 << m); i++){
                d[i] = 1e9;
                A.clear();
                B.clear();

                for(int j = 0; j < m; j++){
                        if(i & (1 << j)){
                                A.push_back(j);
                        } else{
                                B.push_back(j);
                        }
                }

                int place = __builtin_popcount(i);
                for(int x: A){
                        int c1 = 0, c2 = 0;
                        for(int y: B){
                                c1 += c[x][y];
                        }
                        for(int y: A){
                                c2 += c[x][y];
                        }
                        d[i] = min(d[i], d[i ^ (1 << x)] + place * (c2 - c1));
                }
        }

        cout << d[(1 << m) - 1] << "\n";
}