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
#define index Index
#define MXN 300000
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    char c[100005],c2[100005];
    vector<char> v,v2;
    scanf("%s",c);
    scanf("%s",c2);
    for(int i = 0;i<n;i++){
        if(c[i]=='a'||c[i]=='c')v.pb(c[i]);
        if(c2[i]=='a'||c2[i]=='c')v2.pb(c2[i]);
    }
    if(v!=v2){
        printf("NO\n");
    }
    else{
        int sum1=0,sum2=0;
        vector<int> v,v2;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='b')sum1--,v.pb(sum1);
            else if(c[i]=='a') sum1++,v.pb(sum1);
            if(c2[i]=='b')sum2--,v2.pb(sum2);
            else if(c2[i]=='a')sum2++,v2.pb(sum2);
           /* if(sum2>sum1){
                printf("No\n");
                return;
            }*/
        }
        for(int i = 0;i<v.size();i++){
            if(v2[i]>v[i]){
            printf("NO\n");
            return;
            }
        }
        v2.clear();
        v.clear();
        sum1=sum2=0;  
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='b')sum1++,v.pb(sum1);
            else if(c[i]=='c') sum1--,v.pb(sum1);
            if(c2[i]=='b')sum2++,v2.pb(sum2);
            else if(c2[i]=='c')sum2--,v2.pb(sum2);
          /*  if(sum2>sum1){
                printf("No\n");
                return;
            }*/
        }
           for(int i = 0;i<v.size();i++){
            if(v2[i]>v[i]){
            printf("NO\n");
            return;
            }
        }
        printf("YES\n");
    }
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}