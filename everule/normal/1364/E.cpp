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
const int checks = 14;
const int numbers = 12;
const int queries = 4269;
const int MAXN = (1<<11);
void solve(){
    int n;
    cin>>n;
    //vector<int> seq(n);
    //cin>>seq;
    static_assert(2*MAXN + checks*numbers <= queries);
    auto query = [&](int i,int j){
        cout<<"? "<<i+1<<" "<<j+1<<endl;
        int ans;
        cin>>ans;
        //ans = (seq[i] | seq[j]);
        return ans;
    };
    auto find = [&](int i){
        int ans = (1<<30) - 1;
        for(int j=0;j<checks;j++){
            int x = rand()%n;
            while(x == i){
                x = rand()%n;
            }
            ans&=query(i, x);
        }
        return ans;
    };
    vector<pair<int,int>> found;
    for(int i=0;i<numbers;i++){
        int idx = rand()%n;
        int val = find(idx);
        found.push_back(pair(val,idx));
    }
    int idx1 = -1, idx2 = -1;
    int val1 = -1, val2 = -1;
    for(int i=0;i<numbers;i++){
        for(int j=0;j<numbers;j++){
            const auto &[v1,i1] = found[i];
            const auto &[v2,i2] = found[j];
            if((v1&v2) != 0) continue;
            idx1 = i1;
            idx2 = i2;
            val1 = v1;
            val2 = v2;
        }
    }
    if(idx1 == -1 && idx2 == -1){
        while(true) idx1++;
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(idx1 == i){
            ans[i] = val1;
            continue;
        }
        if(idx2 == i){
            ans[i] = val2;
            continue;
        }
        ans[i] = (query(idx1,i) & query(idx2,i));
    }
    cout<<"! ";
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    solve();
}