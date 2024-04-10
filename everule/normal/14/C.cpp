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
int sign(ll x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return -1;
    }
    else{
        return 1;
    }
}
void solve(){
    vector<vector<int>> seq(4, vector<int>(4));
    cin>>seq;
    vector<pair<int,int>> v, h;
    vector<int> x, y;
    for(int i=0;i<4;i++){
        if(seq[i][0]==seq[i][2] && seq[i][1]==seq[i][3]){
            cout<<"NO\n";
            return;
        }
        if(seq[i][0]==seq[i][2]){
            v.pb({seq[i][1], seq[i][3]});
            x.pb(seq[i][0]);
        }
        if(seq[i][1]==seq[i][3]){
            h.pb({seq[i][0], seq[i][2]});
            y.pb(seq[i][1]);
        }
    }
    //cout+x+y;
    if(v.size()!=2 || h.size()!=2){
        cout<<"NO\n";
        return;
    }
    if(x[0]==x[1] || y[0]==y[1]){
        cout<<"NO\n";
        return;
    }
    for(auto &x : v){
        if(x.first > x.second){
            swap(x.first, x.second);
        }
    }
    for(auto &x : h){
        if(x.first > x.second){
            swap(x.first, x.second);
        }
    }
    for(const auto &l : v){
        //cout<<l.first<<" "<<l.second<<"\n";
        for(const auto &val : y){
            if(l.first==val || val==l.second) continue;
            cout<<"NO\n";
            return;
        }
    }
    for(const auto &l : h){
        //cout<<l.first<<" "<<l.second<<"\n";
        for(const auto &val : x){
            if(l.first==val || val==l.second) continue;
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}