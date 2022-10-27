#include <bits/stdc++.h>

using namespace std;

int n,m,k;
pair<pair<int,int>, int> arr[300005];
int tree[6000005][2], val[6000005], root[300005];
int ptr;

bool cmp(pair<pair<int,int>, int> &a, pair<pair<int,int>, int> &b){
    return a.first.first < b.first.first;
}

void buildTree(int v, int l, int r){
    if(l == r){
        val[v] = 1e9 + 5;
        tree[v][0] = 0;
        tree[v][1] = 0;
        return;
    }
    int mid = (l+r)/2;
    tree[v][0] = ptr++;
    buildTree(tree[v][0], l, mid);
    tree[v][1] = ptr++;
    buildTree(tree[v][1], mid+1, r);
    val[v] = 1e9 + 5;
}

int update(int v, int l, int r, int index, int x){
    if(l == r){
        val[ptr] = min(val[v], x);
        tree[ptr][0] = 0;
        tree[ptr][1] = 0;
        ptr++;
        return ptr-1;
    }
    int mid = (l+r)/2;
    int nv = ptr++;
    tree[nv][0] = tree[v][0];
    tree[nv][1] = tree[v][1];
    if(index <= mid)tree[nv][0] = update(tree[v][0], l, mid, index, x);
    else tree[nv][1] = update(tree[v][1], mid+1, r, index, x);
    val[nv] = max(val[tree[nv][0]], val[tree[nv][1]]);
    return nv;
}

int query(int v, int s, int e, int l, int r){
    if(l <= s && e <= r)return val[v];
    if(e < l || r < s)return 0;
    int mid = (s+e)/2;
    return max(query(tree[v][0], s, mid, l, r), query(tree[v][1], mid+1, e, l, r));
}

int binarySearch(int x){
    if(x > arr[k].first.first)return -1;
    int l = 1, r = k;
    while(l < r){
        int mid = (l+r)/2;
        if(x <= arr[mid].first.first){
            r = mid;
        }else{
            l = mid + 1;
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

    cin>>n>>m>>k;
    for(int i = 1; i <= k; i++){
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
    }
    sort(arr+1, arr+k+1, cmp);
    root[k+1] = 1;
    ptr = 2;
    tree[0][0] = tree[0][1] = 0;
    val[0] = 1e9 + 5;
    buildTree(1,1,n);
    for(int i = k; i > 0; i--){
        root[i] = update(root[i+1], 1, n, arr[i].second, arr[i].first.second);
    }
    int a, b, x, y;
    while(m--){
        cin>>a>>b>>x>>y;
        int pos = binarySearch(x);
        if(pos == -1){
            cout<<"no"<<endl;
        }else{
            int z = query(root[pos], 1, n, a, b);
            if(z <= y){
                cout<<"yes"<<endl;
            }else{
                cout<<"no"<<endl;
            }
        }
        fflush(stdout);
    }
}