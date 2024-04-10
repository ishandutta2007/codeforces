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

using namespace std;

set < pair < int, int > > s;
map < int, int > used;
vector < pair < string, int > > v;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string t;
        int x;
        cin >> t;
        if(t == "removeMin"){
            if(s.empty())
                v.pb({"insert", 1});
            else
                s.erase(s.begin());
            v.pb({t, -1});
        }
        else if(t == "insert"){
            cin >> x;
            s.insert({x, ++used[x]});
            v.pb({t, x});
        }
        else{
            cin >> x;
            while(!s.empty() && s.begin()->fi < x){
                v.pb({"removeMin", -1});
                s.erase(s.begin());
            }
            if(s.begin()->fi != x || s.empty()){
                s.insert({x, ++used[x]});
                v.pb({"insert", x});
            }
            v.pb({t, x});
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].fi;
        if(v[i].fi != "removeMin")
            cout << " " << v[i].se;
        cout << endl;
    }
}