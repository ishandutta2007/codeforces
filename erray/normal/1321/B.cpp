#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln "\n"
#define MAX 1000000009
#define MOD 1000000007
#define N 200005
using namespace std;
typedef long long ll;
typedef pair<int ,int > pii;
ll t, n, arr[N], best[N];
ll ans = 0;
map <ll, ll> ct;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    priority_queue <pii > pq;
    for(int i = 0; i < t; i++){
        cin >> arr[i];
        ct[arr[i] - i]+= arr[i];
        ans = max( ct[arr[i] - i], ans);
    }
    cout << ans;
	return 0;
}