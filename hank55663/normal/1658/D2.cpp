#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
#define MXN 200005
int mod=998244353;
int tot[200005];
void solve(){
    int l,r;
    scanf("%d %d",&l,&r);
    int cnt[20],cnt2[20];
    MEM(cnt);
    for(int i = l;i<=r;i++){
        for(int j= 0;j<20;j++){
            if(i&(1<<j)){
                cnt[j]++;
            }
        }
    }
    MEM(cnt2);
    vector<int> v;
    for(int i = l;i<=r;i++){
        int x=i;
        scanf("%d",&x);
        v.pb(x);
        for(int j  =0;j<20;j++){
            if(x&(1<<j)){
                cnt2[j]++;
            }
        }
    }
    LL ans=0,mask=0;;
    for(int i = 0;i<20;i++){
        mask+=(1<<i);
        if(cnt[i]==cnt2[i]){
            if((r-l+1)%2==0&&cnt[i]==(r-l+1)/2)mask-=(1<<i);
        }
        else ans+=(1<<i);
        //printf("%d %d\n",cnt[i],cnt2)
    }
    random_shuffle(v.begin(),v.end());
    for(int i = 0;i<200&&i+1<v.size();i++){
        for(int j = l;j<=r;j++){
            if(((v[i]^j)&mask)==ans){
                tot[(v[i]^j)]++;
            }
        }
    }
    int Next=min(200,(int)v.size()-1);
  //  int tot=0;
    for(int j=l;j<=r;j++){
       
        if(((v[Next]^j)&mask)==ans){
            if(tot[v[Next]^j]==Next){
                int ok=1;
                for(auto it:v){
                    int val=v[Next]^j^it;
                    if(val>=l&&val<=r){
                        
                    }
                    else{
                        ok=0;
                    }
                }
                if(ok){
                printf("%d\n",v[Next]^j);
                break;
                }
              //  tot++;
            }
        }
         
    }
    //assert(tot<=1);
    for(int i = 0;i<=Next;i++){
        for(int j=l;j<=r;j++){
            tot[v[i]^j]=0;
        }
    }
}  
 
 
int main(){
    int t=1;0000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
 
*/