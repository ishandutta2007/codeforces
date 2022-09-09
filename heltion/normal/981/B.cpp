#include<bits/stdc++.h>
struct node{
    int a, x;
    bool operator < (const node &rhs){
        return a == rhs.a ? x > rhs.x :  a < rhs.a;
    }
};
int main(){
    int n, a, x;
    long long ans = 0;
    std::vector<node> v;
    scanf("%d", &n);
    for(int i = 0; i < n; i += 1){
        scanf("%d %d", &a, &x);
        v.push_back((node){a, x});
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i += 1){
        scanf("%d %d", &a, &x);
        v.push_back((node){a, x});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i += 1)
        if(i == 0 or v[i].a != v[i - 1].a)
            ans += v[i].x;
    printf("%lld", ans);
}