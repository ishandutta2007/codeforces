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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define next Next
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int a[300005];
    vector<int> v;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i!=0){
            v.pb(a[i]-a[i-1]);
        }
    }
    int ans=a[n-1]-a[0];
    sort(v.begin(),v.end());
    for(int i = 1;i<k;i++){
        ans-=v.back();
        v.pop_back();
        //printf("%d\n",ans);
    }
    printf("%d\n",ans);
}