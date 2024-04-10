#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

pair<int, int> a[1000005];
string arr[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n;
    cin>>n;
    int m = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        int l, k; cin>>k;
        while(k--){
            cin>>l; m++;
            a[m] = {l - 1, i};
        }
    }
    sort(a + 1, a + m + 1);
    int r = 0;
    string s = "";
    for(int i = 1; i <= m; i++){
        while(r < a[i].first){
            s += 'a';
            r++;
        }
        int sz = arr[a[i].second].size();
        if(r < a[i].first){
            s += arr[a[i].second];
            r = s.size();
        }
        while(r - a[i].first < sz){
            s += arr[a[i].second][r - a[i].first];
            r++;
        }
    }
    cout<<s<<endl;
}