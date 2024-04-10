#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int get(char c)
{
    if(c == '-')
        return 62;
    if(c == '_')
        return 63;
    if('0' <= c && c <= '9')
        return c - '0';
    if('A' <= c && c <= 'Z')
        return c - 'A' + 10;
    return c - 'a' + 36;
}

lli n, ans = 1, d[64], mod = 1e9 + 7;
string s;

int main()
{
    cin >> s;
    for(int i = 0; i < 64; i++)
        for(int j = 0; j < 64; j++)
            d[i & j]++;
    for(int i = 0; i < s.size(); i++)
        ans = (ans * d[get(s[i])]) % mod;
    cout << ans << endl;
}