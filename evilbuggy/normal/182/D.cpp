#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

int z[100005];

set<int> findPeriod(string &s){
    int n = s.size();
    z[0] = 0;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    set<int> tmp;
    for(int len = n; len >= 1; len--){
        if(n%len)continue;
        bool pos = true;
        for(int j = len; j < n; j += len){
            if(z[j] < len)pos = false;
        }
        if(pos)tmp.insert(len);
    }
    return tmp;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin>>s1>>s2;
    
    set<int> a1 = findPeriod(s1);
    set<int> a2 = findPeriod(s2);

    int max_len = 0;
    for(; max_len < min(s1.size(), s2.size()); max_len++){
        if(s1[max_len] != s2[max_len])break;
    }
    int cnt = 0;
    for(auto x : a1){
        if(x > max_len)break;
        if(a2.find(x) != a2.end())cnt++;
    }
    cout<<cnt<<endl;
}