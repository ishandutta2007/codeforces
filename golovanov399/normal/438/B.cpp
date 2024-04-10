#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <algorithm> 
#include <cassert> 
#include <string> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <map> 
#include <set> 
#include <iomanip>

#define itn int 
#define float long double 
#define LL long long 
#define pb push_back 
#define mp make_pair 

using namespace std; 

int main(){ 
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int> > > a;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a.pb(mp(min(v[x], v[y]), mp(x, y)));
    }
    sort(a.begin(), a.end());
//  for (int i = 0; i < a.size(); i++) cout << a[i].first << " " << a[i].second.first << " " << a[i].second.second << "\n";
    vector<vector<int> > lst(n);
    for (int i = 0; i < n; i++) lst[i].pb(i);
    vector<int> clr(n);
    for (int i = 0; i < n; i++) clr[i] = i;
    int i = a.size() - 1;
    long long w = 0, s = 0;
    while (i >= 0){
        int j = i - 1;
        while (j >= 0 && a[j].first == a[j + 1].first) j--;
        while (i > j){
            int x = a[i].second.first, y = a[i].second.second;
            if (clr[x] != clr[y]){
                x = clr[x];
                y = clr[y];
                w = w + 2ll * lst[x].size() * lst[y].size();
                if (lst[x].size() < lst[y].size()){
                    for (int _ = 0; _ < lst[x].size(); _++){
                        lst[y].pb(lst[x][_]);
                        clr[lst[x][_]] = y;
                    }
                    lst[x].erase(lst[x].begin(), lst[x].end());
                } else {
                    swap(x, y);
                    for (int _ = 0; _ < lst[x].size(); _++){
                        lst[y].pb(lst[x][_]);
                        clr[lst[x][_]] = y;
                    }
                    lst[x].erase(lst[x].begin(), lst[x].end()); 
                }
            }
            i--;
        }
        if (i < 0) s += w * a[i + 1].first; else s += w * (a[i + 1].first - a[i].first);
//      cout << w << " " << s << "\n";
    }
    cout << setprecision(10) << fixed;
    cout << (double)s / n / (n - 1) << "\n";
    
    return 0; 
}