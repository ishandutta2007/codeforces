#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 50050;

using namespace std;

int n, a[N], b[N];

bool can(int x)
{
    map < int, bool > used;
    for(int i = 1; i <= n; i++){
        b[i] = a[i];
        while((used.find(b[i]) != used.end() || b[i] > x) && b[i])
            b[i] /= 2;
        if(b[i] == 0)
            return false;
        used[b[i]] = true;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, r = 1e9;
    while(l < r){
        int m = (l + r) / 2;
        if(!can(m))
            l = m + 1;
        else
            r = m;
    }
    can(l);
    for(int i = 1; i <= n; i++)
        cout << b[i] << " ";
}