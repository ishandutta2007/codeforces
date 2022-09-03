#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
//#define ll long long
void solve(){
    int n;
    scanf("%d",&n);
    int a[4005];
    for(int i = 1;i<=2*n;i++)scanf("%d",&a[i]);
    vector<int> v;
    int now=2*n;
    while(now){
        int Max=-1,Maxi;
        for(int i = 1;i<=now;i++){
            if(a[i]>Max){
                Max=a[i];
                Maxi=i;
            }
        }
        v.pb(now-Maxi+1);
     
       // printf("%d %d\n",Maxi,now-Maxi+1);
           now=Maxi-1;
    }
    bitset<4005> b;
    b[0]=1;
    for(auto it:v){
        b=b|(b<<it);
    }
    if(b[n])printf("YES\n");
    else printf("NO\n");
    //int now=2*n;

}
int main(){
    int t;
    scanf("%d",&t);
    //Find();
    while(t--){
        solve();
    }
}