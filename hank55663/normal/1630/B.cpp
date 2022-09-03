#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cnt[200005];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    fill(cnt,cnt+n+1,0);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<n;i++){
        cnt[a[i]]++;
    }
    int x=1,y=n;
    int r=0;
    int tot=0;
    for(int i = 1;i<=n;i++){
        while(tot-(n-tot)<k&&r!=n){
            r++;
            tot+=cnt[r];
        }
        if(tot-(n-tot)>=k){
            if(y-x>r-i){
                x=i,y=r;
            }
        }
        tot-=cnt[i];
    }
    printf("%d %d\n",x,y);
    int now=0,cnt=0;
    vector<pii> v;
    int l=0;
    for(int i = 0;i<n;i++){
        if(a[i]>=x&&a[i]<=y){
            now++;
        }
        else{
            now--;
        }
       // printf("%d %d\n",now,cnt);
        if(now>cnt&&cnt!=k-1){
            cnt=now;
            v.pb(mp(l,i));
            l=i+1;
        }
    }
    v.pb(mp(l,n-1));
    for(auto it:v)printf("%d %d\n",it.x+1,it.y+1);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y

36
0123
0123 4567
*/