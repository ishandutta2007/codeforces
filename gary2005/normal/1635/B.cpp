/**
 *    author:  gary
 *    created: 20.02.2022 22:31:21
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n,a[200000+20],b[200000+20];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        rb(i,1,n) cin>>a[i],b[i]=a[i];
        b[n+1]=1000000000;
        rb(i,2,n-1){
            if(b[i]>b[i-1]&&b[i]>b[i+1]){
                b[i+1]=max(b[i],b[i+2]);
            }
        }
        int ans=0;
        rb(i,1,n) ans+=a[i]!=b[i];
        cout<<ans<<endl;
        rb(i,1,n) cout<<b[i]<<" ";
        cout<<endl;
    }
    return 0;
}