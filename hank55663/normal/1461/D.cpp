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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int cnt[1000005];
LL pre[1000005];
set<LL> s;
void dc(int l,int r){
   // printf("%d %d %lld\n",l,r,pre[r]-pre[l-1]);
    s.insert(pre[r]-pre[l-1]);
    if(l==r)return;
    int mid=(l+r)/2;
    int rr=mid;
    while(cnt[rr]==0)rr--;
    int ll=mid+1;
    while(cnt[ll]==0)ll++;
    dc(l,rr);
    dc(ll,r);
}
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    int a[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    sort(a,a+n);
    for(int i = 1;i<=1000000;i++){
        pre[i]=cnt[i]*1ll*i+pre[i-1];
    }
    dc(a[0],a[n-1]);
    while(q--){
        int x;
        scanf("%d",&x);
        if(s.find(x)!=s.end()){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    s.clear();
    for(int i = 0;i<n;i++){
        cnt[a[i]]--;
    }
}
int main(){
    int t=1;   scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}