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

string s;
string t;
string ans;

void f(int i, int x, int y, bool g)
{
    if(x > s.size() / 2 || y > s.size() / 2)
        return;
    if(i == s.size()){
        ans = t;
        return;
    }
    if(g){
        t[i] = '4';
        f(i + 1, x + 1, y, 1);
        if(ans != "")
            return;
        t[i] = '7';
        f(i + 1, x, y + 1, 1);
    }
    else{
        if('4' >= s[i]){
            t[i] = '4';
            f(i + 1, x + 1, y, '4' > s[i]);
            if(ans != "")
                return;
        }
        if('7' >= s[i]){
            t[i] = '7';
            f(i + 1, x, y + 1, '7' > s[i]);
        }
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    for(int i = 0; i < s.size() / 2; i++)
        t += '7';
    for(int i = 0; i < s.size() / 2; i++)
        t += '4';
    if(s.size() % 2 || s > t){
        t = "";
        for(int i = 0; i < s.size() / 2 + 1; i++)
            t += '4';
        for(int i = 0; i < s.size() / 2 + 1; i++)
            t += '7';
        cout << t << endl;
        return 0;
    }
    t = s;
    f(0, 0, 0, 0);
    cout << ans << endl;
}