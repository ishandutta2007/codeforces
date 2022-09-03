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
    int n;
    scanf("%d",&n);
    int a[105];
    int sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum!=0){
        printf("YES\n1\n1 %d\n",n);
    }
    else{
        sum=0;
        for(int i = 0;i<n;i++){
            sum+=a[i];
            if(sum!=0){
                printf("YES\n2\n1 %d\n%d %d\n",i+1,i+2,n);
                return 0;
            }
        }
        printf("NO\n");
    }
    return 0;
}
/*
1 
2 6 
3 5 
4
*/