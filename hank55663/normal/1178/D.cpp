#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int isprime[5005];
int main(){
    fill(isprime,isprime+5005,1);
    for(int i=2;i<5005;i++){
        if(isprime[i]){
            for(int j = i*2;j<5005;j+=i)
                isprime[j]=0;
        }
    }
    int n;
    scanf("%d",&n);
    vector<pii> v;
    for(int i = 1;i<=n;i++){
        v.pb(mp(i,i%n+1));
    }
    int a=1,b=n/2+1;
    while(!isprime[v.size()]){
        v.pb(mp(a,b));
        a++;
        b++;
    }
    printf("%d\n",v.size());
    for(auto it:v)
        printf("%d %d\n",it.x,it.y);
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/