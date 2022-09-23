#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3030;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        string s;
        cin >> n >> s;

        int A = 0;
        for(char c: s){
                A += (c == 'B');
        }
        int B = n - A;

        char need;
        if(A % 2 == 0){
                need = 'W';
        } else if(B % 2 == 0){
                need = 'B';
        } else{
                cout << -1 << "\n";
                return 0;
        }

        vector < int > res;
        for(int i = 0; i < n - 1; i++){
                if(s[i] == need){
                        continue;
                }
                res.push_back(i + 1);

                s[i + 1] = 'B' + 'W' - s[i + 1];
        }

        cout << res.size() << "\n";
        for(int x: res){
                cout << x << " ";
        }
}