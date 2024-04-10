#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n, a[101], b[101];
bool used[101];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                continue;
            if(b[i] == a[j])
                used[j] = true;
        }
    }
    int cnt = n;
    for(int i = 1; i <= n; i++)
        cnt -= used[i];
    cout << cnt << endl;
}