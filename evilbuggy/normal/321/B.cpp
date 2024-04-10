#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int compute(vector<int> &a, vector<int> &b, bool flg){
    if(flg){
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        int ans = 0;
        while(j < m){
            if(i == n || b[j] < a[i])ans += b[j];
            else{
                ans += b[j] - a[i];
                i++;
            }
            j++;
        }
        if(i != n)return 0;
        return ans;
    }else{
        int i, n = a.size(), m = b.size();
        int suma = 0, sumb = 0;
        for(i = 0; i < min(n, m); i++){
            if(a[i] > b[m-1-i])break;
            suma += a[i];
            sumb += b[m-1-i];
        }
        return sumb - suma;
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

    int n, m;
    cin>>n>>m;
    vector<int> atk, def, ciel;
    for(int i = 0; i < n; i++){
        string s;
        int val;
        cin>>s>>val;
        if(s[0] == 'A')atk.push_back(val);
        else def.push_back(val);
    }
    for(int i = 0; i < m; i++){
        int val;
        cin>>val;
        ciel.push_back(val);
    }
    sort(atk.begin(), atk.end());
    sort(def.begin(), def.end());
    sort(ciel.begin(), ciel.end());
    int ans = compute(atk, ciel, false);
    for(int i = 0; i < def.size(); i++){
        int ind = upper_bound(ciel.begin(), ciel.end(), def[i]) - ciel.begin();
        if(ind == m-i){
            cout<<ans<<endl;
            return 0;
        }
        ciel.erase(ciel.begin() + ind);
    }
    // cout<<compute(atk, ciel, true)<<endl;
    ans = max(ans, compute(atk, ciel, true));
    cout<<ans<<endl;
}