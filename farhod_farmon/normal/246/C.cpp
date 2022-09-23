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

int n, k, a[55];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 0; i < n && k; i++){
        for(int j = 1; j <= n - i && k; j++, k--){
            cout << i + 1 << " " << a[j] << " ";
            for(int h = n - i + 1; h <= n; h++)
                cout << a[h] << " ";
            cout << endl;
        }
    }
}