#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define L (no<<1)
#define R L|1
#define mid (s + e)>>1
#define ln '\n'
#define MAX (1<<31)
#define MOD 1000000007
#define N 300005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int t, n, x, k;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
    	cin >> n;
    	umap <int, bool> vis1, vis2;
    	pii ans;
    	for(int i = 0; i < n; i++){
    		cin >> k;
    		while(k--){
    			cin >> x;
    			if(!vis1[i] && !vis2[x]){
    				vis2[x] = 1;
    				vis1[i] = 1;
    			}
    		}
    	}
    	int n1 = -1, n2 = -1;
    	for(int i = 0; i < n; i++){
    		if(!vis1[i])n1 = i;
    	}
    	for(int i = 0; i < n; i++){
    		if(!vis2[i + 1])n2 = i + 1;
    	}
    	if(n1 != -1 && n2 != -1){
    		cout << "IMPROVE" << ln << n1 + 1 << " " << n2;
    	}
    	else {
    		cout <<"OPTIMAL";
    	}
    	cout << ln;

    }
}