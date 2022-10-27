#include <bits/stdc++.h>
using namespace std;

int maxt[(1<<5)][600005], mint[(1<<5)][600005];
int a[5][200005];
int n, k;

int compute(int ind, int mask){
    int ans = 0;
    for(int i = 0; i < k; i++){
        if(mask&(1<<i)){
            ans += a[i][ind];
        }else{
            ans -= a[i][ind];
        }
    }
    return ans;
}

void build(int mask, int v, int l, int r){
    if(l == r){
        mint[mask][v] = maxt[mask][v] = compute(l, mask);
        return;
    }
    int m = (l+r)/2;
    build(mask, 2*v, l, m);
    build(mask, 2*v+1, m+1, r);
    maxt[mask][v] = max(maxt[mask][2*v], maxt[mask][2*v+1]);
    mint[mask][v] = min(mint[mask][2*v], mint[mask][2*v+1]);
}

void update(int mask, int v, int l, int r, int ind){
    if(l == r){
        mint[mask][v] = maxt[mask][v] = compute(ind, mask);
        return;
    }
    int m = (l+r)/2;
    if(ind <= m)update(mask, 2*v, l, m, ind);
    else update(mask, 2*v+1, m+1, r, ind);
    maxt[mask][v] = max(maxt[mask][2*v], maxt[mask][2*v+1]);
    mint[mask][v] = min(mint[mask][2*v], mint[mask][2*v+1]);
}

pair<int,int> query(int mask, int v, int s, int e, int l, int r){
    if(l <= s && e <= r)return make_pair(maxt[mask][v], mint[mask][v]);
    int m = (s+e)/2;
    if(r <= m)return query(mask, 2*v, s, m, l, r);
    if(l >= m+1)return query(mask, 2*v+1, m+1, e, l, r);
    pair<int,int> q1 = query(mask, 2*v, s, m, l, r);
    pair<int,int> q2 = query(mask, 2*v+1, m+1, e, l, r);
    return make_pair(max(q1.first, q2.first), min(q1.second, q2.second));
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            cin>>a[j][i];
        }
    }

    for(int mask = 0; mask < (1<<k); mask++){
        build(mask, 1, 1, n);
    }

    int q, type, ind, l, r;
    cin>>q;
    while(q--){
        cin>>type;
        if(type == 1){
            cin>>ind;
            for(int i = 0; i < k; i++){
                cin>>a[i][ind];
            }
            for(int mask = 0; mask < (1<<k); mask++){
                update(mask, 1, 1, n, ind);
            }
        }else{
            cin>>l>>r;
            pair<int,int> tmp = query(0, 1, 1, n, l, r);
            int ans = tmp.first - tmp.second;
            for(int mask = 1; mask < (1<<k); mask++){
                tmp = query(mask, 1, 1, n, l, r);
                ans = max(ans, tmp.first - tmp.second);
            }
            cout<<ans<<endl;
        }
    }

}