#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        string s;
        cin >> s;
        long long res = 0;
        for(char c: s){
                res = res * 16;
                if('0' <= c && c <= '9') res += c - '0';
                else res += 10 + c - 'A';
        }
        cout << res % 2 << endl;
}