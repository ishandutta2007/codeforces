#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define x first
#define y second

using namespace std;

int pref[1111111];
int cock[1111111];
bool b[1111111];

int stupid(const vector<int>& a){
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            ans = max(ans, max(a[i], a[j]) % min(a[i], a[j]));
        }
    }
    return ans;
}

int solve(const vector<int>& a){
    int n = a.size();
    int maxN = 1111111;
    if (a[0] == a[n - 1]){
        return 0;
    }
    // vector<int> pref(maxN);
    // vector<bool> b(maxN, false);
    for (int i = 0; i < n; i++) b[a[i]] = true;
    int maxMaxMax = -1;
    pref[0] = maxMaxMax;
    for (int i = 1; i < maxN; i++){
        if (b[i]) pref[i] = i; else
        pref[i] = pref[i - 1];
    }
    int ans = 0;
    // vector<int> cock(maxN, 0);
    for (int i = 1; i < maxN; i++){
        if (b[i]){
            for (int j = i; j < maxN; j += i){
                cock[j] = max(cock[j], i);
            }
        }
    }
    for (int i = 0; i < maxN; i++){
        if (cock[i]){
            ans = max(ans, pref[min(i + cock[i] - 1, maxN - 1)] - i);
        }
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    cout << solve(a) << "\n";

    // while (1){
    //  int n = rand() % 10 + 2;
    //  vector<int> a(n);
    //  for (int i = 0; i < n; i++) a[i] = rand() % 1000000 + 2;
    //  sort(all(a));
    //  int ans1 = stupid(a), ans2 = solve(a);
    //  if (ans1 != ans2){
    //      cout << n << "\n";
    //      for (int i = 0; i < n; i++) cout << a[i] << " ";
    //          cout << "\n";
    //      return 0;
    //  }
    // }

    return 0;
}