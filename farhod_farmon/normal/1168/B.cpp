#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 300300;
const int Q = 100100;
const int MAGIC = 130;

using namespace std;

int n;
string s;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> s;
        int l, r;
        vector < pair < int, int > > v;
        for(int i = 0; i < s.size(); i++){
                for(int j = 1; j < 1111; j++){
                        if(i - j < 0 || i + j >= s.size()){
                                break;
                        }
                        if(s[i - j] == s[i + j] && s[i] == s[i - j]){
                                v.push_back({i - j, i + j});
                                break;
                        }
                }
        }
        sort(v.begin(), v.end());
        long long res = 0;
        for(int i = (int)v.size() - 2; i >= 0; i--){
                v[i].se = min(v[i].se, v[i + 1].se);
        }
        for(int i = 0, j = 0; i < s.size(); i++){
                while(j < v.size() && v[j].fi < i){
                        j += 1;
                }
                if(j == v.size()){
                        break;
                }
                res += s.size() - v[j].se;
        }
        cout << res << "\n";
}