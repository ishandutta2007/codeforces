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
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;
int order[1005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[1005];
    vector<pii> v;
    for(int i=0;i<m;i++){
        int t,l,r;
        scanf("%d %d %d",&t,&l,&r);
        if(t==1){
            for(int j=l;j<r;j++){
                order[j]=1;
            }
        }
        else{
            v.pb(mp(l,r));
        }
    }
    int ok=1;
    for(auto it:v){
        int ook=0;
        for(int i =it.x;i<it.y;i++){
            if(!order[i])
                ook=1;
        }
        if(!ook)ok=0;
    }
    if(!ok){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        int last=1005;
        printf("%d ",last);
        for(int i = 2;i<=n;i++){
            if(!order[i-1]){
                last--;
            }
            printf("%d ",last);
        }
        printf("\n");
    }
}
/*
1 
2 6 
3 5 
4
*/