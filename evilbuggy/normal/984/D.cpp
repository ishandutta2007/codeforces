#include <bits/stdc++.h>

using namespace std;

int n, vis[25000005], maxi[25000005], tree[25000005], arr[5005];

int findNode(int l, int r){
    return (n-r+l)*(n-r+l-1)/2 + l;
}

void buildTree(int l, int r){
    int v = findNode(l, r);
    if(vis[v] == 1)return;
    vis[v] = 1;
    if(l == r){
        maxi[v] = arr[l];
        tree[v] = arr[l];
        return;
    }
    buildTree(l, r-1);
    buildTree(l+1, r);
    int v1 = findNode(l, r-1), v2 = findNode(l+1, r);
    tree[v] = tree[v1]^tree[v2];
    maxi[v] = max(tree[v], max(maxi[v1], maxi[v2]));
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    int q,l,r, mm = n*(n+1)/2;
    for(int i = 1; i <= mm; i++){
        vis[i] = 0;
    }
    buildTree(1, n);
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &l, &r);
        mm = findNode(l,r);
        printf("%d\n", maxi[mm]);
    }
}