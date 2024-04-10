#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr prlong longf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 5050;

using namespace std;

vector < vector < int > > solve(string s, string t)
{
    vector < vector < int > > v;
    v.resize(s.size() + 1);
    for(int i = 0; i <= s.size(); i++){
        v[i].resize(t.size() + 1);
        for(int j = 0; j <= t.size(); j++)
            v[i][j] = 0;
    }
    for(int i = s.size() - 1; i >= 0; i--){
        for(int j = t.size() - 1; j >= 0; j--){
            if(s[i] == t[j])
                v[i][j] = v[i + 1][j + 1] + 1;
        }
    }
    return v;
}

string s, t;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s >> t;
    vector < vector < int > > vs = solve(s, s),
                              vt = solve(t, t),
                              v = solve(s, t);
    for(int i = 0; i < s.size(); i++){
        vs[i][i] = 0;
        for(int j = 0; j < s.size(); j++)
            if(i != j)
                vs[i][0] = max(vs[i][0], vs[i][j]);
    }
    for(int i = 0; i < t.size(); i++){
        vt[i][i] = 0;
        for(int j = 0; j < t.size(); j++)
            if(i != j)
                vt[i][0] = max(vt[i][0], vt[i][j]);
    }
    int cnt = N;
    for(int i = 0; i < s.size(); i++)
        for(int j = 0; j < t.size(); j++)
            if(v[i][j] > max(vs[i][0], vt[j][0]))
                cnt = min(cnt, max(vs[i][0], vt[j][0]));
    if(cnt == N)
        cnt = -2;
    cout << cnt + 1 << endl;
    return 0;
}