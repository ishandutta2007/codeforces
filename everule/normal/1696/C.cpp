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
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        cin>>a;
        int k;
        cin>>k;
        vector<int> b(k);
        cin>>b;
        vector<array<ll, 2>> a_red, b_red;
        for(int i=0;i<n;i++){
            int num = 1;
            int val = a[i];
            while(val % m == 0){
                num *= m;
                val /= m;
            }
            if(a_red.size() > 0 && a_red.back()[0] == val) a_red.back()[1] += num;
            else a_red.push_back({val, num});
        }
        for(int i=0;i<k;i++){
            int num = 1;
            int val = b[i];
            while(val % m == 0){
                num *= m;
                val /= m;
            }
            if(b_red.size() > 0 && b_red.back()[0] == val) b_red.back()[1] += num;
            else b_red.push_back({val, num});
        }
        if(a_red == b_red){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
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