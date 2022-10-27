#include <bits/stdc++.h>

using namespace std;

int f[100005];

void update(int i, int x, int n){
    while(i <= n){
        f[i] += x;
        i += (i&(-i));
    }
}

int query(int i){
    long long int ans = 0;
    while(i > 0){
        ans += f[i];
        i &= (i-1);
    }
    return ans;
}

long long int psum[100005], v[100005], t[100005], temp[100005];
int n;

int binarySearch(int i){
    int l = i, r = n;
    if(v[i] < t[i]-t[i-1])return i-1;
    while(l < r){
        int m = l + (r-l+1)/2;
        if(t[m] - t[i-1] <= v[i]){
            l = m;
        }else{
            r = m-1;
        }
    }
    return l;
}

int main(){
    memset(f, 0, sizeof(f));
    memset(psum, 0, sizeof(psum));
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>v[i];
    }
    t[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>t[i];
        temp[i] = t[i];
        t[i] += t[i-1];
    }
    for(int i = 1; i <= n; i++){
        int ind = binarySearch(i);
        update(i,1,n);
        update(ind+1,-1,n);
        psum[ind+1] += v[i] - (t[ind] - t[i-1]);
    }
    for(int i = 1; i <= n; i++){
        int m = query(i);
        long long int ans = temp[i]*m + psum[i];
        cout<<ans<<" ";
    }
}