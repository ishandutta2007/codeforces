#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int n, cnt[255];
string s;
bool check(int l){
    int nn = n, t;
    for (char ch = 'a'; ch <= 'z'; ch++){
        if (cnt[ch] % l == 0) t = cnt[ch] / l; else t = cnt[ch] / l + 1;
        nn -= t;
        if (nn < 0) return 0;
    }
    return 1;
}

string calc(int l){
    string ret = ""; int t;
    for (char ch = 'a'; ch <= 'z'; ch++){
        if (cnt[ch] % l == 0) t = cnt[ch] / l; else t = cnt[ch] / l + 1;
        n -= t;
        while (t--) ret += ch;
    }
    while (n--) ret += 'a';
    return ret;
}
int main(){
    cin >> s;
    for (int i = 0; i < s.size(); i++) cnt[s[i]]++;
    cin >> n;
    int l = 1, r = 1000, ans = - 1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    printf("%d\n", ans);
    if (ans != -1) cout << calc(ans) << endl;
}