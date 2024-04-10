#include <bits/stdc++.h>

using namespace std;

long double a[100005], tree[600005], pl[600005], sl[600005];

void buildTree(int v, int l, int r){
    pl[v] = 1, sl[v] = 0;
    if(l == r){
        tree[v] = a[l];
    }else{
        int m = (l+r)/2;
        buildTree(2*v, l, m);
        buildTree(2*v + 1, m + 1, r);
        tree[v] = tree[2*v] + tree[2*v + 1];
    }
}

void charge(int v, double x, double y){
    pl[v] *= x;
    sl[v] *= x;
    sl[v] += y;
}

void discharge(int v, int sz){
    tree[v] *= pl[v];
    tree[v] += sz*sl[v];
    if(sz != 1){
        charge(2*v, pl[v], sl[v]);
        charge(2*v + 1, pl[v], sl[v]);
    }
    pl[v] = 1, sl[v] = 0;
}

void update(int v, int s, int e, int l, int r, double x, double y){
    discharge(v, e-s+1);
    if(e < l || r < s)return;
    if(l <= s && e <= r){
        charge(v, x, y);
        discharge(v, e-s+1);
        return;
    }
    int m = (s+e)/2;
    update(2*v, s, m, l, r, x, y);
    update(2*v + 1, m+1, e, l, r, x, y);
    tree[v] = tree[2*v] + tree[2*v + 1];
}

long double query(int v, int s, int e, int l, int r){
    discharge(v, e-s+1);
    if(e < l || r < s)return 0.0;
    if(l <= s && e <= r)return tree[v];
    int m = (s+e)/2;
    return query(2*v, s, m, l, r) + query(2*v + 1, m+1, e, l, r);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    buildTree(1,1,n);
    int type, l1, r1, l2, r2;
    while(q--){
        cin>>type;
        if(type == 1){
            cin>>l1>>r1>>l2>>r2;
            long double s1 = query(1,1,n,l1,r1)/(r1 - l1 + 1);
            long double s2 = query(1,1,n,l2,r2)/(r2 - l2 + 1);
            update(1,1,n,l1,r1,double(r1 - l1)/(r1 - l1 + 1), s2/(r1 - l1 + 1));
            update(1,1,n,l2,r2,double(r2 - l2)/(r2 - l2 + 1), s1/(r2 - l2 + 1));
        }else{
            cin>>l1>>r1;
            cout<<setprecision(30)<<query(1,1,n,l1,r1)<<endl;
        }
    }
}