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

vector < int > add(vector < int > v, int id, int x)
{
    vector < int > nv;
    for(int i = 0; i < id; i++)
        nv.pb(v[i]);
    nv.pb(x);
    for(int i = id; i < v.size(); i++)
        nv.pb(v[i]);
    return nv;
}

vector < int > del(vector < int > v, int l, int r)
{
    vector < int > nv;
    for(int i = 0; i < l; i++)
        nv.pb(v[i]);
    for(int i = r + 1; i < v.size(); i++)
        nv.pb(v[i]);
    return nv;
}

int f(vector < int > v)
{
    vector < int > g;
    int score = 0;
    for(int i = 0; i < v.size(); i++){
        g.pb(v[i]);
        int l = g.size();
        if(l < 3 || i + 1 < v.size() && v[i] == v[i + 1])
            continue;
        if(g[l - 1] == g[l - 2] && g[l - 1] == g[l - 3]){
            int x = g[l - 1];
            while(g.size() > 0 && g.back() == x){
                g.pop_back();
                score++;
            }
        }
    }
    return score;
}

int n, k, c;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    vector < int > v;
    cin >> n >> k >> c;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        v.pb(x);
    }
    int score = 0;
    for(int i = 0; i <= n; i++){
        score = max(score, f(add(v, i, c)));
    }
    cout << max(score - 1, 0) << endl;
}