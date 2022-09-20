#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 104;

using namespace std;

string s;
int d[N][25];

int solve(int X)
{
        for(int i = 0; i <= s.size(); i++){
                for(int j = 0; j < 25; j++){
                        d[i][j] = 0;
                }
        }

        auto can = [&](char c) -> vector<int>
        {
                vector<int> res;
                if(c == 'X'){
                        res.push_back(X);
                } else if(c == '_'){
                        for(int i = 0; i < 10; i++){
                                res.push_back(i);
                        }
                } else{
                        res.push_back(c - '0');
                }
                return res;
        };

        for(int x : can(s[0])){
                if(x != 0){
                        d[0][x] = 1;
                }
        }
        for(int i = 1; i < s.size(); i++){
                for(int j = 0; j < 25; j++){
                        for(int x : can(s[i])){
                                d[i][(j * 10 + x) % 25] += d[i - 1][j];
                        }
                }
        }
        return d[s.size() - 1][0];
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);


        cin >> s;
        int X = 0;
        for(int i = 0; i < s.size(); i++){
                if(s[i] == 'X'){
                        X = 9;
                }
        }
        int res = 0;
        for(int i = 0; i <= X; i++){
                res += solve(i);
        }

        if(s.size() == 1){
                if(s[0] == '0' || s[0] == 'X' || s[0] == '_'){
                        res += 1;
                }
        }

        cout << res << "\n";
}