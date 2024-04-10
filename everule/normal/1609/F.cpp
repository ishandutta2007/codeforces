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
    //n = rand() % 10 + 1;
    vector<ll> a(n);
    cin>>a;
    //for(auto &x : a) x = rand() % ll(10) + (1<<8);
    vector<int> lftmin(n), lftcnt(n), rhtmin(n), rhtcnt(n);
    stack<ll> lft;
    for(int i=0;i<n;i++){
        while(lft.size() && a[lft.top()] > a[i]){
            lft.pop();
        }
        if(lft.size()) lftmin[i] = lft.top();
        else lftmin[i] = -1;
        lft.push(i);
    }
    stack<ll> rht;
    for(int i=n-1;i>=0;--i){
        while(rht.size() && a[rht.top()] > a[i]){
            rht.pop();
        }
        if(rht.size()) rhtmin[i] = rht.top();
        else rhtmin[i] = n;
        rht.push(i);
    }
    lft = stack<ll>();
    rht = stack<ll>();
    vector<int> lftmax(n), rhtmax(n);
    for(int i=0;i<n;i++){
        while(lft.size() && a[lft.top()] <= a[i]){
            lft.pop();
        }
        if(lft.size()) lftmax[i] = lft.top();
        else lftmax[i] = -1;
        lft.push(i);
    }
    for(int i=n-1;i>=0;--i){
        while(rht.size() && a[rht.top()] < a[i]){
            rht.pop();
        }
        if(rht.size()) rhtmax[i] = rht.top();
        else rhtmax[i] = n;
        rht.push(i);
    }
    lft = stack<ll>();
    rht = stack<ll>();
    vector<array<int, 8>> inbitl(n), outbitl(n), inbitr(n), outbitr(n);
    for(int i=0;i<n;i++){
        int b = __builtin_popcountll(a[i]);
        if(lftmin[i] == -1){
            fill(outbitl[i].begin(), outbitl[i].end(), -1);
            fill(inbitl[i].begin(), inbitl[i].end(), -1);
        }
        else{
            outbitl[i] = outbitl[lftmin[i]];
            if(outbitl[i][b/8] != -1) inbitl[i] = inbitl[outbitl[i][b/8]];
            else fill(inbitl[i].begin(), inbitl[i].end(), -1);
        }
        outbitl[i][b/8] = i;
        inbitl[i][b%8] = i;
    }
    for(int i=n-1;i>=0;--i){
        int b = __builtin_popcountll(a[i]);
        if(rhtmin[i] == n){
            fill(outbitr[i].begin(), outbitr[i].end(), n);
            fill(inbitr[i].begin(), inbitr[i].end(), n);
        }
        else{
            outbitr[i] = outbitr[rhtmin[i]];
            if(outbitr[i][b/8] != n) inbitr[i] = inbitr[outbitr[i][b/8]];
            else fill(inbitr[i].begin(), inbitr[i].end(), n);
        }
        outbitr[i][b/8] = i;
        inbitr[i][b%8] = i;
    }
    vector<array<int, 10>> quadliftl(n), quadliftr(n);
    for(int i=0;i<n;i++){
        if(lftmin[i] == -1){
            quadliftl[i][0] = i;
        }
        else{
            quadliftl[i][0] = lftmin[i];
        }
        for(int k=1;k<10;k++){
            quadliftl[i][k] = quadliftl[quadliftl[quadliftl[quadliftl[i][k-1]][k-1]][k-1]][k-1];
        }
    }
    for(int i=n-1;i>=0;--i){
        if(rhtmin[i] == n){
            quadliftr[i][0] = i;
        }
        else{
            quadliftr[i][0] = rhtmin[i];
        }
        for(int k=1;k<10;k++){
            quadliftr[i][k] = quadliftr[quadliftr[quadliftr[quadliftr[i][k-1]][k-1]][k-1]][k-1];
        }
    }
    auto findbitl = [&](int u, int b){
        if(outbitl[u][b/8] < 0) return outbitl[u][b/8];
        return inbitl[outbitl[u][b/8]][b%8];
    };
    auto findbitr = [&](int u,int b){
        if(outbitr[u][b/8] >= n) return outbitr[u][b/8];
        return inbitr[outbitr[u][b/8]][b%8];
    };
    auto findlimr = [&](int u,int r){
        for(int k=9;k>=0;--k){
            for(int c=0;c<3;c++){
                if(quadliftr[u][k] <= r){
                    u = quadliftr[u][k];
                }
            }
        }
        return u;
    };
    auto findliml = [&](int u,int l){
        for(int k=9;k>=0;--k){
            for(int c=0;c<3;c++){
                if(quadliftl[u][k] >= l){
                    u = quadliftl[u][k];
                }
            }
        }
        return u;
    };
    for(int b=0;b<61;b++){
        stack<ll> lft;
        for(int i=0;i<n;i++){
            if(__builtin_popcountll(a[i]) != b) continue;
            while(lft.size() && a[lft.top()] > a[i]){
                lft.pop();
            }
            if(lftmin[i] != -1 && findbitl(lftmin[i], b) != -1) lftcnt[i] = i - lftmin[i] + lftcnt[findbitl(lftmin[i], b)];
            else lftcnt[i] = i - lftmin[i];
            lft.push(i);
        } 
        stack<ll> rht;
        for(int i=n-1;i>=0;--i){
            if(__builtin_popcountll(a[i]) != b) continue;
            while(rht.size() && a[rht.top()] > a[i]){
                rht.pop();
            }
            if(rhtmin[i] != n && findbitr(rhtmin[i], b) != n) rhtcnt[i] = rhtmin[i] - i + rhtcnt[findbitr(rhtmin[i], b)];
            else rhtcnt[i] = rhtmin[i] - i;
            rht.push(i);
        }
    }
    auto solvemax = [&](int u){
        ll ans = 0;
        int l = lftmax[u];
        int r = rhtmax[u];
        if(u - l < r - u){
            int minele = u;
            for(int i=u;i>l;--i){
                if(a[i] < a[minele]){
                    minele = i;
                }
                int findnxt = rhtmin[minele];
                if(findnxt >= r){
                    if(__builtin_popcountll(a[u]) == __builtin_popcountll(a[minele])){
                        ans += r - u;
                    }
                    continue;
                }
                if(__builtin_popcountll(a[u]) == __builtin_popcountll(a[minele])){
                    ans += rhtmin[minele] - u;
                }
                int nxtb = findbitr(rhtmin[minele], __builtin_popcountll(a[u]));
                if(nxtb < 0 || nxtb >= r) continue;
                ans += rhtcnt[nxtb];
                int end = findlimr(nxtb, r);
                if(__builtin_popcountll(a[end]) == __builtin_popcountll(a[u])){
                    ans -= rhtmin[end] - r;
                }
                if(rhtmin[end] == n) continue; 
                int outb = findbitr(rhtmin[end], __builtin_popcountll(a[u]));
                if(outb >= 0 && outb < n) ans -= rhtcnt[outb];
            }
        }
        else{
            int minele = u;
            for(int i=u;i<r;i++){
                if(a[i] < a[minele]){
                    minele = i;
                }
                int findnxt = lftmin[minele];
                if(findnxt <= l){
                    if(__builtin_popcountll(a[u]) == __builtin_popcountll(a[minele])){
                        ans += u - l;
                    }
                    continue;
                }
                if(__builtin_popcountll(a[u]) == __builtin_popcountll(a[minele])){
                    ans += u - lftmin[minele];
                }
                int nxtb = findbitl(lftmin[minele], __builtin_popcountll(a[u]));
                if(nxtb <= l || nxtb >= n) continue;
                ans += lftcnt[nxtb];
                int end = findliml(nxtb, l);
                if(__builtin_popcountll(a[end]) == __builtin_popcountll(a[u])){
                    ans -= l - lftmin[end];
                }
                if(lftmin[end] == -1) continue;
                int outb = findbitl(lftmin[end], __builtin_popcountll(a[u]));
                if(outb >= 0 && outb < n) ans -= lftcnt[outb];
            }
        }
        return ans;
    };
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += solvemax(i);
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    solve();
}