#include <iostream>
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
const int MAXA = 1e5;
void solve(){
    int n;
    cin>>n;
    set<pair<int,int>> logs;
    vector<int> count(MAXA + 1);
    for(int i=1;i<=MAXA;i++){
        logs.insert({0, i});
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        logs.erase({count[x], x});
        ++count[x];
        logs.insert({count[x], x});
    }
    int q;
    cin>>q;
    int ch = 0;
    for(int i=1;i<=MAXA;i++){
        ch+=count[i]/2;
    }
    while(q--){
        char x;
        cin>>x;
        if(x=='+'){
            int y;
            cin>>y;
            ch-=count[y]/2;
            logs.erase({count[y], y});
            ++count[y];
            logs.insert({count[y], y});
            ch+=count[y]/2;
        }
        else{
            int y;
            cin>>y;
            ch-=count[y]/2;
            logs.erase({count[y], y});
            --count[y];
            logs.insert({count[y], y});
            ch+=count[y]/2;
        }
        auto it = logs.end();
        if(logs.empty()){ 
            cout<<"No\n";
            continue;
        }
        --it;
        if((*it).first<4){
            cout<<"No\n";
            continue;
        }
        if(ch>=4){
            cout<<"Yes\n";
            continue;
        }
        cout<<"No\n";
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}