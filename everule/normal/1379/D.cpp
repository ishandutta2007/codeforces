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
void solve(){
    int n,h,m,k;
    cin>>n>>h>>m>>k;
    vector<pair<int,int>> trains(2*n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        trains[i].first = b%(m/2);
        trains[n+i].first = m/2 + trains[i].first; 
        trains[i].second = i;
        trains[n+i].second = i;
    }
    sort(trains.begin(), trains.end());
    queue<int> curr;
    int ans = n;
    int start = 1;
    for(const auto &t : trains){
        while(curr.size() && curr.front() <= t.first-k){
            curr.pop();
        }
        if(t.first >= k){
            if(ans > curr.size()){
                ans = curr.size();
                start = t.first;
            }
        }
        curr.push(t.first);
    }
    cout<<ans<<" "<<(start>=m/2 ? start - m/2 : start)<<"\n";
    set<ll> train;
    for(const auto &t : trains){
        if(t.first>start-k && t.first < start){
            cout<<t.second + 1<<" ";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}