#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 303;

using namespace std;

int n, k;
map < string, bool > used;
vector < int > v;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if(used[s] == true)
            continue;
        used[s] = true;
        v.pb(s.size());
    }
    string s;
    cin >> s;
    sort(v.begin(), v.end());
    int last = s.size();
    int mn = -1, mx = -1, cur = 0;
    for(int i = 0; i < v.size(); i++){
        cur++;
        if(v[i] == last && mn == -1)
            mn = cur;
        if(v[i] == last)
            mx = cur;
        if(i % k == k - 1)
            cur += 5;
    }
    cout << mn << " " << mx << endl;
}