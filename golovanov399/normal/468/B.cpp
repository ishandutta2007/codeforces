#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int> > ar(n);
    for (int i = 0; i < n; i++){
        cin >> ar[i].first;
        ar[i].second = i;
    }
    sort(ar.begin(), ar.end());
    set<int> s;
    map<int, int> M;
    for (int i = 0; i < n; i++){
        s.insert(ar[i].x);
        M[ar[i].x] = ar[i].y;
    }
    vector<int> ans(n);
    int j = n - 1;
    int i = 0;
    int c = 0;
    if (a > b){
        swap(a, b);
        c = 1;
    }
    vector<bool> used(n, false);
    while (i <= j){
        if (used[ar[i].y]) i++; else {
            if (ar[j].x > b - ar[i].x){
                cout << "NO\n";
                return 0;
            } else
            if (ar[j].x == b - ar[i].x){
                ans[ar[i].y] = ans[ar[j].y] = 1 - c;
                used[ar[i].y] = used[ar[j].y] = true;
                do {
                    i++;
                } while (i < n && used[ar[i].y]);
                do {
                    j--;
                } while (j >= 0 && used[ar[j].y]);
            } else {
                if (s.find(a - ar[i].x) != s.end()){
                    int index = M[a - ar[i].x];
                    if (used[index]){
                        cout << "NO\n";
                        return 0;
                    }
                    ans[ar[i].y] = ans[index] = c;
                    used[ar[i].y] = used[index] = true;
                    do {
                        i++;
                    } while (i < n && used[ar[i].y]);
                    while (j >= 0 && used[ar[j].y]) j--;
                } else {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}