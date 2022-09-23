#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;

using namespace std;

int n;
int b[N];
int a[N][N];
int c[N][N];

void solve(int ok)
{
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        c[i][j] = a[i][j];
                }
        }
        int id = 0;
        for(int i = 0; i < n; i++){
                if(b[i]){
                        id = i;
                }
        }
        vector < pair < int, int > > res;
        if(ok){
                res.push_back({1, id});
                for(int j = 0; j < n; j++){
                        c[id][j] ^= b[j];
                }
        }
        for(int j = 0; j < n; j++){
                if(c[id][j]){
                        res.push_back({2, j});
                        for(int i = 0; i < n; i++){
                                c[i][j] ^= b[i];
                        }
                }
        }
        for(int i = 0; i < n; i++){
                int c1 = 1, c2 = 1;
                for(int j = 0; j < n; j++){
                        c1 &= c[i][j] == 0;
                        c2 &= c[i][j] == b[j];
                }
                if(c1){
                        continue;
                } else if(c2){
                        res.push_back({1, i});
                } else{
                        return;
                }
        }
        cout << res.size() << "\n";
        for(auto p: res){
                if(p.fi == 1){
                        cout << "row ";
                } else{
                        cout << "col ";
                }
                cout << p.se << "\n";
        }
        exit(0);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 0; i < n; i++){
                char c;
                for(int j = 0; j < n; j++){
                        cin >> c;
                        a[i][j] ^= c - '0';
                }
        }
        for(int i = 0; i < n; i++){
                char c;
                for(int j = 0; j < n; j++){
                        cin >> c;
                        a[i][j] ^= c - '0';
                }
        }
        for(int i = 0; i < n; i++){
                char c;
                cin >> c;
                b[i] ^= c - '0';
        }

        solve(0);
        solve(1);

        cout << -1 << "\n";
}