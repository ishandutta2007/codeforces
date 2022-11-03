
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; string s;
    while(cin >> n >> s) {
        vector<int> cnt(26 * 2 + 10, 0);
        auto idx = [](char c) { return islower(c) ? c - 'a' : isupper(c) ? 26 + c - 'A' : 52 + c - '0'; };
        auto toChar = [](int x) ->char { return x < 26 ? 'a' + x : x < 52 ? x - 26 + 'A' : x - 52 + '0'; };
        for(char c : s) cnt[idx(c)]++;

        // for(int i = 0; i < 62; ++i) cout << i << ' ' << cnt[i] << endl;

        int odd = 0;
        vector<int> odds;
        for(int i = 0; i < 62; ++i) {
            odd += cnt[i] & 1;
            if(cnt[i] & 1) {
                --cnt[i];
                odds.emplace_back(i);
            }
        }

        bool ok = false;
        for(int i = 1; i <= n; ++i) {
            if(n % i) continue;
            int len = n / i;
            int half = len / 2;
            if(len & 1) {
                if(odd > i) continue;
                else {
                    cout << i << endl;
                    vector<int> todds = odds;
                    for(int j = 0; j < 62; ++j) {
                        while(cnt[j] && todds.size() < i) {
                            --cnt[j];
                            todds.emplace_back(j);
                        }
                    }
                    // for(auto i : todds) cout << i << endl;
                    int k = 0;
                    for(int j = 1; j <= i; ++j) {
                        string one; 
                        char t = toChar(todds.back());
                        todds.pop_back();
                        while(one.size() < half) {
                            while(k < 62 && !cnt[k]) ++k;
                            int go = min<int>(half - one.size(), cnt[k] / 2);
                            // cout << k << ' ' << go << endl;
                            one += string(go, toChar(k));
                            cnt[k] -= go * 2;
                        }
                        cout << one << t;
                        reverse(one.begin(), one.end());
                        cout << one << (" \n"[j == i]);
                    }
                    ok = true;
                }
            }
            else {
                if(odd) continue;
                else {
                    cout << i << endl;
                    int k = 0;
                    for(int j = 1; j <= i; ++j) {
                        string one; 
                        while(one.size() < half) {
                            while(k < 62 && !cnt[k]) ++k;
                            int go = min<int>(half - one.size(), cnt[k] / 2);
                            one += string(go, toChar(k));
                            cnt[k] -= go * 2;
                        }
                        cout << one;
                        reverse(one.begin(), one.end());
                        cout << one << (" \n"[j == i]);
                    }
                    ok = true;
                }
            }
            if(ok) break;
        }
        assert(ok);
    }
    return 0;
}