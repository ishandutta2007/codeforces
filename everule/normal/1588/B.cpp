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
    ll n;
    cin>>n;
    auto query = [&](int l,int r){
        cout<<"? "<<l<<" "<<r<<endl;
        ll ans;
        cin>>ans;
        return ans;
    };
    auto solveq = [&](ll x){
        ll l = 0, r = 1e9;
        while(l < r){
            ll mid = (l + r)/2;
            ll val = mid * (mid - 1) / 2;
            if(val < x){
                l = mid + 1;
            }
            else if(val > x){
                r = mid - 1;
            }
            else{
                l = r = mid;
            }
        }
        return l;
    };
    ll tot = query(1, n);
    ll l = 2, r = n-1;
    while(l < r){
        ll mid = (l + r)/2;
        ll inv = query(1, mid);
        if(inv > 0 && inv < tot){
            l = mid;
            break;
        }
        else if(inv == 0){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    ll i = -1,j = -1,k = -1;
    ll curr = query(1, l);
    ll nxt = query(1, l+1);
    if(curr + 1 == nxt){
        j = l;
    }
    else if(curr == nxt){
        j = l + 1;
    }
    else{
        ll st = l - (nxt - curr - 1);
        if((l - st) * (l - st + 1) / 2 == curr){
            i = st;
            while(l < r){
                ll mid = (l + r)/2;
                ll val = query(1, mid);
                if((mid - st) * (mid - st + 1) / 2 == val){
                    l = mid + 1;
                }
                else if(val == tot){
                    r = mid - 1;
                }
                else{
                    r = mid;
                    break;
                }
            }
            ll curr = query(1, r);
            ll nxt = query(1, r+1);
            j = r - (nxt - curr - 1);
        }
        else{
            j = st;
        }
    }
    ll sum1 = query(1, j);
    ll sum2 = tot - sum1;
    i = j - solveq(sum1);
    k = j - 1 + solveq(sum2);
    cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
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