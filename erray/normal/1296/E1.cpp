#include <bits/stdc++.h>
typedef long long  ll;
typedef unsigned long long int ull;
#define st first 
#define nd second 
#define pb push_back
#define mp make_pair 
#define MAX 1000000009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define IT iterator 
#define ln "\n"
#define mid (start + end)/2
#define R(ii) (ii * 2) + 1
#define L(ii) (ii * 2)
#define pp pair<ll,ll> 
#define vi vector<ll> 
#define all(vv) vv.begin(),vv.end()
#define N 205
using namespace std;       
ll n;
string s;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> s;
    ll sorted = 0, as = 0;
    vector <ll> ans; 
    for(int i = 0; i < s.size(); i++){
        if (s[i] >= sorted){
            sorted = s[i];
            ans.pb(0);
        }
        else if(as <= s[i]){
            as = s[i];
            ans.pb(1);
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for(auto i : ans){
        cout << i;
    }
    return 0;
}