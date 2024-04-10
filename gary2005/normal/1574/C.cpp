/**
 *    author:  gary
 *    created: 20.09.2021 22:34:38
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
const int MAXN=2e5+1;
LL a[MAXN];
int n,m;
int main(){
    cin>>n;
    rb(i,1,n) scanf("%lld",&a[i]);
    cin>>m;
    LL sum=0;
    rb(i,1,n) sum+=a[i];
    sort(a+1,a+1+n);
    rb(i,1,m){
        LL x,y;
        scanf("%lld%lld",&x,&y);
        LL l=0,r=max(0ll,y-(sum-a[1]))+max(0ll,x-a[1]);
        while(l<r){
            LL mid=(l+r)>>1;
            bool ok;
            ok=((sum+mid-y)>=x);
            if(ok){
                LL L,R;
                L=x;
                R=sum+mid-y;
                LL mn,mx;
                mn=L-mid;
                mx=R;
                ok=lower_bound(a+1,a+1+n,mn)!=upper_bound(a+1,a+1+n,mx);
            }
            if(ok){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        printf("%lld\n",l);
    }
    return 0;
}