#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

string s;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> s;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
                cnt += s[i] == 'a';
        }

        int n = s.size();
        cout << min(cnt * 2 - 1, n) << "\n";
}