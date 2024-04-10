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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
#define N 6000005
#define rank Rank
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        k=min(k,m-1);
        int a[3505];
        for(int i = 1;i<=n;i++)
            scanf("%d",&a[i]);
        vector<int> v;
        for(int i = 1;i<=m;i++){
            v.pb(max(a[i],a[i+n-m]));
        }
        multiset<int> s;
        int ans=0;
        for(int i = 0;i<m;i++){
            s.insert(v[i]);
            
       /*     for(auto it:s)printf("%d ",it);
            printf("\n");*/
            if(i>=m-k-1){
                ans=max(ans,*s.begin());
                s.erase(s.find(v[i-(m-k-1)]));
            }
        }
        printf("%d\n",ans);
    }
}