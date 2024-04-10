#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int m, n;
int a[100000];
vector<int> v[200000];
vector<int> v1[200000];
bool used[200000];
bool used1[200000];


int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i < n - 1 && a[i + 1] != a[i]) {
            v[a[i]].push_back(a[i + 1]);
            v1[a[i]].push_back(a[i + 1]);
        }
        if (i > 0 && a[i - 1] != a[i]) {
            v1[a[i]].push_back(a[i - 1]);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (!used[a[i]]) {
            sort(v[a[i]].begin(), v[a[i]].end());
            for (int j = 0; j < (int)v[a[i]].size(); j++) {
                ans += abs(v[a[i]][j] - a[i]);
            }
          //  cout << a[i] << endl; 
            used[a[i]] = true;
        }
    }
   //cout << ans << endl;
    long long sum = ans;
    for (int i = 0; i < n; i++) {
        if (!used1[a[i]]) {
            sort(v1[a[i]].begin(), v1[a[i]].end());
            long long ans1 = sum;
            int g = (int)v1[a[i]].size() / 2;
            for (int j = 0; j < (int)v1[a[i]].size(); j++) {
                ans1 -= abs(v1[a[i]][j] - a[i]);
                ans1 += abs(v1[a[i]][j] - v1[a[i]][g]);
            }
            ans = min(ans, ans1);
            ans1 = sum;
            g = ((int)v1[a[i]].size() - 1) / 2;
            for (int j = 0; j < (int)v1[a[i]].size(); j++) {
                ans1 -= abs(v1[a[i]][j] - a[i]);
                ans1 += abs(v1[a[i]][j] - v1[a[i]][g]);
            }
            ans = min(ans, ans1);
            ans1 = sum;
            long long k = 0;
            for (int j = 0; j < (int)v1[a[i]].size(); j++) {
                ans1 -= abs(v1[a[i]][j] - a[i]);
                k += v1[a[i]][j];
            }
            for (int j = 0; j < (int)v1[a[i]].size(); j++) {
                ans1 += abs(v1[a[i]][j] - (k / (long long)v1[a[i]].size()));
            }
            ans = min(ans, ans1);

     //       cout << ans1 << endl;
            used1[a[i]] = true;
        }
    }
    cout << ans << endl;
    return 0;
}