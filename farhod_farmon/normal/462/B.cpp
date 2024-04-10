#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

char c;
long long n, k;
long long d[26];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(long long i = 1; i <= n; i++){
        cin >> c;
        d[c - 'A']++;
    }
    sort(d, d + 26);
    long long score = 0;
    for(long long i = 25; i >= 0; i--){
        long long g = min(k, d[i]);
        score += g * g;
        k -= g;
    }
    cout << score << endl;
}