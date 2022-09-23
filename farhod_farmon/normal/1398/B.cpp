#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = N * 50;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                string s;
                cin >> s;
                int cnt = 0;
                vector < int > v;
                s += "0";
                for(char x: s){
                        if(x == '0'){
                                if(cnt > 0) v.push_back(cnt);
                                cnt = 0;
                        } else{
                                cnt += 1;
                        }
                }
                sort(v.begin(), v.end());
                reverse(v.begin(), v.end());
                int res = 0;
                for(int i = 0; i < v.size(); i += 2) res += v[i];
                cout << res << "\n";
        }
}