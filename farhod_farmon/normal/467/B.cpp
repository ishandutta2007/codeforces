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

int n, m, k;
int x[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m + 1; i++)
        cin >> x[i];
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        int h = 0;
        for(int j = 0; j < n; j++){
            int a = (x[i] & (1 << j)),
                b = (x[m + 1] & (1 << j));
            if(a != b)
                h++;
        }
        if(h <= k)
            cnt++;
    }
    cout << cnt << endl;
}