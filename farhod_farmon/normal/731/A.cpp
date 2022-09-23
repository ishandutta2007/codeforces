#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 0;

using namespace std;

string s;

int f(char x, char y)
{
    x -= 'a';
    y -= 'a';
    if(x > y)
        swap(x, y);
    return min(y - x, x + 26 - y);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    char cur = 'a';
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        cnt += f(cur, s[i]);
        cur = s[i];
    }
    cout << cnt << endl;
}