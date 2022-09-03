#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 1005
void solve(){
    int n;
    scanf("%d",&n);
    int a[55];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    vector<pair<pii,int> > v;
    for(int i = n-1;i>=0;i--){
        int Max=-1e9-7,Maxi=0;
        for(int j=i;j>=0;j--){
            if(a[j]>Max){
                Max=a[j];
                Maxi=j;
            }
        }
        if(i!=Maxi){
            v.pb(mp(mp(Maxi+1,i+1),1));
            for(int j=Maxi;j<i;j++)swap(a[j],a[j+1]);
        }
    }
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d %d %d\n",it.x.x,it.x.y,it.y);
    }
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*

*/