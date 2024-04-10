#include <bits/stdc++.h>

using namespace std;

const int nax = 2000+10;
int n,k;

string digit[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
string t[nax];
bool can[nax][nax];
int hw[nax][10];

int cost(string &a,string &b) {
    int cnt = 0;
    for(int i = 0; i < (int)a.size(); ++i) {
        if(a[i] == '1' && b[i] == '0') return 8;
        cnt += (a[i] != b[i]);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> t[i];
        for(int j = 0; j < 10; ++j) {
            hw[i][j] = cost(t[i],digit[j]);
        }
    }
    can[n+1][0] = 1;
    for(int i = n; i >= 1; --i) {
        for(int j = 0; j <= k; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                if(hw[i][ii] == 8 || hw[i][ii] > j) continue;
                can[i][j] = can[i][j] | can[i+1][j - hw[i][ii]];
            }
        }
    }
    string ans = "";
    for(int i = 1; i <= n; ++i) {
        for(int j = 9; j >= -1; --j) {
            if(j == -1) {
                cout << "-1";
                return 0;
            }
            if(hw[i][j] != 8 && k >= hw[i][j] && can[i+1][k - hw[i][j]]) {
                k -= hw[i][j];
                ans += (char)(j + '0');
                break;
            }
        }
    }
    cout << ans;
}