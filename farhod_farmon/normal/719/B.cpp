#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

char R[200];

int solve(string s, char c)
{
    int cnt = 0;
    int a = 0, b = 0;
    for(int i = 0; i < s.size(); i++, c = R[c]){
        if(s[i] == c)
            continue;
        if(s[i] == 'r')
            a++;
        else
            b++;
    }
    return max(a, b);
}

int n;
string s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    R['b'] = 'r';
    R['r'] = 'b';
    string t = s;
    cout << min(solve(s, 'b'), solve(t, 'r')) << endl;
}