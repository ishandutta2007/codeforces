#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i = 30;i>0;i--){
        int Min=0,sum=0;
        for(int j = 0;j<n;j++){
            if(a[j]>i){
                Min=0;
                sum=0;
                continue;
            }
            sum+=a[j];
            Min=min(Min,sum);
            ans=max(ans,sum-Min-i);
        //    printf("%d %d %d\n",i,j,sum-Min-i);
        }
    }
    printf("%d\n",ans);
}
/*
2 11 14
9 3


000111222
001112220
*/