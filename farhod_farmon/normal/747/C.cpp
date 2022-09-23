#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;
const int MX = 10010;

using namespace std;

int n;
int q;
int en[111];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1; i <= q; i++){
        int t, k, d, cnt = 0;
        cin >> t >> k >> d;
        for(int j = 1; j <= n; j++)
            if(en[j] < t)
                cnt++;
        if(cnt < k){
            cout << -1 << endl;
            continue;
        }
        cnt = 0;
        for(int j = 1; j <= n && k; j++){
            if(en[j] < t){
                en[j] = t + d - 1;
                cnt += j;
                k--;
            }
        }
        cout << cnt << endl;
    }
}