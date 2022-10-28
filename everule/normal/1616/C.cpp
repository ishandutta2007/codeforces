#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    int ans = n - 1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff = a[j] - a[i];
            int dist = j - i; 
            if(diff == 0){
                ans = min(ans, n - count(a.begin(), a.end(), a[i]));
                continue;
            }
            int g = __gcd(abs(diff), dist);
            int srt = i % (dist / g);
            int ele = a[i] + (srt - i) * (a[j] - a[i]) / (j - i);
            int gp = (a[j] - a[i]) * (dist/g) / (j - i);
            int cv = ele;
            int op = n;
            for(int k=srt;k<n;k+=dist/g){
                op -= (a[k] == cv);
                cv += gp;
            }
            ans = min(ans, op);
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}