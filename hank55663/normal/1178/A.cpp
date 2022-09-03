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
int main(){
    int n;
    scanf("%d",&n);
    pii a[105];
    int sum=0;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[i]=mp(x,i);
        sum+=x;
    }
    sort(a+2,a+n+1);
    int tmp=a[1].x;
    vector<int> v;
    v.pb(1);
    for(int i=2;i<=n&&a[i].x<=a[1].x/2;i++){
        tmp+=a[i].x;
        v.pb(a[i].y);
    }
    if(tmp*2>sum){
        printf("%d\n",v.size());
        sort(v.begin(),v.end());
        for(auto it:v)
            printf("%d " ,it);
        printf("\n");
    }
    else{
        printf("0\n");
    }
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