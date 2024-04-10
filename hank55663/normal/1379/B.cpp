#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > q[100005];
#define mp make_pair
#define x first
#define pb push_back
#define y second
#define LL long long
void solve(){
    int l,r;
    LL m;
    scanf("%d %d %lld",&l,&r,&m);
    int d=r-l;
    for(int i = l;i<=r;i++){
        LL ll=max(m-(r-l),1ll),rr=m+(r-l);
        if(rr/i!=ll/i||ll%i==0){
            rr/=i;
            rr*=i;
           // printf("%d\n",rr);
            if(rr>m)
            printf("%d %lld %lld\n",i,r-(rr-m),r);
            else{
            printf("%d %lld %lld\n",i,r,r-(m-rr));
            }
            return ;
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}