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
const int bs = sqrt(N);

using namespace std;

int n, m, a[N];
int c[N];
int nxt[N];

void build()
{
    for(int i = n; i >= 1; i--){
        int cur = (i - 1) / bs + 1;
        int nt = (i + a[i] - 1) / bs + 1;
        if(i + a[i] > n){
            nxt[i] = i;
            c[i] = 0;
        }
        else if(nt == cur){
            nxt[i] = nxt[i + a[i]];
            c[i] = c[i + a[i]] + 1;
        }
        else{
            nxt[i] = i + a[i];
            c[i] = 1;
        }
    }
}

void upd(int x)
{
    int f = (x - 1) / bs + 1;
    int l = bs * (f - 1) + 1;
    for(int i = x; i >= l; i--){
        int cur = (i - 1) / bs + 1;
        int nt = (i + a[i] - 1) / bs + 1;
        if(i + a[i] > n){
            nxt[i] = i;
            c[i] = 0;
        }
        else if(nt == cur){
            nxt[i] = nxt[i + a[i]];
            c[i] = c[i + a[i]] + 1;
        }
        else{
            nxt[i] = i + a[i];
            c[i] = 1;
        }
    }
}

pair < int, int > get(int x)
{
    pair < int, int > p = {1, nxt[x]};
    while(x != nxt[x]){
        p.fi += c[x];
        p.se = nxt[x];
        x = nxt[x];
    }
    return p;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build();
    for(int i = 1; i <= m; i++){
        int t, x, y;
        cin >> t >> x;
        if(t == 0){
            cin >> y;
            a[x] = y;
            upd(x);
        }
        else{
            pair < int, int > p = get(x);
            cout << p.se << " " << p.fi << endl;
        }
    }
}