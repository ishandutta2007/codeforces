#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define em emplace
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair

typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const ll INF = 1e18;
const int inf = 1e9;

int v[10010];

int Or(int i, int j) {
    cout << "or " << i << " " << j << endl;
    int x;
    cin >> x;
    if(x == -1) exit(0);
    return x;
} 

int And(int i, int j) {
    cout << "and " << i << " " << j << endl;
    int x;
    cin >> x;
    if(x == -1) exit(0);
    return x;
}

int main() {
    int n, k;
    cin >> n >> k;

    int a[3], o[3];
    a[0] = And(1, 2);
    a[1] = And(2, 3);
    a[2] = And(1, 3);
    o[0] = Or(1, 2);
    o[1] = Or(2, 3);
    o[2] = Or(1, 3);

    for(int i=0; i<=30; i++) {
        if(o[0] & o[1] & o[2] & (1 << i)) {
            v[1] += (a[0] | a[2]) & (1 << i); 
            v[2] += (a[0] | a[1]) & (1 << i); 
            v[3] += (a[1] | a[2]) & (1 << i); 
        }
        else {
            v[1] += (o[0] & o[2]) & (1 << i); 
            v[2] += (o[0] & o[1]) & (1 << i); 
            v[3] += (o[1] & o[2]) & (1 << i); 
        }
    }

    for(int i=4; i<=n; i++) {
        int x = And(1, i);
        int y = Or(1, i);

        v[i] = v[1] ^ x ^ y;
    }

    sort(v+1, v+n+1);

    cout << "finish " << v[k] << endl;
}