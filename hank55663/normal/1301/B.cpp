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
#define MXN 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a[400005];
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&a[i]);
        }
        vector<int> v;
        int Max=0;
        for(int i = 1 ; i < n ; i++){
            if(a[i-1]==-1&&a[i]!=-1)v.pb(a[i]);
            if(a[i]==-1&&a[i-1]!=-1)v.pb(a[i-1]);
            if(a[i]!=-1&&a[i-1]!=-1){
                Max=max(Max,abs(a[i]-a[i-1]));
            }
        }
        sort(v.begin(),v.end());
        if(v.empty()){
            printf("%d 1\n",max(Max,0));
        }
        else{
            printf("%d %d\n",max(v.back()-(v[0]+v.back())/2,Max),(v[0]+v.back())/2);
        }
    }
}