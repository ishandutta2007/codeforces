#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 2020;

using namespace std;

int n, m, a[N];
map < int, int > c;
int cnt;

void upd(int x)
{
    c[x]++;
    cnt++;
    for(int i = 1; i <= n; i++){
        if(c[a[i]] > n / m || a[i] > m){
            c[a[i]]--;
            a[i] = x;
            return;
        }
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        c[a[i]]++;
    }
    for(int i = 1; i <= m; i++)
        while(c[i] < n / m)
            upd(i);
    cout << n / m << " " << cnt << endl;
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
}