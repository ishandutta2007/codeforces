#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    pii p[300005];
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        p[i]=mp(a,i+1);
    }
    sort(p,p+n);
    for(int t=0;t<2;t++){
        vector<int> v;
        int ok=0;
        vector<int> ans1;
        vector<int> ans2;
        for(int i=n-1;i>=0;i--){
            if(p[i].x*(n-i)>=b){
                v.pb(i);
              //  printf("%d ",i);
            }
        }
        reverse(v.begin(),v.end());
       // printf("\n");
        for(int i=0;i<n;i++){
            int need=(a+p[i].x-1)/p[i].x;
        //   printf("%d ",i+need);
            if(lower_bound(v.begin(),v.end(),i+need)!=v.end()){
                printf("Yes\n");
                ok=1;
                for(int j=i;j<i+need;j++){
                    ans1.pb(p[j].y);
                }
                for(int j=*lower_bound(v.begin(),v.end(),i+need);j<n;j++)
                ans2.pb(p[j].y);
                break;
            }
        }
     //   printf("\n");
        if(ok){
            if(t==1)
            swap(ans1,ans2);
            printf("%d %d\n",ans1.size(),ans2.size());
            for(auto it:ans1)
            printf("%d ",it);
            printf("\n");
            for(auto it:ans2)
            printf("%d ",it);
            printf("\n");
            return 0;
        }
        swap(a,b);
    }
    printf("No\n");
}
/*
*/