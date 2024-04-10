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
#define double long double
using namespace std;
void solve(){  
    int n,q;
    scanf("%d %d",&n,&q);
    int a[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ok[100005];
    int tot=0;
    for(int i = 0;i<n;i++){
        if(a[i]<=q)ok[i]=1;
        else ok[i]=0,tot++;
    }
    int Max=tot+1,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int ook[100005];
        int now=mid;
        for(int i = n-1;i>=0;i--){
            if(ok[i])ook[i]=1;
            else if(now)ook[i]=1,now--;
            else ook[i]=0;
        }
        int r=q;;
        for(int i = 0;i<n;i++){
            if(ook[i]&&r<a[i])r--;
        }
        if(r>=0)Min=mid;
        else Max=mid;
    }
    int now=Min;
    for(int i = n-1;i>=0;i--){
        if(ok[i]);
        else if(now)ok[i]=1,now--;
    }
    for(int i= 0;i<n;i++)printf("%d",ok[i]);
    printf("\n");
    //printf("%d\n",n-tot+Min);
}
int main(){
    int t=1;
    scanf("%d",&t);
    //printf("\"");
    while(t--){
        // cerr<<t<<endl;
        solve();
     //   cerr<<t<<endl;
    }
    
   // cerr<<cnt<<endl;
}
/*
*/