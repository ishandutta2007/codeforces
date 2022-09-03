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
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[100005];
        for(int i =0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int ans=1;
        for(int i = 0;i<n;i++){
            if(a[i]<i+2)ans=i+2;
        }
        printf("%d\n",ans);
    }
}
/*
2 11 14
9 3


000111222
001112220
*/