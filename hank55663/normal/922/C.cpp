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
int main(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    set<LL> s;
    for(LL i = 1;i<=k;i++){
        if(s.find(n%i)!=s.end()){
            printf("No\n");
            return 0;
        }
        s.insert(n%i);
    }
    printf("Yes\n");
}