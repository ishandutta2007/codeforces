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
#define MXN 1000005
const int mod=1e9+7;
int val[1000005];
void solve(int T){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[200005];
    for(int i =1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    vector<LL> v1,v2;
    for(int i = k+1;i<=n;i++){
        if(v1.empty())v1.pb(a[i]);
        else{
            if(a[i]>0&&v1.back()>0)v1.back()+=a[i];
            else if(a[i]<0&&v1.back()<0)v1.back()+=a[i];
            else if(a[i])v1.pb(a[i]);
        }
    }
    for(int i = k-1;i>=1;i--){
        if(v2.empty())v2.pb(a[i]);
        else{
            if(a[i]>0&&v2.back()>0)v2.back()+=a[i];
            else if(a[i]<0&&v2.back()<0)v2.back()+=a[i];
            else if(a[i])v2.pb(a[i]);
        }
    }
    int l=0,r=0;
    LL sum1=0,Min1=0;
    LL sum2=0,Min2=0;
    while(sum1<=0){
          if(l==v1.size())break;
        sum1+=v1[l];
        Min1=min(Min1,sum1);
        l++;
      
    }
    while(sum2<=0){
         if(r==v2.size())break;
        sum2+=v2[r];
        Min2=min(Min2,sum2);
        r++;
       
    }
    //printf("%d %d\n",Min1,Min2);
    LL now=a[k];
    
    while(true){
        if(now>=-Min1){
            now+=sum1;
            sum1=0;
            Min1=0;
            if(l==v1.size()){
                printf("YES\n");
                return;
            }
            while(sum1<=0){
                 if(l==v1.size())break;
                sum1+=v1[l];
                Min1=min(Min1,sum1);
                l++;
               
            }
        }  
        else if(now>=-Min2){
            now+=sum2;
            sum2=0;
            Min2=0;
            if(r==v2.size()){
                printf("YES\n");
                return;
            }
            while(sum2<=0){
                  if(r==v2.size())break;
                sum2+=v2[r];
                Min2=min(Min2,sum2);
                r++;
              
            }
        }
        else{
            printf("NO\n");
            return;
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
}