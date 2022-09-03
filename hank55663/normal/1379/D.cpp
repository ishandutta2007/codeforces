#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > q[100005];
#define mp make_pair
#define x first
#define pb push_back
#define y second
#define LL long long
#define pii pair<int,int>
int S[1000005];
void add(int x,int k){
    for(int i = x;i<1000005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
void solve(){
    int n,h,m,k;
    scanf("%d %d %d %d",&n,&h,&m,&k);
    map<int,int> y;
    pii p[100005];
    for(int i = 0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
      //  cnt[b]++;
        p[i]=mp(a,b);
        y[b];
        y[(b+k)%m];
        y[(b-k+m)%m];
        y[b+m];
        y[(b+k)%m+m];
        y[(b-k+m)%m+m];
    }
    y[2*m];
    int index=0;
    for(auto& it:y){
        it.y=++index;
    }
    for(int i = 0;i<n;i++){
        add(y[p[i].y],1);
        add(y[p[i].y+m],1);
    }
    int ans=1e9,ansi;
    for(auto it:y){
        //if(it.x<m/2){
        if(it.x>=m)break;
        int l=it.y+1;
        int r=y.lower_bound(it.x+k)->y-1;
        int l2=y.upper_bound(it.x+m/2)->y;
        int r2=y.lower_bound(it.x+k+m/2)->y-1;
        int sum=query(r)-query(l-1)+query(r2)-query(l2-1);
        if(sum<ans){
            ans=sum;
            ansi=(it.x+k)%m;
        }
    }
    printf("%d %d\n",ans,ansi%(m/2));
    ansi=(ansi-k+m)%m;
    int cnt=0;
    for(int i = 0;i<n;i++){
        if(((p[i].y-ansi)%(m/2)+m/2)%(m/2)<k&&((p[i].y-ansi)%(m/2)+m/2)%(m/2)!=0){
            printf("%d ",i+1);
            cnt++;
        }
    }
    assert(ans==cnt);
    printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}