#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
int cnt[2000005];
int main(){
    
    int ans=0;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i+j<=n){
                ans++;
            }
        }
    }
    if(ans<m){
        printf("-1\n");
    }
    else{
     //   printf("%d\n",ans);
        ans-=m;
        int st;
        for(int i = 1;i<=n;i++){
            if((n-i)/2<=ans&&ans)ans-=(n-i)/2;
            else{
                st=i;
                break;
            }
        }
      //  printf("%d\n",st);
        int a[5005];
        for(int i = st;i<st+n-1;i++){
            a[i-st]=i;
        }
        ans=0;
        for(int i = 0;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
                if(a[i]+a[j]<st+n-1){
                    ans++;
                //    printf("%d %d\n",a[i],a[j]);
                }
                else{
                    cnt[a[i]+a[j]]++;
                }
            }
        }
     //   printf("%d\n",ans);
        for(int i=st+n-1;;i++){
            if(ans+cnt[i]==m){
                a[n-1]=i;
                break;
            }
        }
      //  int res=0;
      //  set<int> s;
        for(int i = 0;i<n;i++){
            printf("%d ",a[i]);
         //   s.insert(a[i]);
        }
        printf("\n");
       /* for(int i = 0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s.find(a[i]+a[j])!=s.end())res++;
            }
        }*/

       // assert(res==m);
        
    }
}