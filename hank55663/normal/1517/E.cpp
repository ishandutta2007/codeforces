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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MAXK 2500
int vis[25];
int a[200005];
LL ans2;
void dfs(int x,int n){
    if(x==n){
        int ok=1;
        vector<int> v1,v2;
        for(int i = 0;i<n;i++){
            if(!vis[i])v1.pb(i);
            else v2.pb(i);
        }
        for(int i = 1;i+1<v1.size();i++){
            if(v1[i+1]-v1[i]<v1[i]-v1[i-1])ok=0;
        }
        for(int i = 1;i+1<v2.size();i++){
            if(v2[i+1]-v2[i]>v2[i]-v2[i-1])ok=0;
        }
        if(ok){
            LL sum1=0,sum2=0;
            for(int j = 0;j<n;j++){
                if(vis[j]==0)sum1+=a[j+1];
                else sum2+=a[j+1];//
            }//printf("%d ",vis[j]);
            //printf("\n");
            if(sum1<sum2){
               // for(int j =0;j<n;j++){
                 //   printf("%d ",vis[j]);
               // }
                //printf("\n");
                ans2++;
            }
        }
        return;
    }
    vis[x]=1;
    dfs(x+1,n);
    vis[x]=0;
    dfs(x+1,n);
}
int mod=998244353;
LL pre[200005];
LL pre2[200005];
void solve(){
    int n=20;
    scanf("%d",&n);
   ans2=0;
   // int a[200005];
    for(int i = 1;i<=n;i++){
        //a[i]=rand()%10+1;
        //printf("%d ",a[i]);
        scanf("%d",&a[i]);
        pre[i]=pre[i-1]+a[i];
        if(i!=1)
        pre2[i]=pre2[i-2]+a[i];
    }
    //printf("\n");
    // dfs(0,n);
    LL ans=0;
    for(int i = 1;i<=n;i++){
        if(pre[i]>pre[n]-pre[i])ans++;
    }
    vector<int> odd,even;
    for(int i = 1;i<=n;i++){
        if(i&1)odd.pb(i);
        else even.pb(i);
    }
    //   printf("%lld\n",ans%mod);
    for(int i = 1;i<n;i++){
        if(i%2==1){
            if(pre[i]<pre[n]-pre[i]){
                ans+=i/2+1;
            }
            else{
            int Min=-1,Max=i/2;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(pre[even[mid]-1]+pre2[i]-pre2[even[mid]-1]<pre[n]-pre[i]+pre2[i-1]-pre2[even[mid]-2]){
                    Min=mid;
                }
                else{
                    Max=mid;
                }
            }
            ans+=Min+1;
            }
        }
        else{
            if(pre[i]<pre[n]-pre[i]){
                ans+=i/2;
            }
            else{
            int Min=0,Max=i/2;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(pre[odd[mid]-1]+pre2[i]-pre2[odd[mid]-1]<pre[n]-pre[i]+pre2[i-1]-pre2[odd[mid]-2]){
                    Min=mid;
                }
                else{
                    Max=mid;
                }
            }
            ans+=Min;
            }
        }
    }
   //  printf("%lld\n",ans%mod);
    for(int i = 1;i<n-1;i++){
        if(i%2==1){
            if(pre[i]+a[n]<pre[n-1]-pre[i]){
                ans+=i/2+1;
            }
            else{
            int Min=-1,Max=i/2;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(pre[even[mid]-1]+pre2[i]-pre2[even[mid]-1]+a[n]<pre[n-1]-pre[i]+pre2[i-1]-pre2[even[mid]-2]){
                    Min=mid;
                }
                else{
                    Max=mid;
                }
            }
            ans+=Min+1;
            }
        }
        else{
            if(pre[i]+a[n]<pre[n-1]-pre[i]){
                ans+=i/2;
            }
            else{
            int Min=0,Max=i/2;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(pre[odd[mid]-1]+pre2[i]-pre2[odd[mid]-1]+a[n]<pre[n-1]-pre[i]+pre2[i-1]-pre2[odd[mid]-2]){
                    Min=mid;
                }
                else{
                    Max=mid;
                }
            }
            
            ans+=Min;
            }
        }
    }
  //   printf("%lld\n",ans%mod);
     for(int i = 2;i<n;i++){
        if(i%2==1){
            if(pre[i]-pre[1]<pre[n]-pre[i]+a[1]){
                ans+=i/2;
            }
            else{
            int Min=0,Max=i/2;
           //  printf("%d %d\n",Min,Max);
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(pre[even[mid]-1]+pre2[i]-pre2[even[mid]-1]-a[1]<a[1]+pre[n]-pre[i]+pre2[i-1]-pre2[even[mid]-2]){
                    Min=mid;
                }
                else{
                    Max=mid;
                }
            }
           // printf("%d %d\n",Min,Max);
            
            ans+=Min;
            }
        }
        else{
            if(pre[i]-pre[1]<pre[n]-pre[i]+a[1]){
                ans+=i/2;
            }
            else{
            int Min=0,Max=i/2;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(pre[odd[mid]-1]+pre2[i]-pre2[odd[mid]-1]-a[1]<a[1]+pre[n]-pre[i]+pre2[i-1]-pre2[odd[mid]-2]){
                    Min=mid;
                }
                else{
                    Max=mid;
                }
            }
            ans+=Min;
            }
        } //printf("%d %lld\n",i,ans%mod);
    }
   //  printf("%lld\n",ans%mod);
    for(int i = 2;i<n-1;i++){
        if(i%2==1){
            if(pre[i]+a[n]-a[1]<pre[n-1]-pre[i]+a[1]){
                ans+=i/2;
            }
            else{
            int Min=0,Max=i/2;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(pre[even[mid]-1]+pre2[i]-pre2[even[mid]-1]+a[n]-a[1]<a[1]+pre[n-1]-pre[i]+pre2[i-1]-pre2[even[mid]-2]){
                    Min=mid;
                }
                else{
                    Max=mid;
                }
            }
            ans+=Min;
            }
        }
        else{
            if(pre[i]+a[n]-a[1]<pre[n-1]-pre[i]+a[1]){
                ans+=i/2;
            }
            else{
            int Min=0,Max=i/2;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(pre[odd[mid]-1]+pre2[i]-pre2[odd[mid]-1]+a[n]-a[1]<a[1]+pre[n-1]-pre[i]+pre2[i-1]-pre2[odd[mid]-2]){
                    Min=mid;
                }
                else{
                    Max=mid;
                }
            }
            ans+=Min;
            }
        }
      //  printf("%d %lld\n",i,ans%mod);
    }
    printf("%lld\n",ans%mod);
    //printf("%lld\n",ans2%mod);
   // assert(ans==ans2);
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101


PPPPP
PPPPC
PPPCC

CPPPP
CCPPP
CPCPP

CPPPC

PCPPP
PCPCP

PCPPC
*/