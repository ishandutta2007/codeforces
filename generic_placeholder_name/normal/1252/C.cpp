#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair

int main(){
    int n, k;
    map<vector<pii>, int> freq;
    cin>>n>>k;
    ll ans=0;
    for(int i=1; i<=n; i++){
        int tmp; cin>>tmp;
        vector<pii> f;
        for(int j=2; j<=sqrt(tmp); j++){
            if(tmp%j==0){
                int cnt=0;
                while(tmp%j==0){
                    cnt++; tmp/=j;
                }
                if(cnt%k!= 0){
                    f.push_back(mp(j, cnt%k));
                }
            }
        }
        if(tmp!=1) f.push_back(mp(tmp, 1));
        vector<pii> rev;
        for(auto p : f){
            rev.push_back(mp(p.fi, (k-p.se)%k));
        }
        ans += freq[rev];
        freq[f]++;
    }
    cout<<ans<<endl;
}