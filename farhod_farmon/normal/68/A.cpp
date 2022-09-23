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

vector < pair < pair < int, int >, pair < int, int > > > v;
int p[4], a, b;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j)
                continue;
            for(int h = 0; h < 4; h++){
                if(h == i || h == j)
                    continue;
                int k = 6 - i - j - h;
                v.pb({{p[i], p[j]}, {p[h], p[k]}});
            }
        }
    }
    int ans = 0;
    for(int i = a; i <= b; i++){
        int cnt = 0;
        for(auto p: v){
            if((((i % p.fi.fi) % p.fi.se) % p.se.fi) % p.se.se == i)
                cnt++;
        }
        ans += (cnt >= 7);
    }
    cout << ans << endl;
}