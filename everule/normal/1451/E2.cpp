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
int MEX(vector<int> &x){
    vector<bool> found(x.size());
    for(int i=0;i<x.size();i++){
        if(x[i]<x.size()){
            found[x[i]]=1;
        }
    }
    for(int i=0;i<x.size();i++){
        if(!found[i]){
            return i;
        }
    }
    return x.size();
}
void solve(){
    int n;
    cin>>n;
    vector<int> pxor(n);
    auto queryxor = [&](int i,int j){
        cout<<"XOR "<<i + 1<<" "<<j + 1<<endl;
        int ans;
        cin>>ans;
        return ans;
    };
    auto queryand = [&](int i,int j){
        cout<<"AND "<<i + 1<<" "<<j + 1<<endl;
        int ans;
        cin>>ans;
        return ans;
    };
    auto queryor = [&](int i,int j){
        cout<<"OR "<<i + 1<<" "<<j + 1<<endl;
        int ans;
        cin>>ans;
        return ans;
    };
    for(int i=1;i<n;i++){
        pxor[i] = queryxor(0,i);
    }
    auto solveequal = [&](){
        int idx1 = -1, idx2 = -1;
        map<int,int> last;
        for(int i=0;i<n;i++){
            if(last.count(pxor[i])){
                idx1 = last[pxor[i]];
                idx2 = i;
                break;
            }
            last[pxor[i]] = i;
        }
        if(idx1 == -1 && idx2 == -1){
            return false;
        } 
        int x = queryand(idx1, idx2);
        vector<int> seq(n);
        seq[0] = x ^ pxor[idx1];
        for(int i=1;i<n;i++){
            seq[i] = seq[0] ^ pxor[i];
        }
        cout<<"! ";
        cout+seq<<endl;
        return true;
    };
    if(solveequal()){
        return;
    }
    int par = 0;
    for(int i=1;i<n;i++){
        if(pxor[i]%2 == 0){
            par = (queryand(0,i)&1);
            break;
        }
    }
    vector<int> seq(n);
    for(int i=1;i<n;i++){
        if(pxor[i] == 1){
            seq[0] = queryor(0,i);
            if(seq[0]%2 != par){
                seq[0] ^= 1;
            }
            break;
        }
    }
    for(int i=1;i<n;i++){
        seq[i] = seq[0] ^ pxor[i];
    }
    cout<<"! ";
    cout+seq<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}