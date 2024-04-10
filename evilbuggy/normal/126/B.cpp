#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

int z[1000005], f[1000005];

void zz(string s) {
    int n = s.size();
    z[0] = 0;
    for (int i = 1, l = 0, r = 0; i < n-1; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n-1 && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

void kmp(string s){
    int n = s.size();
    int i = 1, j = 0;
    f[0] = 0;
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

    string s;
    cin>>s;
    int n = s.size();
    zz(s);
    kmp(s);
    vector<int> pos_lens;
    int len = f[n-1];
    while(len != 0){
        pos_lens.push_back(len);
        len = f[len - 1];
    }
    int ind = -1;
    for(int i = 1; i < n-1; i++){
        if(z[i] > z[ind])ind = i;
    }
    if(ind == -1){
        cout<<"Just a legend"<<endl;
        return 0;
    }
    for(auto x : pos_lens){
        if(x <= z[ind]){
            cout<<s.substr(ind, x)<<endl;
            return 0;
        }
    }
    cout<<"Just a legend"<<endl;
}