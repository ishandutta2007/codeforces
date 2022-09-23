#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll long long

const int N = 100100;
const long long mod = 1e15 + 3;

using namespace std;

int l[N];
int r[N];
string s;
string t;
vector < int > v[26];

int gete(int g, int x)
{
    if(v[g].empty() || v[g].back() <= x)
        return -1;
    int l = 0,
        r = v[g].size() - 1;
    while(l < r){
        int m = (l + r) / 2;
        if(v[g][m] <= x)
            l = m + 1;
        else
            r = m;
    }
    return v[g][l];
}

int getb(int g, int x)
{
    if(v[g].empty() || v[g][0] >= x)
        return -1;
    int l = 0,
        r = v[g].size() - 1;
    while(l < r){
        int m = (l + r) / 2 + 1;
        if(v[g][m] < x)
            l = m;
        else
            r = m - 1;
    }
    return v[g][l];
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++)
        v[s[i] - 'a'].pb(i);
    l[0] = gete(t[0] - 'a', -1);
    for(int i = 1; i < t.size(); i++){
        if(l[i - 1] == -1)
            l[i] = -1;
        else
            l[i] = gete(t[i] - 'a', l[i - 1]);
    }
    r[t.size() - 1] = getb(t[t.size() - 1] - 'a', 1e6);
    for(int i = t.size() - 2; i >= 0; i--){
        if(r[i + 1] == -1)
            r[i] = -1;
        else
            r[i] = getb(t[i] - 'a', r[i + 1]);
    }
    if(r[0] != -1){
        cout << t << endl;
        return 0;
    }
    int ii = 0,
        ij = t.size() - 1;
    for(int i = 0; i < t.size(); i++){
        if(i && l[i - 1] == -1)
            break;
        int tl = i,
            tr = t.size() - 1;
        while(tl < tr){
            int m = (tl + tr) / 2;
            if((m + 1 == t.size() ? 1e6 : r[m + 1]) > (!i ? -1: l[i - 1]))
                tr = m;
            else
                tl = m + 1;
        }
        if(t.size() - tl + i - 1 >= t.size() - ij + ii - 1){
            ii = i;
            ij = tl;
        }
    }
    if(ii == 0 && ij == t.size() - 1){
        cout << "-" << endl;
        return 0;
    }
    for(int i = 0; i < ii; i++)
        cout << t[i];
    for(int i = ij + 1; i < t.size(); i++)
        cout << t[i];
}