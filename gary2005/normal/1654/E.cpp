/**
 *    author:  gary
 *    created: 20.03.2022 19:29:15
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
int cnt[100000000],a[100000+10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int B=ceil(sqrt(100000));
    rb(i,1,n) cin>>a[i];
    int ans=1;
    rb(k,-B,B){
        rb(i,1,n){
            cnt[a[i]-i*k+50000000]++;
        }
        rb(i,1,n){
            check_max(ans,cnt[a[i]-i*k+50000000]);
            cnt[a[i]-i*k+50000000]=0;
        }
    }
    rb(i,1,n){
        rb(j,i+1,min(n,i+B)){
            if(abs(a[j]-a[i])%(j-i)==0){
                cnt[(a[j]-a[i])/(j-i)+50000000]++;
            }
        }
        rb(j,i+1,min(n,i+B)){
            if(abs(a[j]-a[i])%(j-i)==0){
                check_max(ans,cnt[(a[j]-a[i])/(j-i)+50000000]+1);
                cnt[(a[j]-a[i])/(j-i)+50000000]=0;
            }
        }
    }
    cout<<n-ans<<endl;
    return 0;
}