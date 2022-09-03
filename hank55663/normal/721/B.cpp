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
#define MXN 300005
#define next Next
#define index Index
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v;
    for(int i = 0;i<n;i++){
        char c[105];
        scanf("%s",c);
        v.pb(strlen(c));
    }
    int target;
    char c[105];
    scanf("%s",c);
    target=strlen(c);
    sort(v.begin(),v.end());
    int ans=0;
    int ok=0;
    v.pb(1e9);
    for(int i = 0;i<v.size();i++){
        
        ans++;
        if(v[i]==target&&!ok){
            ok=1;
            printf("%d ",ans);
        }
        if(v[i+1]>target){
            printf("%d\n",ans);
            return 0;
        }
        if(i%k==k-1)
            ans+=5;
    }
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */