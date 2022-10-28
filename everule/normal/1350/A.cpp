#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; 
typedef long long ll;
const ll N_MAX = 1e6+10;

vector<ll> min_div(N_MAX+1, 0);
vector<bool> isprime(N_MAX+1, 1);
void sieve(){
    for (ll i = 2; i*i<=N_MAX; i+=2){
        if(isprime[i]){
            for(int j=2*i;j<=N_MAX;j+=i){
                isprime[j]=0;
            }
        }
    }
    for(int i=2;i<=N_MAX;i++){
        if(!isprime[i]){
            continue;
        }
        for(int j=i;j<=N_MAX;j+=i){
            if(min_div[j]==0){
                min_div[j]=i;
            }
        }
    }
}

int main() {
#ifdef ks
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int t;

    cin >> t;
    while(t--){
        ll n,k;

        cin >> n >> k;
        
        if (n&1)
            n += 2*(k-1) + min_div[n];
        else
            n += 2*k;

        cout << n << "\n";
    }    

    // for (int i=1; i<=200; i++){
    //     cout << i << " " << min_div[i] << "\n";
    // }

    return 0;
}