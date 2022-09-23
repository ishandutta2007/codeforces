#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

int n;
int w[N];
int h[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> h[i];
    int ans = 1e9;
    for(int t = 0; t < 2; t++){
        for(int i = 1; i <= n; i++){
            bool can = true;
            int s = 0;
            for(int j = 1; j <= n; j++){
                if(i == j){
                    s += h[i];
                    continue;
                }
                if(max(w[j], h[j]) <= w[i])
                    s += min(w[j], h[j]);
                else if(min(w[j], h[j]) <= w[i])
                    s += max(w[j], h[j]);
                else
                    can = false;
            }
            if(can)
                ans = min(ans, s * w[i]);
        }
        for(int i = 1; i <= n; i++)
            swap(w[i], h[i]);
    }
    cout << ans << endl;
}