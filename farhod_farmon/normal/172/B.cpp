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

int l[N];
int L;
int a;
int b;
int m;
int r;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a >> b >> m >> r;
    while(!l[r]){
        l[r] = ++L;
        r = (r * a + b) % m;
    }
    cout << L - l[r] + 1 << endl;
}