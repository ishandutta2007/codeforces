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
#define XXX 2520
int main(){
    int n;
    scanf("%d",&n);
    if(n%2==0){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        vector<int> v;
        for(int i = 1;i<2*n;i+=2){
            v.pb(i);
        }
        for(int i = 0;i<v.size();i++){
            if(i&1)
            printf("%d ",v[i]+1);
            else
            printf("%d ",v[i]);
        }
        for(int i = 0;i<v.size();i++){
            if(i&1)
            printf("%d ",v[i]);
            else
            printf("%d ",v[i]+1);
        }
    }
}
/*
1 4  2  3

*/