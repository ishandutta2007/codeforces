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
    int n,k;
    cin>>n>>k;
    int q = 0;
    vector<bool> distinct(n, 1);
    auto query = [&](int c){
        cout<<"? "<<c + 1<<endl;
        char x;
        cin>>x;
        ++q;
        return (x == 'Y');
    };
    auto clear = [&]{
        cout<<"R"<<endl;
    };
    function<void(int,int)> divide = [&](int l,int r){
        if(r - l == k){
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
        for(int i=l;i<mid;i+=(k+1)/2){
            for(int j=mid;j<r;j+=(k+1)/2){
                for(int x=i;x<i+(k+1)/2;x++){
                    if(!distinct[x]) continue;
                    if(query(x)){
                        distinct[x] = 0;
                    }
                }
                for(int x=j;x<j+(k+1)/2;x++){
                    if(!distinct[x]) continue;
                    if(query(x)){
                        distinct[x] = 0;
                    }
                }
                clear();
            }
        }
    };
    divide(0,n);
    cout<<"! "<<count(distinct.begin(), distinct.end(), 1)<<"\n";
    //cerr<<q<<" "<<2*n*n/k<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}