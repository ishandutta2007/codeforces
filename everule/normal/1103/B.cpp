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
    string check;
    cin>>check;
    if(check!="start"){
        exit(0);
    }
    function<char(int,int)> query = [&](int x,int y){
        cout<<"? "<<x<<" "<<y<<endl;
        char ans;
        cin>>ans;
        return ans;
    };
    int p = 1;
    while(query(p, 2*p)=='y'){
        p*=2;
    }
    int mn = p, mx = 2*p;
    while(mn < mx){
        int mid = mn + mx;
        mid>>=1;
        char c =  query(p-1, mid);
        if(c=='y'){
            mn = mid + 1;
        }
        else{
            mx = mid;
        }
    }
    cout<<"! "<<mn<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        solve();
    }
}