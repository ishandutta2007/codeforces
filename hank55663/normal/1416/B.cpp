#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define N 700005
void solve(){
    int n;
    scanf("%d",&n);
    int a[10005];
    LL tot=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    vector<pair<pii,int> > v;
    if(tot%n){
        printf("-1\n");
        return;
    }
    for(int i = 2;i<=n;i++){
        if(a[i]%i!=0){
            v.pb(mp(mp(1,i),i-a[i]%i));
            a[1]-=i-a[i]%i;
            a[i]+=i-a[i]%i;
        }
        assert(a[i]%i==0);
        v.pb(mp(mp(i,1),a[i]/i));
        a[1]+=a[i];
        a[i]=0;
    }
    for(int i = 2;i<=n;i++){
        v.pb(mp(mp(1,i),tot/n));
        a[i]+=tot/n;
        a[1]-=tot/n;
    }
    for(int i = 1;i<=n;i++)assert(a[i]==tot/n);
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d %d %d\n",it.x.x,it.x.y,it.y);
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/