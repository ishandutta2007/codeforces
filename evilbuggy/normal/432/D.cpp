#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int z[100005], f[100005];

void computeZ(string &s){
    int n = s.size();
    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        if(r < i){
            l = r = i;
            while(r < n && s[r] == s[r-l])r++;
            r--;
            z[i] = (r-l+1);
        }else{
            int k = i-l;
            if(i + z[k] - 1 < r){
                z[i] = z[k];
            }else{
                l = i;
                while(r < n && s[r] == s[r-l])r++;
                r--;
                z[i] = (r-l+1);
            }
        }
    }
}

void computeKMP(string &s){
    int n = s.size();
    f[0] = 0;
    int i = 1, j = 0;
    while(i < n){
        if(s[i] == s[j]){
            f[i] = j+1;
            i++; j++;
        }else if(j == 0){
            f[i] = 0;
            i++;
        }else{
            j = f[j-1];
        }
    }
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
    string s;
    cin>>s;
    n = s.size();
    computeZ(s);
    computeKMP(s);

    vector<int> poslen;
    int len = f[n-1];
    while(len != 0){
        poslen.push_back(len);
        len = f[len - 1];
    }
    reverse(poslen.begin(), poslen.end());
    vector<int> arr;
    for(int i = 1; i < n; i++){
        arr.push_back(z[i]);
    }
    sort(arr.begin(), arr.end());
    cout<<poslen.size() + 1<<endl;
    for(auto x : poslen){
        int ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        cout<<x<<" "<<n - ind<<endl;
    }
    cout<<n<<" "<<1<<endl;
}