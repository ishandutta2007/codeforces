#include <bits/stdc++.h>
using namespace std;

const int NAX = 2005;
const int INF = 1e9 + 5;

char grid[NAX][NAX];
// grid[row][col]

int dp[NAX][NAX];
// dp[row][col]
// the minimum number of changes we need so far,
// in order to get to cell (row, col) with a's

void mini(int& a, int b) {
    a = min(a, b);
}
void maxi(int& a, int b) {
    a = max(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    auto inside = [&](int row, int col) {
        return 0 <= row && 0 <= col && row < n && col < n;
    };
    cin >> n >> k;
    for(int row = 0; row < n; ++row) {
        cin >> grid[row];
    }
    
    for(int row = 0; row < n; ++row) {
        for(int col = 0; col < n; ++col) {
            dp[row][col] = INF;
        }
    }
    
    dp[0][0] = 0;
    for(int row = 0; row < n; ++row) {
        for(int col = 0; col < n; ++col) {
            if(row != 0) {
                mini(dp[row][col], dp[row-1][col]);
            }
            if(col != 0) {
                mini(dp[row][col], dp[row][col-1]);
            }
            if(grid[row][col] != 'a') {
                ++dp[row][col];
            }
        }
    }
    //~ for(int row = 0; row < n; ++row) {
        //~ for(int col = 0; col < n; ++col) {
            //~ cout << dp[row][col];
        //~ }
        //~ cout << "\n";
    //~ }
    
    int pref = 0;
    for(int row = 0; row < n; ++row) {
        for(int col = 0; col < n; ++col) {
            if(dp[row][col] <= k) {
                maxi(pref, row + col + 1);
            }
        }
    }
    cerr << pref << endl;
    string answer(pref, 'a');
    vector<pair<int,int>> list;
    for(int row = 0; row < n; ++row) {
        for(int col = 0; col < n; ++col) {
            if(dp[row][col] <= k && row + col + 1 == pref) {
                list.push_back(make_pair(row, col));
            }
        }
    }
    if(list.empty()) {
        list.emplace_back(0, 0);
        answer += grid[0][0];
    }
    //~ for(pair<int,int> p : list) {
        //~ cout << p.first << " " << p.second << "\n";
    //~ }
    while(!list.empty()) {
        char best_char = 'z';
        vector<pair<int,int>> new_list;
        for(pair<int,int> p : list) {
            for(int d_row : {0, 1}) { // for(int dx = 0; dx < 2; ++dx) {
                int d_col = 1 - d_row;
                int r2 = p.first + d_row;
                int c2 = p.second + d_col;
                if(inside(r2, c2)) {
                    if(grid[r2][c2] <= best_char) {
                        if(grid[r2][c2] < best_char) {
                            new_list.clear();
                        }
                        best_char = grid[r2][c2];
                        new_list.push_back(make_pair(r2, c2));
                        //~ new_list.emplace_back(r2, c2);
                    }
                }
            }
        }
        if(new_list.empty()) {
            break;
        }
        answer += best_char;
        list = new_list;
        
        // remove repeatitions from list
        sort(list.begin(), list.end());
        list.resize( unique(list.begin(), list.end()) - list.begin() );
    }
    
    cout << answer << "\n";
}