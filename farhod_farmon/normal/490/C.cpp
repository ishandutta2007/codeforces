#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000010;

using namespace std;

string s;
int l[N], r[N], a, b;

void ans(int x)
{
    cout << "YES" << endl;
    for(int i = 0; i <= x; i++)
        cout << s[i];
    cout << endl;
    for(int i = x + 1; i < s.size(); i++)
        cout << s[i];
    cout << endl;
    exit(0);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s >> a >> b;
    for(int i = 0; i < s.size(); i++){
        int x = s[i] - '0';
        int y = 0;
        if(i)
            y = l[i - 1];
        l[i] = (y * 10 + x) % a;
    }
    int pw10 = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        int x = s[i] - '0';
        int y = r[i + 1];
        r[i] = (y + x * pw10) % b;
        pw10 = (pw10 * 10) % b;
    }
    for(int i = 0; i + 1 < s.size(); i++)
        if(l[i] == 0 && r[i + 1] == 0 && s[0] != '0' && s[i + 1] != '0')
            ans(i);
    cout << "NO" << endl;
}