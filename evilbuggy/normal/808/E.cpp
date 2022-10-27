#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 100005;

int a[maxn], b[maxn], c[maxn];
ll sa[maxn], sb[maxn], sc[maxn];

ll search(int m){
    int l = 0, r = min(m/2, maxn-1);
    while(l < r){
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        ll tmp1 = sb[mid1] + sa[min(m-2*mid1, maxn - 1)];
        ll tmp2 = sb[mid2] + sa[min(m-2*mid2, maxn - 1)];
        if(tmp1 < tmp2){
            l = mid1 + 1;
        }else if(tmp1 > tmp2){
            r = mid2 - 1;
        }else{
            return tmp1;
        }
    }
    return sb[l] + sa[min(m-2*l, maxn - 1)];
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int pa = 0, pb = 0, pc = 0;
    int n, m;
    cin>>n>>m;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; i++){
        int x, y;
        cin>>x>>y;
        if(x == 1){
            pa++;
            a[pa] = y;
        }else if(x == 2){
            pb++;
            b[pb] = y;
        }else if(x == 3){
            pc++;
            c[pc] = y;
        }
    }
    sort(a + 1, a + pa + 1, greater<int>());
    sort(b + 1, b + pb + 1, greater<int>());
    sort(c + 1, c + pc + 1, greater<int>());
    sa[0] = sb[0] = sc[0] = 0;
    for(int i = 1; i < maxn; i++){
        sa[i] = sa[i-1] + a[i];
        sb[i] = sb[i-1] + b[i];
        sc[i] = sc[i-1] + c[i];
    }
    ll ans = 0;
    for(int i = 0; i < maxn; i++){
        if(3*i > m)break;
        ans = max(ans, sc[i] + search(m - 3*i));
    }
    cout<<ans<<endl;
}