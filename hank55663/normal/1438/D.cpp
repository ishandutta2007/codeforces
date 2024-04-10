#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
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
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    if(n%2==1){
        vector<vector<int> > v;
        for(int i = 1;i<=n-2;i+=2){
            v.pb({i,i+1,i+2});
            a[i]=a[i+1]=a[i+2]=a[i]^a[i+1]^a[i+2];
        }
        for(int i = 1;i<=n-2;i+=2){
            v.pb({i,i+1,n});
            a[i]=a[i+1]=a[n]=a[i]^a[i+1]^a[n];
        }
        printf("YES\n%d\n",v.size());
        for(auto it:v){
            printf("%d %d %d\n",it[0],it[1],it[2]);
        }
       // for(int i=  1;i<=n;i++)printf("%d",a[i]);
    }
    else{
        vector<vector<int> > v;
        for(int i = 1;i<=n-3;i+=2){
            v.pb({i,i+1,i+2});
            a[i]=a[i+1]=a[i+2]=a[i]^a[i+1]^a[i+2];
        }
        if(a[n-1]==a[n]){
            for(int i = 1;i<=n-3;i+=2){
                v.pb({i,i+1,n});
                a[i]=a[i+1]=a[n]=a[i]^a[i+1]^a[n];
            }
            printf("YES\n%d\n",v.size());
            for(auto it:v){
                printf("%d %d %d\n",it[0],it[1],it[2]);
            }
           // for(int i=  1;i<=n;i++)printf("%d",a[i]);
        }
        else{
            printf("NO\n");
        }
    }
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