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
int main(){
    int n,l;
    scanf("%d %d",&n,&l);
    int a[55];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int b[105];
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++){
        b[n+i]=b[i]+l;
    }
    for(int i = 0;i<n;i++){
        int ok=1;
        for(int j = 0;j<n-1;j++){
            if(a[j+1]-a[j]!=b[i+j+1]-b[i+j]){
                ok=0;
                //printf("%d %d\n",i,j);
                break;
            }
        }
        if(ok){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}