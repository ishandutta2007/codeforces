/**
 *    author:  gary
 *    created: 14.11.2021 14:01:22
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
#define ff fflush(stdout)
LL query(int l,int r){ 
    cout<<"? "<<l<<" "<<r<<endl;
    ff;
    LL x;
    cin>>x;
    return x;
}
int puzzle(LL x){
    int l=2,r=1e9;
    while(l<r){
        int mid=(l+r)>>1;
        if(1ll*mid*(mid-1)/2<x) l=mid+1;
        else r=mid;
    }
    return l;
}
void answer(int i,int j,int k){
    cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
    ff;
}
void solve(){
    int n;
    cin>>n;
    LL tot=query(1,n);
    int l=1,r=n+1;
    while(l<r-1){
        int mid=(l+r)>>1;
        if(query(1,mid)==0) l=mid;
        else r=mid;
    }
    LL ano=query(l+1,n);
    int len1=tot-ano+1;
    LL rp=tot-1ll*len1*(len1-1)/2;
    int len2=puzzle(rp);
    answer(l,l+len1,l+len1+len2-1);
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}