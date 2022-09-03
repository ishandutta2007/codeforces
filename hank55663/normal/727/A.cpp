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
vector<int> v;
bool dfs(LL a,LL b){
    if(a>b)return false;
    if(a==b){
        v.pb(b);
        return true;
    }
    if(dfs(a*10+1,b)){
        v.pb(a);
        return true;
    }
    if(dfs(a*2,b)){
        v.pb(a);
        return true;
    }
    return false;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(dfs(a,b)){
        printf("YES\n");
        printf("%d\n",v.size());
        reverse(v.begin(),v.end());
        for(auto it:v){
            printf("%d ",it);
        }
        printf("\n");
    }
    else{
        printf("NO\n");
    }
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */