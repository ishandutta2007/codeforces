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
vector<vector<int>> euler;
void precompute(){
    euler.resize(11);
    euler[0] = {0,1};
    euler[1] = {0,2,1,3,0};
    vector<int> p2(12);
    p2[0] = 1;
    for(int i=1;i<12;i++){
        p2[i] = p2[i-1] * 2;
    }
    for(int i=2;i<=10;i++){
        int s = euler[i-1].size();
        auto add = [&](int o1, int o2){
            for(int j=0;j<s;j++){
                euler[i].push_back(euler[i-1][j] + (j%2 ? o2 : o1));
            }
        };
        add(0,p2[i-1]);
        euler[i].pop_back();
        for(int j=0;j<s;j++){
            if(j%2 == 0){
                euler[i].push_back(euler[i-1][j]);
            }
            else{
                euler[i].push_back(euler[i-1][j] + p2[i]);
            }
        }
        euler[i].pop_back();
        for(int j=0;j<s;j++){
            if(j%2 == 0){
                euler[i].push_back(p2[i] - 1 - euler[i-1][j]);
            }
            else{
                euler[i].push_back(euler[i-1][j] + p2[i-1]);
            }
        }
        for(int j=2;j<s;j++){
            if(j%2 == 0){
                euler[i].push_back(p2[i+1] - 1 - euler[i-1][j]);
            }
            else{
                euler[i].push_back(p2[i] - 1 - (euler[i-1][j] - p2[i-1]));
            }
        }
        euler[i].push_back(0);
    }
    /*
    for(int i=1;i<4;i++){
        //cout+euler[i];
    }
    int idx = 4;
    vector<vector<bool>> check(p2[idx], vector<bool>(p2[idx]));
    cout+euler[idx];
    for(int i=0;i+1<euler[idx].size();i+=2){
        check[euler[idx][i]][euler[idx][i+1] - p2[idx]] = 1;
    }
    for(int i=1;i+1<euler[idx].size();i+=2){
        check[euler[idx][i+1]][euler[idx][i] - p2[idx]] = 1;
    }
    for(int i=0;i<p2[idx];i++){
        for(int j=0;j<p2[idx];j++){
            cout<<check[i][j];
        }
        cout<<"\n";
    }
    */
}
struct Judge{
    vector<int> seq;
    queue<int> mem;
    vector<int> cnt;
    int n, k;
    Judge(int k, vector<int> seq) : n(seq.size()), seq(seq) , k(k), cnt(seq.size() + 1) {}
    char query(int x){
        bool ans = (cnt[seq[x]] != 0);
        ++cnt[seq[x]];
        mem.push(seq[x]);
        if(mem.size() > k){
            cnt[mem.front()]--;
            mem.pop();
        }
        return (ans ? 'Y' : 'N');
    } 
    void remove(){
        cnt.assign(n+1, 0);
        mem = queue<int>();
    }
};
void solve(){
    int n,k;
    cin>>n>>k;
    //vector<int> seq(n);
    //cin>>seq;
    int q = 0;
    //Judge judge(k, seq);
    vector<bool> distinct(n, 1);
    auto query = [&](int c){
        char x;
        cout<<"? "<<c + 1<<endl;
        //cout<<c<<endl;
        //x = judge.query(c);
        //cout<<x<<endl;
        cin>>x;
        ++q;
        return (x == 'Y');
    };
    auto clear = [&]{
        //judge.remove();
        cout<<"R"<<endl;
    };
    function<void(int,int)> divide = [&](int l,int r){
        if(r - l == k){
            if(k == 1) return;
            for(int i=l;i<r;i++){
                if(query(i)){
                    distinct[i] = 0;
                }
            }
            clear();
            return;
        }
        int mid = (l + r)/2;
        divide(l,mid);
        divide(mid,r);
        int range = (r - l)/k;
        auto makequeries = [&](int p){
            int cnt = 0;
            int didx = -1;
            for(int i=0;i<(k+1)/2;i++){
                int idx = p*((k+1)/2) + l + i;
                if(!distinct[idx]){
                    if(k!=1) ++cnt;
                    continue;
                }
                else{
                    didx = idx;
                }
                if(query(idx)){
                    distinct[idx] = 0;
                }
            }
            if(didx==-1){
                clear();
            }
            else{
                while(cnt){
                    query(didx);
                    --cnt;
                }
            }
        };
        int p2 = 30 - __builtin_clz(range*2);
        if(k==1) --p2;
        vector<int> &ord = euler[p2];
        for(const auto &x : ord){
            makequeries(x);
        }
        clear();
    };
    divide(0,n);
    cout<<"! "<<count(distinct.begin(), distinct.end(), 1)<<"\n";
    //cerr<<double(q)*k/n/n<<" "<<3*n*n/k/2<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    solve();
}