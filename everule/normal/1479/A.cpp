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
    if(n == 1){
        cout<<"! 1"<<endl;
        return;
    }
    auto query = [&](int idx){
        cout<<"? "<<idx + 1<<endl;
        int ans;
        cin>>ans;
        return ans;
    };
    int a = query(0);
    int b = query(1);
    if(a < b){
        cout<<"! 1"<<endl;
        return;
    }
    int c = query(n-1);
    int d = query(n-2);
    if(c < d){
        cout<<"! "<<n<<endl;
        return;
    }
    int mn = 1, mx = n-2;
    while(mn < mx){
        int mid = (mn + mx)/2;
        int a = query(mid);
        int b = query(mid-1);
        int c = query(mid+1);
        if(a < b && a < c){
            mn = mx = mid;
            break;
        }
        if(a > b){
            mx = mid-1;
        }
        if(a > c){
            mn = mid+1;
        }
    }
    cout<<"! "<<mn + 1<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}