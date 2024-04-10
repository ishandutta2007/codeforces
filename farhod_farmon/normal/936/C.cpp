#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
string s, t;
vector < int > res;

void shift(int x)
{
        res.push_back(x);
        string A = "", B = "";
        for(int i = n - x; i < n; i++){
                B += s[i];
        }
        for(int i = 0; i < n - x; i++){
                A += s[i];
        }
        reverse(B.begin(), B.end());
        s = B + A;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> s >> t;

        for(int i = 0; i < n; i++){
                int j = 0;
                while(j < n && s[j] != t[i]){
                        j += 1;
                }
                if(j >= n - i){
                        cout << -1 << "\n";
                        return 0;
                }
                shift(n - j - 1);
                shift(1);
                shift(n);
        }

        assert(s == t);
        cout << res.size() << "\n";
        for(int x: res) cout << x << " ";
}