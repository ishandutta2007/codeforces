#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string p[100005];

void compute(string &s, vector<ll> &mf, int &st, int &en){
    vector<pair<char, ll> > arr;
    for(auto ch : s){
        if(arr.empty() || arr.back().first != ch)arr.push_back({ch, 1});
        else arr.back().second++;
    }
    mf = vector<ll>(26, 0);
    for(auto x : arr){
        mf[x.first - 'a'] = max(mf[x.first - 'a'], x.second);
    }
    st = arr.front().second;
    en = arr.back().second;
}

bool check(string &s){
    char nch = s[0];
    for(auto ch : s){
        if(ch != nch)return false;
    }
    return true;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>p[i];
    }

    vector<ll> mf, nmf;
    int st, en;
    compute(p[1], mf, st, en);
    for(int i = 2; i <= n; i++){
        // for(int i = 0; i < 26; i++){
        //     cout<<mf[i]<<" "<<char('a' + i)<<endl;
        // }
        // cout<<endl;
        nmf = vector<ll>(26, 0);
        if(check(p[i])){
            for(int j = 0; j < 26; j++){
                nmf[j] = (mf[j] > 0);
            }
            int ch = p[i][0] - 'a';
            int sz = p[i].size();
            nmf[ch] = (mf[ch] + 1)*sz + mf[ch];
        }else{
            nmf.clear();
            compute(p[i], nmf, st, en);
            for(int j = 0; j < 26; j++){
                if(mf[j] > 0)nmf[j] = max(nmf[j], 1LL);
            }
            if(p[i][0] == p[i].back()){
                int ch = p[i][0] - 'a';
                if(mf[ch] > 0)nmf[ch] = max(nmf[ch], en + st + 1LL);
            }else{
                int ch = p[i][0] - 'a';
                if(mf[ch] > 0)nmf[ch] = max(nmf[ch], st + 1LL);
                ch = p[i].back() - 'a';
                if(mf[ch] > 0)nmf[ch] = max(nmf[ch], en + 1LL);
            }
        }
        mf = nmf;
    }
    ll ans = mf[0];
    for(int i = 0; i < 26; i++){
        ans = max(ans, mf[i]);
        // cout<<mf[i]<<" "<<char('a' + i)<<endl;
    }
    cout<<ans<<endl;
}