#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double



int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    set<int> se;
    for (int i = 0; i < n; i++){
        int sz;
        cin >> sz;
        set<int> kek;
        while(sz--){
            int x;
            cin >> x;
            kek.insert(x);
        }
        if (i == 0) se = kek;
        else {
            set<int> da;
            for (int x : kek) if (se.find(x) != se.end()) da.insert(x);
            se = da;
        }
    }
    for (int x : se) cout << x << ' ';
}