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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 3000000
void solve(){
    int a,b;
    scanf("%d %d",&a,&b);
    int xa=(a+b)/2,xb=a+b-xa;
    set<int> v;
    v.insert(max(xa-a,xb-b));
    int now=max(xa-a,xb-b);
    for(int i = 1;i<=min(a,b);i+=1){
        now+=2;
        v.insert(now);
    }
    swap(a,b);
    v.insert(max(xa-a,xb-b));
    now=max(xa-a,xb-b);
    for(int i = 1;i<=min(a,b);i+=1){
        now+=2;
        v.insert(now);
    }
    printf("%d\n",v.size());
    for(auto it:v)printf("%d ",it);
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
6 4 2 3 5 1
*/