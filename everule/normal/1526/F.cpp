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
const int guesses = 300;
void solve(){
    int n;
    cin>>n;
    //n = 20;
    //vector<int> p(n);
    //iota(p.begin(), p.end(), 1);
    //cin>>p;
    //random_shuffle(p.begin(), p.end());
    //if(p[0] > p[1]) for(int i=0;i<n;i++) p[i] = n - p[i] + 1;
    auto query = [&](int x,int y,int z){
        cout<<"? "<<x+1<<" "<<y+1<<" "<<z+1<<endl;
        int ans;
        cin>>ans;
        if(ans == -1) exit(0);
        return ans;
        /*vector<int> ele = {p[x], p[y], p[z]};
        sort(ele.begin(), ele.end());
        return max(ele[2] - ele[1], ele[1] - ele[0]);*/
    };
    int u,v,w;
    for(int i=0;i<guesses;i++){
        u = rand() % n;
        v = rand() % n;
        w = rand() % n;
        if(u == v || v == w || u == w) continue;
        int ans = query(u, v, w);
        if(ans < n / 6) break;
    }
    vector<int> bst(n, -1);
    for(int i=0;i<n;i++){
        if(i == u || i == v || i == w) continue;
        bst[i] = query(u, v, i);
    }
    //cout<<u<<" "<<v<<" "<<w<<"\n";
    //cout+bst;
    vector<int> bstid(n);
    iota(bstid.begin(), bstid.end(), 0);
    sort(bstid.begin(), bstid.end(), [&](int x,int y){
        return bst[x] > bst[y];
    });
    //cout<<bstid[0]<<" "<<bstid[1]<<"\n";
    int one_pos = bstid[0];
    int two_pos = bstid[1];
    int cnt = 0;
    while(bst[bstid[0]] == bst[bstid[1]] || bst[bstid[1]] == bst[bstid[2]]){
        int u = rand() % n;
        int v = rand() % n;
        if(u == v || find(bstid.begin(), bstid.begin() + 5, u) != bstid.begin() + 5 || find(bstid.begin(), bstid.begin() + 5, v) != bstid.begin() + 5) continue;
        //cout<<u<<" "<<v<<"\n";
        for(int i=0;i<5;i++) bst[bstid[i]] = query(u, v, bstid[i]);
        sort(bstid.begin(), bstid.begin() + 5, [&](int x,int y){
            return bst[x] > bst[y];
        });
        one_pos = bstid[0];
        two_pos = bstid[1];
    }
    vector<int> ans(n);
    ans[one_pos] = 1;
    ans[two_pos] = 2;
    for(int i=0;i<n;i++){
        if(i == one_pos || i == two_pos) continue;
        ans[i] = query(one_pos, two_pos, i) + 2;
    }
    if(ans[0] > ans[1]) for(int i=0;i<n;i++) ans[i] = n - ans[i] + 1;
    cout<<"! ";
    cout+ans;
    cout.flush();
    int check = 0;
    cin>>check;
    if(check == -1) exit(0);
    //cout+ans;
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