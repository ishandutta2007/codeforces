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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
int main(){
    int n,I;
    scanf("%d %d",&n,&I);
    I*=8;
    int a[500005];
    int target = I/n;
    if(target>20){
        target = 1e9;
    }
    else{
        target = 1<<target;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    vector<pii> v;
    v.pb(mp(-1,-1));
    for(int i = 0;i<n;i++){
        if(v.back().x==a[i]){
            v.back().y=i;
        }
        else{
            v.pb(mp(a[i],i));
        }
    }
    int sum=0;
    for(int i = 1;i<v.size();i++){
        sum=max(v[i].y-v[max(i-target,0)].y,sum);
    }
    printf("%d\n",n-sum);
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */