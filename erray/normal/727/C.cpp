    #include <bits/stdc++.h>
    typedef long long  ll;
    typedef unsigned long long int ull;
    #define flush fflush(stdout)
    #define umap unordered_map 
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
    #define N 500005
    using namespace std;       
    ll sz, n;
    ll sum[N];  
    ll arr[N];
    int main(){
        /*
        #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);  
        freopen("out.txt", "w", stdout);
        #endif
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        */
        cin >> sz;
        for(int i = 2; i <= sz; i++){
            cout << '?' << " " << 1 << " " << i << ln;
            flush;
            cin >> sum[i];
        }
        cout << '?' << " " << 2 << " " << 3 << ln;
        flush;
        cin >> n;
        ll fark = abs(sum[2] - sum[3]);
        if (sum[2] > sum[3]){
            arr[2] = (n + fark)/2;
            arr[3] = n - arr[2];
        }
        else {
            arr[3] = (n + fark)/2;
            arr[2] = n - arr[3];
        }
        arr[1]  = sum[3] - arr[3];
        cout << '!' << " " << arr[1] << " " << arr[2] << " " << arr[3];
        for(int i = 4; i <= sz; i++){
            cout << " " << sum[i] - arr[1];
        } 
        flush;
        return 0;
    }