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

int n;
bool used[5050];

int main()
{
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        used[x] = true;
    }
    for(int i = 1; i <= n; i++)
        cnt += 1 - used[i];
    cout << cnt << endl;
}