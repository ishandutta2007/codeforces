#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 26;

using namespace std;

int n;
int a[N];
int d[N][N];
bool used[N];

void f()
{
    d[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            d[i][j] = d[i - 1][j];
            if(j >= a[i] && !used[i])
                d[i][j] |= d[i - 1][j - a[i]];
        }
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    if(a[n] != n){
        cout << "NO" << endl;
        return 0;
    }
    f();
    for(int i = 1; i <= n; i++){
        int need = a[i] - 1;
        for(int j = i - 1; j >= 1; j--){
            if(need >= a[j] && d[j - 1][need - a[j]] && !used[j] && a[j] != a[i] - 1){
                used[j] = true;
                need -= a[j];
                f();
            }
        }
        if(need){
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int i = 1; i < n; i++){
        if(!used[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}