#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int n;
int a[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        if(a[i] < 0){
            cout << "NO" << endl;
            return 0;
        }
        if(a[i] % 2)
            a[i + 1]--;
        a[i] = 0;
    }
    if(a[n + 1] < 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}