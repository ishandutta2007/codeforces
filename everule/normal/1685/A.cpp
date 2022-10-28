#include <bits/stdc++.h>
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
    map<int, int> cnt;
    vector<int> a(n);
    cin>>a;
    if(n % 2){
        cout<<"NO\n";
        return;
    }
    for(auto &x : a) cnt[x]++;
    for(auto &[a, b] : cnt){
        if(b > n / 2){
            cout<<"NO\n";
            return;
        }
    }
    if(n % 2 == 0){
        for(auto &[x, b] : cnt){
            if(b == n / 2){
                vector<int> ans(n);
                for(int i=0;i<n;i+=2) ans[i] = x;
                int j = 1;
                for(int i=0;i<n;i++){
                    if(a[i] == x) continue;
                    ans[j] = a[i];
                    j += 2; 
                }
                auto check = [&](){
                    for(int i=0;i<n;i++){
                        int a = ans[(i + n - 1) % n];
                        int b = ans[i];
                        int c = ans[(i + 1) % n];
                        if(!((a < b && c < b) || (a > b && c > b))){
                            return false;
                        }
                    }
                    return true;
                };
                if(check()){
                    cout<<"YES\n";
                    cout+ans;
                    return;
                }
                else{
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[i] = a[i / 2 + i % 2 * (n / 2) + (n % 2)];
    }
    cout<<"YES\n";
    cout+ans;
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