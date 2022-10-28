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
    vector<int> seq(n);
    cin>>seq;
    vector<int> par(n, -1);
    for(int i=0,j=0;i<n;i++){
        if(seq[i]==2){
            while(j < i){
                ++j;
            }
            while(j < n && seq[j]!=1){
                ++j;
            }
            if(j==n){
                cout<<"-1\n";
                return;
            }
            par[j] = i;
            ++j;
        }
    }
    for(int i=0,j=0;i<n;i++){
        if(seq[i]==3){
            while(j <= i){
                ++j;
            }
            while(j < n && ((seq[j]==0) || par[j]!=-1)){
                ++j;
            }
            if(j==n){
                cout<<"-1\n";
                return;
            }
            par[j] = i;
            ++j;
        }
    }
    int d = n-1;
    vector<pair<int,int>> points;
    for(int i=0;i<n;i++){
        if(seq[i]!=1) continue;
        points.pb({d,i});
        if(par[i]==-1){
            --d;
            continue;
        }
        if(seq[par[i]]==2){
            points.pb({d,par[i]});
            --d;
            continue;
        }
        if(seq[par[i]]==3){
            --d;
            points.pb({d,i});
            points.pb({d,par[i]});
            --d;
            continue;
        }
        assert(false);
    }
    for(int i=0;i<n;i++){
        if(seq[i]==2){
            if(par[i]==-1) continue;
            points.pb({d,par[i]});
            points.pb({d,i});
            --d;
            continue;
        }
    }
    for(int i=n-1;i>=0;--i){
        if(seq[i]==3 && par[i]!=-1){
            points.pb({d,par[i]});
            points.pb({d,i});
            --d;
            continue;
        }
    }
    cout<<points.size()<<"\n";
    for(const auto &[x,y] : points){
        cout<<x+1<<" "<<y+1<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}