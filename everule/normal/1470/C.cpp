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
struct Judge{
    int n;
    vector<int> curr;
    int p;
    Judge(int n,int k,int p) : curr(n,k), n(n), p(p) {}
    int query(int pos){
        int ans = curr[pos];
        vector<int> curr2(n);
        for(int i=0;i<n;i++){
            if(i==p){
                curr2[(i+1)%n] += curr[i];
            }
            else{
                curr2[(i-1+n)%n] += curr[i]/2;
                curr2[(i+1)%n] += curr[i] - curr[i]/2;
            }
        }
        curr = curr2;
        return ans;
    }
};
//Judge judge(3000,1e9,0);
const int BQ = 323;
void solve(){
    int n,k;
    cin>>n>>k;
    //n = judge.n;
    //k = judge.curr[0];
    static_assert(3*BQ <= 1000);
    auto query = [&](int pos){
        //pos %= n;
        cout<<"? "<<pos+1<<endl;
        int ans;
        cin>>ans;
        return ans;
        //return judge.query(pos);
    };
    auto answer = [&](int pos){
        //pos %= n;
        cout<<"! "<<pos+1<<endl;
    };
    for(int i=0;i<BQ;i++){
        query(0);
    }
    if(n <= 2 * BQ){
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = query(i);
        }
        for(int i=0;i<n;i++){
            if(ans[(i-1+n)%n] < ans[i] && ans[i] < ans[(i+1)%n]){
                answer(i);
                return;
            }
        }
    }
    int a = query(0);
    int b = query(1);
    if(a < k){
        vector<int> ans(BQ + 10);
        for(int i=0;i<BQ+10;i++){
            ans[i] = query(i);
        }
        for(int i=0;i<BQ+9;i++){
            if(ans[i] < ans[i+1]){
                answer(i+1);
                return;
            }
        }
    }
    if(a < b){
        int v = query(n-1);
        if(a < v){
            answer(1);
        }
        else{
            answer(0);
        }
        return;
    }
    if(b > k){
        int v = query(n-1);
        if(v < a){
            answer(n-1);
            return;
        }
        else{}
        int prev = 2e9 + 7;
        for(int i=n-BQ-10;i<n;i++){
            int curr = query(i);
            if(prev < curr){
                answer(i);
                return;
            }
            prev = curr;
        }
    }
    int l = 0;
    for(;l<n;l+=BQ){
        if(query(l) < k) break;
    }
    int r = n-1;
    while(l < r){
        int mid = (l+r)/2;
        if(query(mid) < k){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    answer(l);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}