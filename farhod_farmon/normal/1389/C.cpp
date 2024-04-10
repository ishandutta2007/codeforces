#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

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
                vector < int > v;
                int res = 0;
                for(int i = 0; i < 10; i++){
                        int cnt = 0;
                        for(char c: s){
                                cnt += ((c - '0') == i);
                        }
                        if(cnt % 2 == 0) cnt -= 1;
                        res = max(res, cnt);
                        for(int j = 0; j < 10; j++){
                                cnt = 0;
                                int g = 0;
                                for(char c: s){
                                        if(g == 0 && (c - '0') == i){
                                                g = 1;
                                        } else if(g == 1 && (c - '0') == j){
                                                g = 0;
                                                cnt += 1;
                                        }
                                }
                                res = max(res, cnt * 2);
                        }
                }
                cout << s.size() - res << "\n";
        }
}