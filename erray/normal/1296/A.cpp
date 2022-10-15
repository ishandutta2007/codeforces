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
#define N 100005
using namespace std;       
ll t, n, x;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--){
        cin >> n;
        ll sum = 0, arr[2] = {0 ,0};
        while (n--){
            cin >> x;
            sum += x;
            arr[x % 2]++;
        }
        if (sum % 2 == 1 || (arr[1] > 0 && arr[0] > 0)){
            cout << "YES" << ln;
        }
        else {
            cout << "NO" << ln;
        }
        
    }
    return 0;
}