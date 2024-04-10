/**
 *    author:  gary
 *    created: 28.10.2021 16:24:45
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
const int MAXN=5e2+1;
int a[MAXN],n;
const int B=4e4;
LL check(int x){
    LL ans=0;
    rb(i,1,n){
        int A,B;
        A=a[i]/x;
        B=a[i]%x;
        if(B>A) return 1e18;
        B=A-B;
        ans+=A;
        ans-=B/(x+1);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    LL ans=1e18;
    rb(i,1,B) check_min(ans,check(i));
    rb(i,1,min(B,a[1])){
        if(a[1]%i==0){
            check_min(ans,check(a[1]/i));
            if(a[1]/i-1) check_min(ans,check(a[1]/i-1));
        }
        else{
            check_min(ans,check(a[1]/i));
        }
    }
    cout<<ans<<endl;
    return 0;
}