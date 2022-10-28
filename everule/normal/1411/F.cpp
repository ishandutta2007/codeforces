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
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> p(n);
    for(auto &x : p) cin>>x, --x;
    vector<int> cnt(n+3);
    array<int, 3> cntmod{};
    vector<int> clen;
    [&](){
        vector<bool> vis(n);
        int c = 0;
        function<void(int)> dfs = [&](int u){
            if(vis[u]) return;
            vis[u] = 1;
            ++c;
            dfs(p[u]);
        };
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            c = 0;
            dfs(i);
            cntmod[c%3]++;
            cnt[c]++;
            clen.push_back(c);
        }
    }();
    int nc = clen.size();
    for(int i=0;i<nc;i++) if(clen[i] > 2) clen.push_back(clen[i]-2);
    sort(clen.begin(), clen.end());
    clen.resize(unique(clen.begin(), clen.end()) - clen.begin());
    int ans = 0;
    auto get = [&](){
        int curr = ans;
        curr += n/3 - (n%3 == 1);
        curr -= cntmod[0];
        curr += (max(cntmod[1], cntmod[2]) - min(cntmod[1], cntmod[2]))/3;
        return curr;
    };
    auto sub = [&](int len){
        if(cnt[len] < 1 + (len == 1)) return false;
        cnt[len] -= 1 + (len == 1);
        cntmod[len%3] -= 1 + (len == 1);
        if(len > 2){
            cnt[len-2]++;
            cntmod[(len+1)%3]++;
        }
        ans+=(len != 2);
        return true;
    };
    auto add = [&](int len){
        cnt[len] += 1 + (len == 1);
        cntmod[len%3] += 1 + (len == 1);
        if(len > 2){
            cnt[len-2]--;
            cntmod[(len+1)%3]--;
        }
        ans-=(len != 2);
    };
    auto sub2 = [&](int len){
        if(len < 3) return false;
        if(len == 3){
            if(cnt[1] < 1 || cnt[3] < 1) return false;
            ans++;
            cnt[1]--;
            cntmod[1]--;
            cnt[3]--;
            cntmod[0]--;
            cnt[4]++;
            cntmod[1]++;
            return true;
        }
        if(cnt[len] < 1) return false;
        cnt[len]--;
        cntmod[len%3]--;
        if(len > 4){
            cnt[(len-4)]++;
            cntmod[(len+2)%3]++;
            ans++;
        }
        return true;
    };
    auto add2 = [&](int len){
        if(len == 3){
            ans--;
            cnt[1]++;
            cntmod[1]++;
            cnt[3]++;
            cntmod[0]++;
            cnt[4]--;
            cntmod[1]--;
            return;
        }
        cnt[len]++;
        cntmod[len%3]++;
        if(len > 4){
            cnt[(len-4)]--;
            cntmod[(len+2)%3]--;
            ans--;
        }
    };
    int fin = INF;
    if(n%3 == 0){
        fin = min(fin, get());
    }
    if(n%3 == 2){
        for(auto &l : clen){
            if(sub(l)){
                fin = min(fin, get());
                add(l);
            }
        }
    }
    if(n%3 == 1){
        for(auto &l1 : clen){
            if(sub(l1)){
                for(auto &l2 : clen){
                    if(sub(l2)){
                        fin = min(fin, get());
                        add(l2);
                    }
                }
                add(l1);
            }
        }
        assert(ans == 0);
        for(auto &l : clen){
            if(sub2(l)){
                fin = min(fin, get());
                add2(l);
            }
        }
    }
    ll fincnt = 1;
    while(n){
        fincnt *= (3 - (n%3 != 0));
        n -= 3 - (n%3 != 0);
        fincnt %= mod;
    }
    cout<<fincnt<<" "<<fin<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}