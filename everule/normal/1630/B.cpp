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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int t = (n + k + 1) / 2;
    cin>>a;
    vector<int> olda = a;
    sort(a.begin(), a.end());
    int ans = n + 1;
    int x,y;
    for(int i=t-1;i<n;i++){
        if(ans > a[i] - a[i-t+1]){
            ans = a[i] - a[i-t+1];
            x = a[i-t+1];
            y = a[i];
        }
    }
    cout<<x<<" "<<y<<"\n";
    int l = 0;
    int s = 0;
    int good = 0, bad = 0;
    for(int i=0;i<n;i++){
        if(x <= olda[i] && olda[i] <= y){
            good++;
        }
        else{
            bad++;
        }
        if(good > bad && s < k - 1){
            cout<<l+1<<" "<<i+1<<"\n";
            l = i + 1;
            good = 0;
            bad = 0;
            s++;
        }
    }
    cout<<l+1<<" "<<n<<"\n";
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