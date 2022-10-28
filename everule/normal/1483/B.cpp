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
    set<array<int, 2>> a;
    set<int> dl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.insert({i, x});
    }
    auto getprev = [&](int u){
        auto it = a.lower_bound({u, -1});
        assert((*it)[0] == u);
        if(it == a.begin()){
            return --a.end();
        }
        else{
            return --it;
        }
    };
    auto getnext = [&](int u){
        auto it = a.lower_bound({u, -1});
        assert((*it)[0] == u);
        if(it == --a.end()){
            return a.begin();
        }
        else{
            return ++it;
        }
    };
    auto getthis = [&](int u){
        auto it = a.lower_bound({u, -1});
        assert((*it)[0] == u);
        return it;
    };
    for(int i=0;i<n;i++){
        if(n > 1 && gcd((*getprev(i))[1], (*getthis(i))[1]) == 1){
            dl.insert(i);
        }
    }
    auto getnextdl = [&](int c){
        auto it = dl.upper_bound(c);
        if(it == dl.end()) return dl.begin();
        else return it;
    };
    vector<int> ans;
    int c = 0;
    //for(auto &i : dl) cout<<i<<"\n";
    while(dl.size() > 0){
        auto nxt = getnextdl(c);
        auto itp = getprev(*nxt);
        auto itn = getnext(*nxt);
        auto it = getthis(*nxt);
        ans.push_back(*nxt + 1);
        c = (*itn)[0];
        cout.flush();
        if(gcd((*it)[1], (*itn)[1]) == 1){
            dl.erase(dl.find((*itn)[0]));
        }
        if(a.size() > 2 && gcd((*itp)[1], (*itn)[1]) == 1){
            dl.insert((*itn)[0]);
            //cout<<(*itp)[0]<<" "<<(*itn)[0]<<"\n";
        }
        a.erase(getthis(*nxt));
        dl.erase(nxt);
    }
    if(a.size() == 1 && (*a.begin())[1] == 1){
        ans.push_back((*a.begin())[0] + 1);
    }
    cout<<ans.size()<<" ";
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