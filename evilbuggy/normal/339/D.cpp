#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll a[(1<<18)], tree[(1<<19)];

void build(int v, int l, int r, int n){
    if(l == r){
        tree[v] = a[l];
        return;
    }
    int m = (l+r)>>1;
    build(2*v, l, m, n-1);
    build(2*v+1, m+1, r, n-1);
    if(n%2 == 1){
        tree[v] = tree[2*v]|tree[2*v+1];
    }else{
        tree[v] = tree[2*v]^tree[2*v+1];
    }
}

void update(int v, int l, int r, int ind, int n){
    if(l == r){
        tree[v] = a[l];
        return;
    }
    int m = (l+r)>>1;
    if(ind <= m)update(2*v, l, m, ind, n-1);
    else update(2*v+1, m+1, r, ind, n-1);
    if(n%2 == 1){
        tree[v] = tree[2*v]|tree[2*v+1];
    }else{
        tree[v] = tree[2*v]^tree[2*v+1];
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= (1<<n); i++){
        cin>>a[i];
    }
    build(1,1,(1<<n), n);
    int p, b;
    while(m--){
        cin>>p>>b;
        a[p] = b;
        update(1,1,(1<<n),p,n);
        cout<<tree[1]<<endl;
    }
}