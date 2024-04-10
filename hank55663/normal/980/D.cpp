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
    int n;
    scanf("%d",&n);
    int a[5005];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        for(int j=2;j<=10000;j++){
            while(a[i]%sqr(j)==0&&a[i]!=0){
                a[i]/=sqr(j);
            }
        }
    }
    map<int,int> m;
    for(int i=0;i<n;i++)
    m[a[i]];
    int index=0;
    for(auto &it:m)
    it.y=++index;
    m[0]=0;
    for(int i=0;i<n;i++)
    a[i]=m[a[i]];
    int ans[5005];
    MEM(ans);
    for(int i=0;i<n;i++){
        int cnt[5005];
        MEM(cnt);
        cnt[0]=1;
        int sum=0;
        for(int j=i;j<n;j++){
            if(!cnt[a[j]])
                sum++;
            ans[sum]++;
            cnt[a[j]]++;
        }
    }
    ans[1]+=ans[0];
    for(int i=1;i<=n;i++)
    printf("%d ",ans[i]);
}
/*
6 4 8 2
4 8 2 2
6 8 2 2
6 4 2 2
6 2 2
6 4 2
8 2 2

*/