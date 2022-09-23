#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

void solve(int n)
{
        string res = "";
        if(n == 1){
                cout << -1 << "\n";
                return;
        }
        for(int i = 0; i < n - 1; i++) res += "2";
        res += "3";
        if((n - 1) * 2 % 3 == 0){
                res[res.size() - 2] = '7';
                int shit = 0;
                for(char c: res) shit = (shit * 10 + c - '0') % 7;
                assert(shit != 0);
        }
        cout << res << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        //for(int i = 2; i <= 1000; i++) solve(i);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                solve(n);
        }
}