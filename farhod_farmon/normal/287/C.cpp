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

int n, p[N];
int l;

void dfs(int x)
{
    p[p[x]] = n - x + 1;
    int y = p[x];
    while(y != x){
        p[p[y]] = n - y + 1;
        y = p[y];
    }
}

int main()
{
	//fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    if(n % 2)
        p[n / 2 + 1] = n / 2 + 1;
    for(int i = 1; i <= n; i++){
        if(p[i])
            continue;
        l = i;
        p[i] = i + 1;
        dfs(i);
    }
    for(int i = 1; i <= n; i++){
        if(p[p[i]] != n - i + 1){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << p[i] << " ";
}