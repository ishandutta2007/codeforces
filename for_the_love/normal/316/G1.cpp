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

string s, t[15];
int l[15], r[15], n;
map <string, int> S;

int find(int l, int r, int k){
    int ret = 0;
    for (int i = 0; i < (int)t[k].size() - (r - l + 1) + 1; i++){
        int found = 1;
        for (int j = i; j <= i + r - l; j++)
        if (s[l + j - i] != t[k][j]){
            found = 0; break;
        }
        ret += found;
    }
    return ret;
}

int main(){
    cin >> s;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> l[i] >> r[i];
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    for (int j = i; j < s.size(); j++){
        string ss = "";
        for (int k = i; k <= j; k++) ss += s[k];
        if (S[ss]) continue;
        S[ss] = 1;
        int found = 1;
        for (int k = 1; k <= n; k++){
            int tmp = find(i, j, k);
            if (tmp > r[k] || tmp < l[k]){
                found = 0;
                break;
            }
        }
        ans += found;
    }
    printf("%d\n", ans);

}