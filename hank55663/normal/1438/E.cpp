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
    map<LL,vector<int> > m;
    int a[200005];
    for(int i = 1;i<=n;i++){
        //a[i]=rand()%100000000+1;
        scanf("%d",&a[i]);
    }
    LL p[200005];
    p[0]=0;
    p[1]=a[1];
    p[2]=a[2]+a[1];
    int ans=0;
    for(int i = 3;i<=n;i++){
        p[i]=p[i-1]+a[i];
        m[p[i-3]-2*p[i-2]].pb(i-2);
        LL val=p[i]-2*p[i-1];
        for(auto it:m){
            if(it.x>val)break;
            for(auto it2:it.y){
                if(p[i-1]-p[it2]==(a[i]^a[it2]))ans++;
            }
        }
    }
    printf("%d\n",ans);
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