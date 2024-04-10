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
    LL a[500005];
    LL sum=0;
    for(int i = 0;i<(n+1)/2;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    LL x;
    scanf("%lld",&x);
    sum+=x*(n-(n+1)/2);
    for(int i =(n+1)/2;i<n;i++)a[i]=x;
    if(sum>0){
        printf("%d\n",n);
        return 0;
    }
    /*if(x>0){
        printf("-1\n");
        return 0;
    }*/
    int l=0,r=n-1;
    LL pre=0,suf=0;
    LL Min=1e18;
    int res=n;
    while(l<=r){
        pre+=a[l];
        suf+=a[r];
        sum-=a[l];
        sum-=a[r];
        if(l!=0){
            Min=min(Min+a[l]+a[r]-a[r+1],a[l]+suf-a[n-1]);
        }
        res--;
        if(sum+min(Min,min(suf,pre))>0){
            printf("%d\n",res);
            return 0;
        }
        l++;
        r--;
    }
    printf("-1\n");
}
/*
2 11 14
9 3


000111222
001112220
*/