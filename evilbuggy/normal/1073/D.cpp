#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll a[200005];
ll tree[800005];
int rmv[800005];

void buildTree(int v, int l, int r){
    if(l == r){
        tree[v] = a[l];
        rmv[v] = 1;
        return;
    }
    int m = (l+r)/2;
    buildTree(2*v, l, m);
    buildTree(2*v + 1, m+1, r);
    tree[v] = tree[2*v] + tree[2*v+1];
    rmv[v] = rmv[2*v] + rmv[2*v+1];
}

pair<int, ll> query(int v, int s, int e, int l, int r){
    if(r < s || e < l)return make_pair(0,0);
    if(l <= s && e <= r)return make_pair(rmv[v], tree[v]);
    int m = (s+e)/2;
    pair<int,ll> t1 = query(2*v, s, m, l, r);
    pair<int,ll> t2 = query(2*v+1, m+1, e, l, r);
    return make_pair(t1.first + t2.first, t1.second + t2.second);
}

void update(int v, int l, int r, int i){
    if(l == r){
        tree[v] = 0;
        rmv[v] = 0;
        return;
    }
    int m = (l+r)/2;
    if(i <= m)update(2*v, l, m, i);
    else update(2*v+1, m+1, r, i);
    tree[v] = tree[2*v] + tree[2*v+1];
    rmv[v] = rmv[2*v] + rmv[2*v+1];
}

int binarySearch(ll t, int n){
    int l = 1, r = n;
    while(l < r){
        int m = l + (r-l)/2;
        pair<int,ll> tt = query(1,1,n,1,m);
        if(tt.second > t){
            r = m;
        }else{
            l = m+1;
        }
    }
    return l;
}

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll t;
    cin>>n>>t;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    ll ans = 0;
    buildTree(1,1,n);
    pair<int, ll> tmp;
    int removed = 0;
    while(removed < n){
        tmp = query(1,1,n,1,n);
        ans += (t/tmp.second)*tmp.first;
        t %= tmp.second;
        if(t == 0)break;
        int ind = binarySearch(t, n);
        tmp = query(1,1,n,1,ind);
        update(1,1,n,ind);
        removed++;
    }

    cout<<ans<<endl;
}