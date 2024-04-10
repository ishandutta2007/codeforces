#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 2000000;
const int MX = 300100;

using namespace std;

string s, t;
int k;
int n;
int d[N][26];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s >> t >> k;
    for(int i = 0; i < s.size(); i++){
        int cur = 0,
            p = 0;
        for(int j = i; j < s.size(); j++){
            if(t[s[j] - 'a'] == '0')
                p++;
            if(p > k)
                break;
            if(!d[cur][s[j] - 'a'])
                d[cur][s[j] - 'a'] = ++n;
            cur = d[cur][s[j] - 'a'];
        }
    }
    cout << n << endl;
}