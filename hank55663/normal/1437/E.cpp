#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[500005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]-=i;
    }
    if(k==0){
        vector<int> v;
        for(int i = 1;i<=n;i++){
            if(v.empty()||v.back()<=a[i])v.pb(a[i]);
            else{
                *upper_bound(v.begin(),v.end(),a[i])=a[i];
            }
        }
        printf("%d\n",n-v.size());
    }
    else{
        int last=0;
        a[0]=-1e8;
        int ans=0;
        for(int i = 1;i<=k;i++){
            int x;
            scanf("%d",&x);
            vector<int> v;
            v.pb(a[last]);
            if(a[x]<a[last]){
                printf("-1\n");
                return;
            }
            for(int j=last+1;j<x;j++){
                if(v.back()<=a[j])v.pb(a[j]);
                else{
                    if(upper_bound(v.begin(),v.end(),a[j])==v.begin()&&i!=1)continue;
                    *upper_bound(v.begin(),v.end(),a[j])=a[j];
                }
            }
            v.pb(1e9);
          /*  for(auto it:v)printf("%d ",it);
            printf("\n");*/
            ans+=x-last-1-(upper_bound(v.begin(),v.end(),a[x])-v.begin()-1);
            last=x;
          //  printf("%d\n",ans);
        }
        vector<int> v;
        v.pb(a[last]);
        for(int j = last+1;j<=n;j++){
            if(v.empty()||v.back()<=a[j])v.pb(a[j]);
            else{
                if(upper_bound(v.begin(),v.end(),a[j])==v.begin())continue;
                *upper_bound(v.begin(),v.end(),a[j])=a[j];
            }
        }
       /* for(auto it:v)printf("%d ",it);
            printf("\n");*/
        ans+=n-last-v.size()+1;
        printf("%d\n",ans);
    }
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
12
0 0
0 -13
3 -13
3 -10
10 -10
10 10
-1 10
-1 13
-4 13
-4 10
-10 10
-10 0

*/