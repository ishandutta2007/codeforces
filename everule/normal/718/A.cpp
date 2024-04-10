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
    //digit x < 5
    //digit y < 4
    //digit z >= 5
    //digit t is arbitrary
    //xx.xxxxxx y 444444 z //tttttt
    int n,t;
    cin>>n>>t;
    string num;
    cin>>num;
    int decimal_point = std::find(num.begin(), num.end(), '.') - num.begin();
    int z_pos = decimal_point + 1;
    while(z_pos < n){
        if(num[z_pos] - '0' >= 5){
            break;
        }
        ++z_pos;
    }
    if(z_pos == n){
        cout<<num<<"\n";
        return;
    }
    int y_pos = z_pos - 1;
    while(true){
        if(num[y_pos] != '4'){
            break;
        }
        --y_pos;
    }
    //cout<<decimal_point<<" "<<y_pos<<" "<<z_pos<<"\n";
    //3.14445
    //3.1445
    //3.145
    //3.15
    //3.2
    int upto = max(y_pos, z_pos - t);
    if(num[upto] == '.') --upto;
    string ans = num.substr(0, upto);
    if(num[upto] == '9'){
        string ans = num.substr(0, decimal_point);
        int idx = ans.size() - 1;
        while(idx >= 0 && ans[idx] == '9') ans[idx--] = '0';
        //9999999
        if(idx == -1){
            //999999
            //1000000
            string newans(ans.size(), '0');
            newans = string("1") + newans;
            cout<<newans<<"\n";
            return;
        }
        ans[idx] = ans[idx] + 1;
        cout<<ans<<"\n";
        return;
    }
    ans.push_back(num[upto] + 1);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}