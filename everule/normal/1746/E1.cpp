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
        cout<<"! 1\n";
        cout.flush();
        return;
    }
    //int x;
    //cin>>x;
    //bool prev = true;
    auto q = [&](int bit) -> bool{
        vector<int> qr;
        for(int x=1;x<=n;x++){
            if(x & (1<<bit)){
                qr.push_back(x);
            }
        }
        if(qr.size() == 0) return false;
        cout<<"? "<<qr.size()<<" ";
        cout+qr;
        cout.flush();
        string ans;
        cin>>ans;
        return (ans == "YES");
        /*
        if(prev == false){
            return (x & (1<<bit)) > 0;
        }
        else{
            if(rand() % 2){
                prev = true;
                return (x & (1<<bit)) > 0;
            }
            else{
                if(rand() % 2){
                    prev = false;
                    return (x & (1<<bit)) == 0;
                }
                else{
                    return (x & (1<<bit)) > 0;
                }
            }
        }
        */
    };
    int mbit = 32 - __builtin_clz(n);
    vector<array<int, 2>> bit_val(mbit, {-1, -1});
    int base_bit = 0;
    for(int i=1;i<mbit;i++){
        bool ans1 = q(base_bit);
        bool ans2 = q(i);
        bool ans3 = q(i);
        bool ans4 = q(base_bit);
        //cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<"\n";
        if(ans2 == ans3){
            bit_val[i] = {-1, ans2};
        }
        else{
            if(ans1 == ans4){
                bit_val[base_bit] = {-1, ans1};
                base_bit = i;
            }
            else{
                bit_val[i] = {base_bit, ans3 ^ ans1};
            }
        }
    }
    /*for(auto &[chg, dep] : bit_val){
        cout<<chg<<" "<<dep<<"\n";
    }*/
    vector<int> bits(mbit);
    for(int i=0;i<mbit;i++){
        auto [dep, chg] = bit_val[i];
        if(chg == -1){
            chg = 0;
        }
        if(dep != -1) chg ^= bits[dep];
        bits[i] = chg;
    }
    int ans1 = 0;
    for(int i=0;i<mbit;i++) if(bits[i]) ans1 |= (1<<i);
    for(int i=0;i<mbit;i++){
        auto [dep, chg] = bit_val[i];
        if(chg == -1){
            chg = 1;
        }
        if(dep != -1) chg ^= bits[dep];
        bits[i] = chg;
    }
    int ans2 = 0;
    for(int i=0;i<mbit;i++) if(bits[i]) ans2 |= (1<<i);
    if(ans1 == 0) swap(ans1, ans2);
    cout<<"! "<<ans1<<"\n";
    cout.flush();
    string ret;
    cin>>ret;
    if(ret == ":("){
        cout<<"! "<<ans2<<"\n";
        cout.flush();
        string ret;
        cin>>ret;
        if(ret == ":(") cout<<":(\n";
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}