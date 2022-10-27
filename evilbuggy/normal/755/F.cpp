#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;

const int maxn = 1000005;

int p[maxn], sz[maxn], cnt[maxn];
bitset<maxn> B;

int find(int v){
    return (p[v] == v)?v:(p[v] = find(p[v]));
}

void combine(int u, int v){
    u = find(u); v = find(v);
    if(u == v)return;
    if(sz[u] < sz[v])swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, k, x;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        cin>>x;
        combine(x, i);
    }
    memset(cnt, 0, sizeof(cnt));
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        if(find(i) == i){
            cnt[sz[i]]++;
            tmp += sz[i]/2;
        }
    }
    B[0] = 1;
    for(int i = 1; i <= n; i++){
        if(cnt[i] > 2){
            if(cnt[i]&1){
                cnt[2*i] += (cnt[i]/2);
                cnt[i] = 1;
            }else{
                cnt[2*i] += (cnt[i]/2) - 1;
                cnt[i] = 2;
            }
        }
        if(!cnt[i])continue;
        B |= (B<<i);
        if(cnt[i] == 2)B |= (B<<i);
    }
    if(B[k])cout<<k<<" ";
    else cout<<k + 1<<" ";
    if(k <= tmp)cout<<2*k<<endl;
    else cout<<min(n, k + tmp)<<endl;
}