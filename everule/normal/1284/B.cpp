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
    vector<vector<int>> seq(n);
    vector<int> mn;
    vector<int> mx;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        seq[i].resize(l);
        for(auto &x : seq[i]){
            cin>>x;
        }
        bool flag = 0;
        for(int j=1;j<l;j++){
            if(seq[i][j]>seq[i][j-1]){
                flag = 1;
            }
        }
        if(flag){
            a++;
        }
        else{
            b++;
            mn.push_back(*min_element(seq[i].begin(), seq[i].end()));
            mx.push_back(*max_element(seq[i].begin(), seq[i].end()));
        }
    }
    sort(mn.begin(), mn.end());
    sort(mx.begin(), mx.end());
    ll ans = 0;
    ans+=(ll)(n-b)*(n+b);
    for(int i=0,j=0;i<b;i++){
        while(j<b && mx[j]<=mn[i]){
            ++j;
        }
        ans+=b-j;
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}