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
    string s;
    cin>>s;
    int o=0,z=0,any=0;
    bool flag = 0;
    for(int i=0;i<k;i++){
        bool set=0,w=0;
        for(int j=i;j<n;j+=k){
            if(s[j]=='1'){
                if(set && w==0){
                    flag = 1;
                }
                set=1;
                w=1;
            }
            if(s[j]=='0'){
                if(set && w==1){
                    flag = 1;
                }
                set = 1;
                w = 0;
            }
        }
        if(!set){
            ++any;
        }
        else if(w){
            ++o;
        }
        else{
            ++z;
        }
    }
    if(o<=k/2 && z<=k/2 && !flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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