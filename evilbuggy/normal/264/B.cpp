#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

int lpf[100005];

void pre(){
    memset(lpf, 0, sizeof(lpf));
    for(int i = 2; i < 100005; i++){
        if(!lpf[i]){
            for(int j = i; j < 100005; j += i){
                if(!lpf[j])lpf[j] = i;
            }
        }
    }
}

vector<int> fac[100005];
int a[100005];

void comp(int n){
    for(int i = 1; i <= n; i++){
        int x = a[i];
        while(x > 1){
            int t = lpf[x];
            while(x%t == 0)x /= t;
            fac[i].push_back(t);
        }
    }
}

int maxi[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    comp(n);
    memset(maxi, 0, sizeof(maxi));
    for(int i = 1; i <= n; i++){
        int ret = 1;
        for(auto x : fac[i]){
            ret = max(ret, maxi[x] + 1);
        }
        for(auto x : fac[i]){
            maxi[x] = max(maxi[x], ret);
        }
    }
    int ans = 1;
    for(int i = 1; i < 100005; i++){
        ans = max(ans, maxi[i]);
    }
    cout<<ans<<endl;
}