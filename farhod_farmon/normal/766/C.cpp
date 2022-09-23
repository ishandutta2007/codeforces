#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int d1[N];
int d2[N];
int d3[N];
int c[26];
string s;
bool used[26];

void solve()
{
    cin >> n >> s;
    s = "#" + s;
    for(int i = 0; i < 26; i++)
        cin >> c[i];
    d1[0] = 1;
    for(int i = 1; i < s.size(); i++){
        int f = 0;
        d2[i] = d2[i - 1];
        d3[i] = 1e9;
        char last = '#';
        for(int j = 0; j < 26; j++)
            used[j] = false;
        for(int j = i; j > 0; j--){
            if(s[j] == last)
                f++;
            else{
                last = s[j];
                f = 1;
            }
            used[s[j] - 'a'] = true;
            bool can = true;
            for(int h = 0; h < 26; h++)
                if(used[h] && i - j + 1 > c[h])
                    can = false;
            if(!can)
                break;
            d1[i] = (d1[i] + d1[j - 1]) % mod;
            d2[i] = max(d2[i], i - j + 1);
            d3[i] = min(d3[i], d3[j - 1] + 1);
        }
    }
    cout << d1[n] << endl;
    cout << d2[n] << endl;
    cout << d3[n] << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t = 1;
    if(mtest)
        cin >> t;
    while(t--)
        solve();
}