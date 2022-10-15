#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define umap unordered_map
#define flush fflush(stdout)
#define For(ii,aa,bb) for(int ii = aa; ii < bb; ii++) 
#define st first
#define nd second 
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ln "\n"
#define all(v) v.begin(),v.end()
#define MAX 1000000009
#define MOD 998244353
#define mid (start + end) / 2 
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 500005
using namespace std;
typedef pair<ll,ll> pp;
typedef pair<pp,pp> pp4; 
typedef vector<ll> vi; 
ll n, t, x, a, b, k , c ,y, p, c1, c2;
pp val[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("outt.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    priority_queue <ll> pq;
    for(int i = 0; i < t; i++)cin >> val[i].st;
    for(int i = 0; i < t; i++)cin >> val[i].nd;
    ll ans = 0, sum = 0;
    sort(val, val + t);
    for(int i = 0;i < t;i++){
        //cout << val[i].st << " " << val[i].nd << ln;
        pq.push(val[i].nd);
        sum += val[i].nd;
        ll now = val[i].st;
        while(!pq.empty() && now < val[i + 1].st){
            sum -= pq.top();
            ans += sum;
            pq.pop();
            now++;
        }
    }
    while(!pq.empty()){
            sum -= pq.top();  
            ans += sum;  
            pq.pop();
    }
        cout << ans << ln;

    
    return 0;
}