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
struct Test{
    string name;
    bool example;
    int getval() const{
        int ans = 0;
        if(name[0]=='0'){
            return -1;
        }
        for(int i=0;i<name.size();i++){
            if(name[i]<'0' || name[i]>'9'){
                return -1;
            }
            ans*=10;
            ans+=name[i]-'0';
        }
        return ans;
    }
    bool operator<(const Test &o){
        return getval() < o.getval();
    }
};
void solve(){
    int n;
    cin>>n;
    set<int> notused;
    int e = 0;
    vector<Test> seq(n);
    for(auto &test : seq){
        cin>>test.name>>test.example;
        e+=test.example;
    }
    vector<Test> wexample, wmain;
    for(int i=1;i<=n;i++) notused.insert(i);
    for(const auto &test : seq){
        int v = test.getval();
        notused.erase(v);
        if(test.example){
            if(v==-1 || v>e){
                wexample.pb(test);
            }
        }
        else{
            if(v==-1 || v>n || v<=e){
                wmain.pb(test);
            }
        }
    }
    sort(wexample.begin(), wexample.end());
    sort(wmain.begin(), wmain.end());
    if(notused.empty() && wexample.empty()){
        assert(wmain.empty());
        cout<<"0\n";
        return;
    }
    struct final{
        Test s;
        int put;
        final(const Test &s, int put) : s(s), put(put) {}
    };
    string s(6, '-');
    for(int i=0;i<6;i++){
        if(rand()%4==0){
            s[i] = '0' + rand()%10;
        }
        else{
            s[i] = 'a' + rand()%26;
        }
    }
    function<void(Test&, int)> move = [&](Test &x, int put){
        if(put!=-1){
            cout<<"move "<<x.name<<" "<<put<<"\n";
            return;
        }
        cout<<"move "<<x.name<<" "<<s<<"\n";
    };
    vector<final> ans;
    if(notused.empty()){
        Test &test = wexample[0];
        assert(test.getval()!=-1);
        notused.insert(test.getval());
        ans.pb({test, -1});
        test.name = s;
    }
    while(wexample.size() || wmain.size()){
        int x = *notused.begin();
        if(x<=e){
            Test test = wexample.back();
            int y = test.getval();
            ans.pb({test, x});
            wexample.pop_back();
            if(y>=1 && y<=n){
                notused.insert(y);
            }
        }
        else{
            Test test = wmain.back();
            int y = test.getval();
            if(y>=1 && y<=n){
                notused.insert(y);
            }
            ans.pb({test, x});
            wmain.pop_back();
        }
        notused.erase(x);
    }
    cout<<ans.size()<<"\n";
    for(auto &[t,p] : ans){
        move(t,p);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    solve();
}