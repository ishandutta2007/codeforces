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

#define itn int 
#define float long double 
#define LL long long 
#define pb push_back 
#define mp make_pair 

using namespace std; 

int main(){ 
    
    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<int> > a(n);
    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].pb(y);
        a[y].pb(x);
    }
    vector<int> clr(n, 0), d(n, 0);
    vector<int> st(1, 0);
    while (!st.empty()){
        int x = st.back();
        d[clr[x]]++;
        st.pop_back();
        for (int i = 0; i < a[x].size(); i++){
            if (a[x][i] != 0 && clr[a[x][i]] == 0){
                clr[a[x][i]] = clr[x] + 1;
                st.pb(a[x][i]);
            }
        }
    }
    sort(clr.begin(), clr.end());
    int i = n - 1;
    int j = n - 1;
    LL qw = 0;
    int s = 0;
    int ans = 0;
    while (i >= 1){
        while (j >= 1 && i - j + 1 <= k && qw + (clr[i] - clr[j]) <= p){
            qw += clr[i] - clr[j--];
            s++;
        }
        ans = max(ans, s);
        s -= d[clr[i]];
        i--;
        while (i >= 1 && clr[i] == clr[i + 1]) i--;
        qw -= s;
    }
    cout << ans << "\n";
    
    return 0; 
}