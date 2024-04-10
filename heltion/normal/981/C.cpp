#include<bits/stdc++.h>
#define maxn 200000
int d[maxn];
int main(){
    int n, u, vv, c = 0, r;
    scanf("%d", &n);
    for(int i = 1; i < n; i += 1){
        scanf("%d %d", &u, &vv);
        d[u] += 1, d[vv] += 1;
    }
    std::vector<int> v;
    for(int i = 1; i <= n; i += 1){
        if(d[i] > 2) c += 1, r = i;
        if(d[i] == 1) v.push_back(i);
    }
    if(c >= 2) printf("No");
    if(c == 1){
        printf("Yes\n%d\n", v.size());
        for(int k : v) printf("%d %d\n", r, k);
    }
    if(c == 0){
        printf("Yes\n1\n");
        printf("%d %d", v[0], v[1]);
    }
}