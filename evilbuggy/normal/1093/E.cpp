#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set st[200005];
int n, a[200005], b[200005], pa[200005], pb[200005];

void remove(int ind, int v){
    while(ind <= n){
        st[ind].erase(v);
        ind += ind&(-ind);
    }
}

void add(int ind, int v){
    while(ind <= n){
        st[ind].insert(v);
        ind += ind&(-ind);
    }
}

int query(int ind, int l, int r){
    int ans = 0;
    while(ind > 0){
        ans += st[ind].order_of_key(r+1) - st[ind].order_of_key(l);
        ind &= (ind - 1);
    }
    return ans;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        pa[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cin>>b[i];
        pb[b[i]] = i;
        add(pa[b[i]], i);
    }
    int type, la, ra, lb, rb, x, y;
    while(q--){
        cin>>type;
        if(type == 1){
            cin>>la>>ra>>lb>>rb;
            cout<<query(ra, lb, rb) - query(la-1, lb, rb)<<endl;
        }else{
            cin>>x>>y;
            remove(pa[b[x]], x);
            remove(pa[b[y]], y);
            add(pa[b[x]], y);
            add(pa[b[y]], x);
            swap(b[x], b[y]);
        }
    }
}