/**
 *    author:  gary
 *    created: 02.08.2022 08:58:25
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int a[202];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    rb(i,1,n<<1) cin>>a[i];
    int ans=0;
    rb(i,1,2*n){
        int j=i+1;
        while (a[j]!=a[i]){
            j++;
        }
        while (j>i+1){
            ans++;
            swap(a[j],a[j-1]);
            --j;
        }
        // rb(k,1,n<<1) cout<<a[k]<<" ";
        // cout<<endl;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}