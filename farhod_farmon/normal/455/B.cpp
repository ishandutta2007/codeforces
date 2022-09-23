#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

int n, t[N][27], sz = 1, k, win[N], lose[N];

void add( string s )
{
    int x = 1;
    for( int i = 0; i < s.size(); i++ ){
        int h = s[i] - 'a';
        if( !t[x][h] )
            t[x][h] = ++sz;
        x = t[x][h];
    }
}

void dfs( int x )
{
    bool b = true;
    for( int i = 0; i < 26; i++ ){
        int to = t[x][i];
        if( !to )
            continue;
        b = false;
        dfs(to);
        win[x] |= !win[to];
        lose[x] |= !lose[to];
    }
    lose[x] |= b;
}

int main()
{
    cin >> n >> k;
    for( int i = 1; i <= n; i++ ){
        string s;
        cin >> s;
        add(s);
    }
    dfs(1);
    if( win[1] == false )
        cout << "Second" << endl;
    else if( lose[1] == true )
        cout << "First" << endl;
    else if( k % 2 == 1 )
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}