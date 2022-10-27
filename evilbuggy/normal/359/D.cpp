#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 300005;
const int lgn = 20;

int a[maxn], gcd[maxn][lgn];

int query(int l, int r){
    int len = r - l + 1;
    int ans = 0;
    for(int i = lgn - 1; i >= 0; i--){
        if((len>>i)&1){
            ans = __gcd(ans, gcd[l][i]);
            l += (1<<i);
        }
    }
    return ans;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    memset(a, 0, sizeof(a));
    memset(gcd, 0, sizeof(gcd));
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        gcd[i][0] = a[i];
    }
    for(int k = 1; k < lgn; k++){
        for(int i = 1; i <= n; i++){
            if(i + (1<<(k-1)) <= n)gcd[i][k] = __gcd(gcd[i][k-1], gcd[i + (1<<(k-1))][k-1]);
            else gcd[i][k] = gcd[i][k-1];
        }
    }

    set<pair<int,int> > arr;
    int l, r, left, right;
    for(int i = 1; i <= n; i++){
        l = i, r = n;
        while(l < r){
            int m = l + (r - l + 1)/2;
            if(query(i, m)%a[i] == 0){
                l = m;
            }else{
                r = m - 1;
            }
        }
        right = l;
        l = 1, r = i;
        while(l < r){
            int m = l + (r - l)/2;
            if(query(m, i)%a[i] == 0){
                r = m;
            }else{
                l = m + 1;
            }
        }
        left = l;
        // cout<<i<<" "<<right<<" "<<left<<endl;
        arr.insert({right - left, left});
    }
    vector<int> ans;
    int maxi = (*arr.rbegin()).first;
    for(auto x : arr){
        if(x.first == maxi)ans.push_back(x.second);
    }
    cout<<ans.size()<<" "<<maxi<<endl;
    for(auto x : ans){
        cout<<x<<" ";
    }
}