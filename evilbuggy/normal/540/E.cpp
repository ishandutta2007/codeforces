#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

map<int,int> pos;
map<int,int> cnt;
int f[200005];
pair<int,int> arr[200005];

void update(int i, int x, int n){
    while(i <= n){
        f[i] += x;
        i += i&(-i);
    }
}

int query(int i){
    int ans = 0;
    while(i > 0){
        ans += f[i];
        i &= (i-1);
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

    int n, a, b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(pos.find(a) == pos.end()){
            pos[a] = a;
        }
        if(pos.find(b) == pos.end()){
            pos[b] = b;
        }
        swap(pos[a], pos[b]);
    }
    int sum = 0, prev = 0;
    for(auto x : pos){
        sum += x.first - prev - 1;
        cnt[x.first] = sum;
        prev = x.first;
    }
    ll ans = 0;
    int ptr = 1;
    for(auto x : pos){
        ans += abs(cnt[x.first] - cnt[x.second]);
        arr[ptr] = {x.second, ptr};
        ptr++;
    }
    sort(arr + 1, arr + ptr);
    for(int i = 1; i < ptr; i++){
        ans += query(ptr) - query(arr[i].second);
        update(arr[i].second, 1, ptr);
    }
    cout<<ans<<endl;
}