#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll int

const int N = 500300;
const long long mod = 1e15 + 3;

using namespace std;

long long n;
long long ans;
long long d[10000];
string s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n >> s;
    s = '0' + s;
    for(int i = 1; i < s.size(); i++)
        d[i] = 1e18 + 1;
    for(int i = 1; i < s.size(); i++){
        if(d[i - 1] == 1e18 + 1)
            continue;
        long long x = 0;
        for(int j = i; j < s.size(); j++){
            x = x * 10 + s[j] - '0';
            if(x >= n)
                break;
            if(1.0 * d[i - 1] < 1.0 * (d[j] - x) / n)
                d[j] = d[i - 1] * n + x;
            if(s[i] == '0')
                break;
        }

    }
    cout << d[s.size() - 1] << endl;
}