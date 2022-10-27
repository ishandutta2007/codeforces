#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 1000000007;

vector<int> search(string &s, string &t){
    int n = s.size();
    int m = t.size();
    vector<int> f(m);
    f[0] = 0;
    int i = 1, j = 0;
    while(i < m){
        if(t[i] == t[j]){
            f[i] = j+1;
            i++; j++;
        }else if(j == 0){
            f[i] = 0;
            i++;
        }else{
            j = f[j-1];
        }
    }
    vector<int> ret;
    i = 0, j = 0;
    while(i < n){
        if(j == m){
            ret.push_back(i - 1);
            j = f[j-1];
        }else if(s[i] == t[j]){
            i++; j++;
        }else if(j == 0){
            i++;
        }else{
            j = f[j-1];
        }
    }
    if(j == m){
        ret.push_back(n - 1);
    }
    return ret;
}

ll dp[100005], sdp[100005], ssdp[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;
    cin>>s>>t;
    vector<int> arr = search(s, t);
    int n = s.size(), m = t.size();

    for(int i = 0; i < n; i++){
        int ind = lower_bound(arr.begin(), arr.end(), i + 1) - arr.begin() - 1;
        if(ind < 0){
            dp[i] = 0;
        }else if(arr[ind] == m-1){
            dp[i] = 1;
        }else{
            dp[i] = (ssdp[arr[ind] - m] + arr[ind] - m + 2) % mod;
        }
        sdp[i] = (i == 0)?dp[0]:(sdp[i-1] + dp[i]) % mod;
        ssdp[i] = (i == 0)?sdp[0]:(ssdp[i-1] + sdp[i]) % mod;
    }
    cout<<sdp[n-1]<<endl;
}