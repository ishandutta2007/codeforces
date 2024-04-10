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
int S=350;
int M=350;
void solve(){
    int n;
    scanf("%d",&n);
    if(n<=2){
        printf("0\n");
        return;
    }
    int a[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        //a[i]=rand()%n+1;
    }
    int ans=0;
    for(int i = -S;i<=S;i++){
        vector<int> v;
        for(int j = 0;j<n;j++){
            v.pb(a[j]-j*i);
            //m[a[j]-j*i]++;
        }
        sort(v.begin(),v.end());
        int cnt=1;
        ans=max(ans,cnt);
        for(int i = 1;i<v.size();i++){
            if(v[i]==v[i-1])cnt++;
            else{
                cnt=1;
            }
            ans=max(ans,cnt);
        }
       // for(auto it:m){
        //    ans=max(ans,it.y);
          //  if(it.y==9){
             //   printf("%d\n",i);
            //}
        //}

    }
   // printf("%d\n",ans);
    for(int i = 0;i<n;i++){
       vector<int> v;
        for(int j = 1;j<=M&&i+j<n;j++){
            if((a[j+i]-a[i])%j==0){
                v.pb((a[j+i]-a[i])/j);
            }
        }
        sort(v.begin(),v.end());
        int cnt=1;
        ans=max(ans,cnt+1);
        for(int i = 1;i<v.size();i++){
            if(v[i]==v[i-1])cnt++;
            else cnt=1;
            ans=max(ans,cnt+1);
        }
       // for(auto it:m){
       //    // printf("%d %d %d\n",i,it.x,it.y);
       //     ans=max(ans,it.y+1);
       // }
    }
    printf("%d\n",n-ans);
}


int main(){
    int t=1;
  //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/