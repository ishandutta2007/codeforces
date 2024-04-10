#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 500500;

using namespace std;

int n;
int a[N], b[N], c[N];
map < int, vector < int > > d1, d2, d3, d4;

void add(int i)
{
    d1[a[i] + b[i]].pb(i);
    d2[a[i] - b[i]].pb(i);
    d3[a[i]].pb(i);
    d4[b[i]].pb(i);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("three.in");
    //fout("three.out");
    ios_base::sync_with_stdio(0);
    sc("%d\n%d %d\n", &n, &a[0], &b[0]);
    add(0);
    for(int i = 1; i <= n; i++){
        char f;
        sc("%c %d %d\n", &f, &a[i], &b[i]);
        if(f == 'B')
            c[i] = 1;
        else if(f == 'R')
            c[i] = 2;
        else
            c[i] = 3;
        add(i);
    }
    for(auto &f: d1){
        vector < pair < int, int > > v;
        for(int i = 0; i < f.se.size(); i++)
            v.pb({a[f.se[i]], f.se[i]});
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            if(i + 1 < v.size() && (c[v[i].se] == 1 || c[v[i].se] == 3) && c[v[i + 1].se] == 0){
                pr("YES\n");
                return 0;
            }
            if(i > 0 && (c[v[i].se] == 1  || c[v[i].se] == 3) && c[v[i - 1].se] == 0){
                pr("YES\n");
                return 0;
            }
        }
    }
    for(auto &f: d2){
        vector < pair < int, int > > v;
        for(int i = 0; i < f.se.size(); i++)
            v.pb({a[f.se[i]], f.se[i]});
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            if(i + 1 < v.size() && (c[v[i].se] == 1 || c[v[i].se] == 3) && c[v[i + 1].se] == 0){
                pr("YES\n");
                return 0;
            }
            if(i > 0 && (c[v[i].se] == 1  || c[v[i].se] == 3) && c[v[i - 1].se] == 0){
                pr("YES\n");
                return 0;
            }
        }
    }
    for(auto &f: d3){
        vector < pair < int, int > > v;
        for(int i = 0; i < f.se.size(); i++)
            v.pb({b[f.se[i]], f.se[i]});
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            if(i + 1 < v.size() && (c[v[i].se] == 2 || c[v[i].se] == 3) && c[v[i + 1].se] == 0){
                pr("YES\n");
                return 0;
            }
            if(i > 0 && (c[v[i].se] == 2  || c[v[i].se] == 3) && c[v[i - 1].se] == 0){
                pr("YES\n");
                return 0;
            }
        }
    }
    for(auto &f: d4){
        vector < pair < int, int > > v;
        for(int i = 0; i < f.se.size(); i++)
            v.pb({a[f.se[i]], f.se[i]});
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            if(i + 1 < v.size() && (c[v[i].se] == 2 || c[v[i].se] == 3) && c[v[i + 1].se] == 0){
                pr("YES\n");
                return 0;
            }
            if(i > 0 && (c[v[i].se] == 2  || c[v[i].se] == 3) && c[v[i - 1].se] == 0){
                pr("YES\n");
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}