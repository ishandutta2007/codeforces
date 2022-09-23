#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;

using namespace std;

int inf = 1e9;

int n;
int k;
int a[N][10];
bool d[N][N];
string s[10] = {
"1110111",
"0010010",
"1011101",
"1011011",
"0111010",
"1101011",
"1101111",
"1010010",
"1111111",
"1111011"
};

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                string t;
                cin >> t;
                for(int j = 0; j < 10; j++){
                        for(int h = 0; h < 7; h++){
                                if(t[h] == '1'){
                                        if(s[j][h] == '0'){
                                                a[i][j] = inf;
                                        }
                                } else if(s[j][h] == '1'){
                                        a[i][j] += 1;
                                }
                        }
                }
        }
        d[n + 1][0] = 1;
        for(int i = n; i >= 1; i--){
                for(int j = 0; j <= k; j++){
                        for(int h = 0; h < 10; h++){
                                if(a[i][h] <= j && d[i + 1][j - a[i][h]]){
                                        d[i][j] = 1;
                                        break;
                                }
                        }
                }
        }
        vector < int > res;
        for(int i = 1; i <= n; i++){
                for(int j = 9; j >= 0; j--){
                        if(k < a[i][j]){
                                continue;
                        }
                        if(d[i + 1][k - a[i][j]]){
                                res.push_back(j);
                                k -= a[i][j];
                                break;
                        }
                }
                if(res.empty()){
                        cout << -1 << "\n";
                        return 0;
                }
        }
        for(int x: res) cout << x;
}