#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln '\n'
#define MAX 1000000009
#define MOD 1000000007
#define N 100005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi; 
int t, n, x, b, ans = MAX, dist[78505], ct[78505], pl[1000007];
bool isPrime[1000007];
vi edge[N], prob[N], primes;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    pl[0] = 0;
    isPrime[1] = 1;
    for(ll i = 2; i <= 1000005; i++){
        if(!isPrime[i]){
            primes.pb(i);
            pl[i] = primes.size();
            for(ll j =  i * i; j <= 1000005; j += i){
                isPrime[j] = 1;
            }
            //cout << i<< ln;
        }
    }
    primes.pb(0);
    sort(all(primes));
    cin >> t;
    for(int i = 0; i< t; i++){
        cin >> x;
        bool b = 1;
        int num = (int)ceil(sqrt((double)x));
        for(int j = 1; j < primes.size() && primes[j] <= num; j++){
            int ct = 0;
            auto a = primes[j];
            while(x % a == 0){
                ct ^= 1;
                x /= a;
            }
            if(ct){
                prob[i].pb(j);
                //cout <<" bas " <<  j << " ";
            }
        }
        if(!isPrime[x]){
            prob[i].pb(pl[x]);
        }
        /*
        for(auto a : prob[i]){
            cout << primes[a] << " ";
        }
        cout << ln;
        */
    }
    int ans = MAX;
    for(int i = 0; i < t; i++){
        if(prob[i].empty()){
            cout << 1;
            return 0;
        }   
        else  if(prob[i].size() == 1){
            edge[prob[i][0]].pb(0);
            edge[0].pb(prob[i][0]);
        }
        else{
            edge[prob[i][0]].pb(prob[i][1]);
            edge[prob[i][1]].pb(prob[i][0]);
            //cout << primes[prob[i][0]] << " " <<  primes[prob[i][1]] << ln;
        }
    }
    int don = 0;
    for(int i = 0; i < primes.size() && primes[i] <= 1000; i++){
        don ++;
        queue <pii> q;
        memset(dist, -1, sizeof dist);
        memset(ct, 0, sizeof ct);
        q.push(mp(-1, i));
        dist[i] = 0;
        //cout << i << ln;
        while(!q.empty()){
            int nd = q.front().nd, par = q.front().st;
            q.pop();
            //cout << nd << ln;
            for(auto a : edge[nd]){
                //cout << a << " ";
                if(a == i){
                    ct[nd]++;
                }
                if(ct[nd] == 2){
                    //cout << nd << " asd\n";

                    ans = min(dist[nd] + 1, ans);
                }
                else if(dist[a] == -1){
                    dist[a] = dist[nd] + 1;
                    q.push(mp(nd, a));
                    //cout << a << " ";
                }
                else if(a != par){
                    //cout << primes[a] << " " << primes[nd] << ln;
                    ans = min(ans, dist[nd] + dist[a] + 1);
                }
            }
            //cout << ln;
        }
                   // cout << ln;

    }
    //cout << don << ln;
    cout << (ans == MAX ? -1 : ans);

}