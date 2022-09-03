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
#define next Next
int main(){
    int n;
    scanf("%d",&n);
    LL sum=(LL)n*(n+1)/2;
    if(sum%2==0){
        printf("0\n");
    }
    else{
        printf("1\n");
    }
    sum/=2;
    vector<int> v;
    for(int i = n;i>=1;i--){
        if(sum>=i){
            v.pb(i);
            sum-=i;
        }
    }
    printf("%d",v.size());
    for(auto it:v)
    printf(" %d",it);
    printf("\n");
}