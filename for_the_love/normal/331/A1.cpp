#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
map <long long, long long> S;
vector <int> v[300005];
long long a[300005], s[300005], n, t, cnt;
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] < 0) s[i] = s[i - 1]; else s[i] = s[i - 1] + a[i];
    }
    long long ans = -1e16;
    long long l, r;
    for (int i = 1; i <= n; i++){
        if (!S[a[i]]) S[a[i]] = ++cnt;
        t = S[a[i]];
        if (v[t].size()){
            for (int j = 0; j < v[t].size(); j++)
            if (ans < s[i - 1] - s[v[t][j]] + a[i] * 2){
                ans = s[i - 1] - s[v[t][j]] + a[i] * 2;
                l = v[t][j];
                r = i;
            }
        }
        v[t].push_back(i);
    }
    int ansk = l - 1 + n - r;
    for (int i = l + 1; i < r; i++)
    if (a[i] < 0) ansk++;

    cout << ans << " " << ansk << endl;
    for (int i = 1; i < l; i++) cout << i << " ";
    for (int i = l + 1; i < r; i++)
    if (a[i] < 0) cout << i << " ";
    for (int i = r + 1; i <= n; i++) cout << i << " ";

}