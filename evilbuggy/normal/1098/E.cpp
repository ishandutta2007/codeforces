#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll floorSum(ll a, ll b, ll c, ll n){
    if(n == 0){
        return 0;
    }
    if(a < 0){
        return floorSum(-a, a*(n+1) + b, c, n);
    }
    if(b < 0){
        return floorSum(a, c + b%c, c, n) + n*(b/c) - n;
    }
    if(a >= c || b >= c){
        return floorSum(a%c, b%c, c, n) + (a/c)*n*(n+1)/2 + (b/c)*n;
    }
    ll m = (a*n + b)/c;
    return m*n - floorSum(c, -b-1, a, m);
}

int n, a[50005];
ll cnt[100005];

void getGcdArr(){
    map<int,int> arr[2];
    int flg = 0;
    for(int i = 1; i <= n; i++){
        arr[flg].clear();
        for(auto x : arr[flg^1]){
            int tmp = __gcd(x.first, a[i]);
            arr[flg][tmp] += x.second;
            cnt[tmp] += x.second;
        }
        arr[flg][a[i]]++;
        cnt[a[i]]++;
        flg ^= 1;
    }
}

ll compute(ll r, ll maxi){
    if(maxi >= r*cnt[r])return cnt[r]*(cnt[r] + 1)/2;
    ll k = maxi/r;
    return k*(k+1)/2 + (cnt[r] - k)*k;
}

ll count(ll maxi){
    ll totCount = 0;
    ll totSum = 0;
    ll ret = 0;
    for(ll r = 1, l = 1; r <= 100000; r++){
        if(r > maxi)break;
        totSum += (r-1)*cnt[r-1];
        totCount += cnt[r-1];
        if(!cnt[r])continue;
        ret += compute(r, maxi);
        ll k = 1;
        while(k <= cnt[r]){
            while(totSum + k*r > maxi && l < r){
                totSum -= l*cnt[l];
                totCount -= cnt[l];
                l++;
            }
            ll x = r, y = l-1;
            if(totSum == 0){
                if(cnt[y] == 0)break;
                if(y + x*k > maxi)break;
                ll lim = min((maxi/x), cnt[x]);
                ret += floorSum(-r, maxi, y, lim);
                ret -= floorSum(-r, maxi, y, k-1);
                break;
            }
            ll lim = min(((maxi - totSum)/x), cnt[x]);
            ret += (lim - k + 1)*totCount;
            if(!y){
                k = lim + 1;
                continue;
            }
            ret += floorSum(-r, maxi - totSum, y, lim);
            ret -= floorSum(-r, maxi - totSum, y, k-1);
            k = lim + 1;
        }
    }
    return ret;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    memset(cnt, 0, sizeof(cnt));
    getGcdArr();
    ll totCount = 1LL*n*(n+1)/2;
    totCount = totCount*(totCount + 1)/2;
    ll req = (totCount + 1)/2;
    ll left = 1, right = 0;
    for(int i = 1; i <= 100000; i++){
        right += 1LL*i*cnt[i];
    }
    while(left < right){
        ll mid = (right + left)/2;
        ll tmp = count(mid);
        // cout<<mid<<" "<<tmp<<endl;
        if(tmp < req){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    cout<<left<<endl;
}