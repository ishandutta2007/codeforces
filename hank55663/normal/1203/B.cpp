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
#define MXN 1500005
//#define next Next
#define index Index
#define rank Rank
#define context Context
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int cnt[10005];
        MEM(cnt);
        int n;
        scanf("%d",&n);
        for(int i=0;i<4*n;i++){
            int a;
            scanf("%d",&a);
            cnt[a]++;
        }
        vector<int> v;
        for(int i = 1;i<=10000;i++){
            for(int j = 0;j<cnt[i]/2;j++)
                v.pb(i);
        }
  //      printf("%d\n",v.size());
        if(v.size()!=2*n){
            printf("NO\n");
            continue;
        }
        int l=0,r=v.size()-1;
        int area=v[l]*v[r];
        int ok=1;
        while(l<r){
            if(v[l]*v[r]!=area)ok=0;
            l++;
            r--;
        }
        if(ok){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */