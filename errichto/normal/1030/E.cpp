// 1) sum is even
// 2) max <= rest <===> 2*max <= sum

#include <bits/stdc++.h>
using namespace std;

const int MAGIC = 70;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        a[i] = __builtin_popcountll(x);
    }
    //~ for(int x : a) {
        //~ cout << x << "" ;
    //~ }
    long long answer = 0;
    
    // 2, 3, 1, 1, 2, 4, 2, 6, 3, 6, 7
    
    // count all intervals where sum is even
    vector<int> pref(n);
    for(int i = 0; i < n; ++i) {
        pref[i] = a[i];
        if(i != 0) {
            pref[i] += pref[i-1];
        }
    }
    int even = 0, odd = 0;
    for(int i = 0; i < n; ++i) {
        if(pref[i] % 2) {
            ++odd;
        }
        else {
            ++even;
        }
    }
    ++even; // empty prefix
    
    auto f = [&](int x) {
        return (long long) x * (x - 1) / 2;
    };
    
    answer = f(even) + f(odd);
    
    //~ for(int x : {even, odd}) {
        //~ answer += (long long) x * (x - 1) / 2;
    //~ }
    
    // subtract those where sum is even,
    // but not(2*max<=sum)
    for(int L = 0; L < n; ++L) {
        int sum = 0;
        int big = 0;
        for(int R = L; R < min(n, L + MAGIC); ++R) {
            sum += a[R];
            big = max(big, a[R]);
            if(sum % 2 == 0 && 2*big > sum) {
                --answer;
            }
        }
    }
    
    
    
    
    cout << answer << "\n";
}