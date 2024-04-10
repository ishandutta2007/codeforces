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

using namespace std;

string s, t;
int d[10], cnt;

bool can( int x )
{
    int f[10] = {0};
    bool b = true;
    int y = x, l = 0;
    while( y ){
        f[y % 10]++;
        y /= 10;
        l++;
    }
    for( int i = 0; i < 10; i++ )
        if( f[i] > d[i] )
            b = false;
    if( s.size() - l != x )
        b = false;
    if( b )
        for( int i = 0; i < 10; i++ )
            d[i] -= f[i];
    return b;
}

int main()
{
    cin >> s >> t;
    bool b = true;
    for( int i = 0; i < s.size(); i++ ){
        s[i] -= '0';
        if( s[i] )
            b = false;
        d[s[i]]++;
    }
    for( int i = 0; i < t.size(); i++ ){
        t[i] -= '0';
        d[t[i]]--;
    }
    if( b ){
        cout << 0 << endl;
        return 0;
    }
    int cnt = 1;
    while( !can(cnt) )
        cnt++;
    string ans = "";
    int first = -1;
    for( int i = 1; i < 10; i++ ){
        if( d[i] ){
            first = i;
            break;
        }
    }
    if( first == -1 ){
        for( int i = 0; i < t.size(); i++ )
            t[i] += '0';
        ans = t;
        for( int i = 0; i < d[0]; i++ )
            ans += '0';
        cout << ans << endl;
    }
    else{
        ans += char(first + '0');
        d[first]--;
        for( int i = 0; i < 10; i++ )
            for( int j = 0; j < d[i]; j++ )
                ans += char(i + '0');
        d[first]++;
        for( int i = 0; i < t.size(); i++ )
            t[i] += '0';
        string ans1 = ans + t;
        if( t[0] != '0' ){
            string heh = t;
            for( int i = 0; i < 10; i++ )
                for( int j = 0; j < d[i]; j++ )
                    heh += char(i + '0');
            ans1 = min(ans1, heh);
        }
        for( int i = 0; i < ans.size(); i++ ){
            if( i && ans[i] == ans[i - 1] )
                continue;
            if( !i && t[0] == '0' )
                continue;
            string heh = "";
            for( int j = 0; j < i; j++ )
                heh += ans[j];
            heh += t;
            for( int j = i; j < ans.size(); j++ )
                heh += ans[j];
            ans1 = min(ans1, heh);
        }
        d[first]--;
        string heh = "";
        heh += char(first + '0');
        heh += t;
        for( int i = 0; i < 10; i++ )
            for( int j = 0; j < d[i]; j++ )
                heh += char(i + '0');
        ans1 = min(ans1, heh);
        cout << ans1 << endl;
    }
}