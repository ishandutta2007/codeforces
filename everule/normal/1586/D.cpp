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
    vector<int> q(n);
    auto query = [&](){
        cout<<"? ";
        cout+q;
        cout.flush();
        int ans;
        cin>>ans;
        return ans;
    };
    q.assign(n, 1);
    vector<int> p(n);
    p[n-1] = 1;
    for(int i=2;i<=n;i++){
        q[n-1] = i;
        int ans = query();
        if(ans == 0){
            p[n-1] = n - i + 2;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(i == p[n-1]) continue;
        int delta = i - p[n-1];
        if(delta > 0){
            q.assign(n, 1);
            q[n-1] = delta + 1;
        }
        else{
            q.assign(n, n);
            q[n-1] = n + delta;
        }
        int ans = query();
        p[ans-1] = i;
    }
    cout<<"! ";
    cout+p;
    cout.flush();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
//3 2 1 5 4