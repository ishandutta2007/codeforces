#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
vector<LL> v1,v2;
void dfs(int i,int n,LL sum,int *p){
    if(i==n){
        v1.pb(sum);
        return ;
    }
    dfs(i+1,n,sum,p);
    for(int j = 0;;j++){
        LL last= sum;
        sum=sum*p[i];
        if(sum<=1e18&&sum>last&&sum%p[i]==0&&sum%last==0){
            dfs(i+1,n,sum,p);
        }
        else{
            break;
        }
    }
}
int main(){
    int n;
    int p[16];
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%d",&p[i]);
    sort(p,p+n);
    int p1[8],p2[8];
    for(int i = 0;i<n;i++){
        if(i&1)
        p2[i/2]=p[i];
        else
        p1[i/2]=p[i];
    }
    dfs(0,(n+1)/2,1,p1);
    swap(v1,v2);
    dfs(0,n/2,1,p2);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
   // printf("%d %d\n",v1.size(),v2.size());
    LL k;
    scanf("%lld",&k);
    LL Max=1e18,Min=0;
    while(Max>Min+1){
        LL mid=(Max+Min)/2;
        LL tot = 0;
        for(auto it:v1){
            LL x=upper_bound(v2.begin(),v2.end(),mid/it)-v2.begin();
            tot+=x;
        }
        if(tot>=k){
            Max=mid;
        }
        else{
            Min = mid;
        }
    }
    printf("%lld\n",Max);
}