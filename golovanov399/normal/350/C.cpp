#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>

#define float long double
#define LL long long

using namespace std;

int abss(int x){
    if (x < 0) return -x; else return x;
}

bool cmp(pair<int, int> x, pair<int, int> y){
    return ((abss(x.first) + abss(x.second)) < (abss(y.first) + abss(y.second)));
}

int main(){

//  freopen("courier.in", "r", stdin);
//  freopen("courier.out", "w", stdout);

    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    
    sort(a, a + n, &cmp);
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (a[i].first != 0) ans += 2;
        if (a[i].second != 0) ans += 2;
        ans += 2;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++){
        if (a[i].first > 0){
            cout << "1 " << a[i].first << " R\n";
        } else
        if (a[i].first < 0){
            cout << "1 " << -a[i].first << " L\n";
        }
        if (a[i].second > 0){
            cout << "1 " << a[i].second << " U\n";
        } else
        if (a[i].second < 0){
            cout << "1 " << -a[i].second << " D\n";
        }
        cout << "2\n";
        if (a[i].second < 0){
            cout << "1 " << -a[i].second << " U\n";
        } else
        if (a[i].second > 0){
            cout << "1 " << a[i].second << " D\n";
        }
        if (a[i].first < 0){
            cout << "1 " << -a[i].first << " R\n";
        } else
        if (a[i].first > 0){
            cout << "1 " << a[i].first << " L\n";
        }
        cout << "3\n";
    }
    
    return 0;

}