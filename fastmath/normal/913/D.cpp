#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <random>
#include <time.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
#define int long long

const int MAXN = 2e5 + 7;

struct Elem{
    int num, cost, want;
};

int n, t;
vector <Elem> a;

bool comp(Elem a, Elem b){
    return a.cost < b.cost;
}

bool check(int m){
    int have = t;
    int get = 0;
    for (int i = 0; i < n; ++i){
        if (m <= a[i].want && a[i].cost <= have){
            ++get;
            have -= a[i].cost;
        }
    }
    return m <= get;
}

signed main(){  
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    a.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i].want >> a[i].cost;
        a[i].num = i + 1;
    }

    sort(a.begin(), a.end(), comp);

    int l = 0;
    int r = n + 1;
    vector <int> ans;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (check(m)){
            l = m;
        }
        else{
            r = m;
        }
    }

    cout << l << '\n' << l << '\n';
    int have = t;
    int get = 0;
    for (int i = 0; i < n; ++i){
        if (get == l) break;
        if (l <= a[i].want && a[i].cost <= have){
            cout << a[i].num << ' ';
            ++get;
            have -= a[i].cost;    
        }
    }
    cout << '\n';

    return 0;
}