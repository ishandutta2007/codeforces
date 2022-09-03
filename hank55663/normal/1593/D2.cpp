#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
int a[40];
bool check(int v,int i,int n){
    int tot=1;
    for(int j = i+1;j<n;j++){
        if((a[j]-a[i])%v==0)tot++;
    }
  //  printf("%d %d %d\n",v,tot,n);
    if(tot*2>=n)return true;
    return false;
}
void solve(){
    int n;
    scanf("%d",&n);
    int gcd=0;

    map<int,int> m;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    for(auto it:m){
        if(it.y*2>=n){
            printf("-1\n");
            return;
        }
    }
    sort(a,a+n);
    int ans=1;
    for(int i = 0;i<n;i++){
        for(int j =i+1;j<n;j++){
            int x=a[j]-a[i];
            for(int k = 1;k*k<=x;k++){
                if(x%k==0){
                    if(check(k,i,n))ans=max(ans,k);
                    if(check(x/k,i,n))ans=max(ans,x/k);
                }
            }
        }
    }
    printf("%d\n",ans);
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
*/