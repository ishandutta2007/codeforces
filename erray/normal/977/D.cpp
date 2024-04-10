#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define flush fflush(stdout)
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln '\n'
#define MAX 1000000009
#define N 505
using namespace std;
typedef long long ll;
typedef pair<int ,int > pii;
int t;
ll x;
vector <ll> v; 
bool cmp(ll a, ll b){
    ll ta = a, tb = b;
    int ct1 = 0, ct2 = 0;
    while(ta % 3 == 0){
        ta /= 3;
        ct1++;
    }
    while(tb % 3 == 0){
        tb /= 3;
        ct2++;
    }
    if(ct2 > ct1){
        return 0;
    }
    else if(ct1 > ct2){
        return 1;
    }
    else {
        return a < b;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 
    cin >> t;
    while(t--){
        cin >> x;
        v.pb(x);
    }
    sort(all(v), cmp);
    for(auto a : v){
        cout << a << " ";
    }
}