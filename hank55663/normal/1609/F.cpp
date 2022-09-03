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
LL a[1000005];
int val[1000005];
LL Min[1000005],Max[1000005];
LL vMin[1000005],vMax[1000005];
LL ans=0;
vector<int> ll[60],rr[60];
void dc(int l,int r){
    if(l==r){
        ans++;
        return;
    }
    int mid=(l+r)/2;
    dc(l,mid);
    dc(mid+1,r);
    int last=ans;
   // printf("%d\n",ans);
    Min[mid+1]=Max[mid+1]=a[mid+1];
    vMin[mid+1]=vMax[mid+1]=val[mid+1];
    for(int i = mid+2;i<=r;i++){
        Min[i]=min(Min[i-1],a[i]),Max[i]=max(Max[i-1],a[i]);
        if(Min[i]==Min[i-1])vMin[i]=vMin[i-1];
        else vMin[i]=val[i];
        if(Max[i]==Max[i-1])vMax[i]=vMax[i-1];
        else vMax[i]=val[i];
    }
    Min[mid]=Max[mid]=a[mid];
    vMin[mid]=vMax[mid]=val[mid];
    for(int i = mid-1;i>=l;i--){
        Min[i]=min(Min[i+1],a[i]),Max[i]=max(Max[i+1],a[i]);
        if(Min[i]==Min[i+1])vMin[i]=vMin[i+1];
        else vMin[i]=val[i];
        if(Max[i]==Max[i+1])vMax[i]=vMax[i+1];
        else vMax[i]=val[i];
    }
    int t=r;
    for(int i = l;i<=mid;i++){
        while(t>mid&&!(Min[t]>=Min[i]&&Max[t]<=Max[i]))t--;
        if(vMin[i]==vMax[i]){
            ans+=t-mid;
        }
    }
    t=l;
    for(int i = r;i>=mid-1;i--){
         while(t<=mid&&!(Min[t]>=Min[i]&&Max[t]<=Max[i]&&(Min[t]!=Min[i]||Max[t]!=Max[i])))t++;
        if(vMin[i]==vMax[i]){
            ans+=mid+1-t;
        }
    }
    for(int i = 0;i<60;i++)ll[i].clear(),rr[i].clear();
    for(int i = l;i<=mid;i++)ll[vMin[i]].pb(i);
    for(int i = mid+1;i<=r;i++)rr[vMax[i]].pb(i);

    for(int i = 0;i<60;i++){
        int l1=ll[i].size()-1,l2=ll[i].size();
        for(auto it:rr[i]){
            while(l2!=0&&Max[ll[i][l2-1]]<Max[it])l2--;
            while(l1!=-1&&Min[ll[i][l1]]>=Min[it])l1--;
              ans+=max(l1-l2+1,0);
        }
      
    }
    for(int i = 0;i<60;i++)ll[i].clear(),rr[i].clear();
    for(int i = l;i<=mid;i++)ll[vMax[i]].pb(i);
    for(int i = mid+1;i<=r;i++)rr[vMin[i]].pb(i);
    for(int i = 0;i<60;i++){
        int l1=ll[i].size()-1,l2=ll[i].size();
        for(auto it:rr[i]){
            while(l2!=0&&Min[ll[i][l2-1]]>Min[it])l2--;
            while(l1!=-1&&Max[ll[i][l1]]<=Max[it])l1--;
             ans+=max(l1-l2+1,0);
        }
         
    }
   /* int tot2=0;
    LL Ma=0,Mi=1e18;
    for(int i = mid;i>=l;i--){
        Ma=max(Ma,a[i]);
        Mi=min(Mi,a[i]);
        LL Ma2=Ma;
        LL Mi2=Mi;
        for(int j=mid+1;j<=r;j++){
            Ma2=max(Ma2,a[j]);
            Mi2=min(Mi2,a[j]);
            if(__builtin_popcountll(Ma2)==__builtin_popcountll(Mi2))tot2++;
        }
    }
   // printf("%d\n",tot2);
   // printf("%d %d %d %d\n",ans,l,r,mid);
    assert(tot2==ans-last);*/
}
void solve(){
   // MEM(val);
    int n=10;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
        //a[i]=rand()%10+1;
        for(int j = 0;j<60;j++){
            if(a[i]&(1ll<<j))val[i]++;
        }
    }
    dc(1,n);
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
  //  scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/