#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200200;

int n;
string s[3];

void solve()
{
        cin >> n;
        for(int i = 0; i < 3; i++){
                cin >> s[i];
        }
        for(char c: {'0', '1'}){
                vector < int > v;
                for(int i = 0; i < 3; i++){
                        int cnt = 0;
                        for(char x: s[i]){
                                cnt += (x == c);
                        }
                        if(cnt >= n){
                                v.push_back(i);
                        }
                }
                if(v.size() < 2){
                        continue;
                }
                int X = v[0], Y = v[1];
                vector < int > A(1, 0), B(1, 0);
                for(int j = 0; j < 2 * n; j++){
                        if(s[X][j] == c){
                                A.push_back(0);
                        } else{
                                A.back() += 1;
                        }
                        if(s[Y][j] == c){
                                B.push_back(0);
                        } else{
                                B.back() += 1;
                        }
                }
                int G = max(A.size(), B.size());
                string res = "";
                for(int i = 0; i < G; i++){
                        int x = 0;
                        if(i < A.size()){
                                x = max(x, A[i]);
                        }
                        if(i < B.size()){
                                x = max(x, B[i]);
                        }
                        res += string(x, '0' + '1' - c);
                        if(i + 1 < G){
                                res += c;
                        }
                }
                assert((int)res.size() <= 3 * n);
                cout << res << "\n";
                break;
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}