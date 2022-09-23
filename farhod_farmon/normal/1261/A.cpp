#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 150500;

using namespace std;

int n;
int k;
string s;

void solve()
{
        cin >> n >> k >> s;
        string need = "";
        for(int i = 0; i < n / 2 - k + 1; i++){
                need += "(";
        }
        for(int i = 0; i < n / 2 - k + 1; i++){
                need += ")";
        }
        for(int i = 1; i < k; i++){
                need += "()";
        }
        vector < pair < int, int > > res;
        for(int i = 0; i < n; i++){
                if(s[i] == need[i]){
                        continue;
                }
                for(int j = i; j < n; j++){
                        if(s[j] == need[i]){
                                reverse(s.begin() + i, s.begin() + j + 1);
                                res.push_back({i + 1, j + 1});
                                break;
                        }
                }
                assert(s[i] == need[i]);
        }
        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi << " " << p.se << "\n";
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}