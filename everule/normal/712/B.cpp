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
    string s;
    cin>>s;
    int x =0, y=0;
    for(int i=0;i<int(s.size());i++){
        if(s[i]=='L'){
            x--;
        }
        if(s[i]=='R'){
            x++;
        }
        if(s[i]=='U'){
            y++;
        }
        if(s[i]=='D'){
            y--;
        }
    }
    x = abs(x);
    y = abs(y);
    if((x+y)%2 == 1){
        cout<<"-1\n";
        return;
    }
    cout<<(x+y)/2<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}