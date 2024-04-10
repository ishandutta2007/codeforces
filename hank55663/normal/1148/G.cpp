#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int from[10000005];
int cnt[10000005];
int ans[10000005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[100005];
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
        ans[a[i]]++;
    }
    for(int i = 2;i<=1e7;i++){
        for(int j = i;j<=1e7;j+=i){
            cnt[i]+=ans[j];
            if(from[j]==0)from[j]=i;
        }
    }
    for(int i = 2;i<=1e7;i++){
        if(cnt[i]>=k){
            for(int j = 0;j<n;j++){
                if(a[j]%i==0){
                    printf("%d ",j+1);
                    k--;
                }
                if(k==0)
                    return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        int temp=a[i];
        vector<int> p;
        while(temp!=1){
            int x=from[temp];
            p.pb(x);
            while(temp%x==0)temp/=x;
        }
        int tot=0;
        for(int j = 0;j<(1<<p.size());j++){
            int sum=1,mobe=-1;
            for(int k =0;k<p.size();k++)
                if(j&(1<<k))
                    sum*=p[k],mobe=-mobe;
            tot+=mobe*cnt[sum];
           // printf("%d %d\n",sum,cnt[sum]);
        }
       // printf("%d\n",tot);
        if(n-tot+1>=k){
            printf("%d",i+1);
            k--;
            for(int j =0;j<n;j++){
                if(__gcd(a[i],a[j])==1){
                    printf(" %d",j+1);
                    k--;
                    if(k==0)
                    break;
                }
            }
            printf("\n");
            return 0;
        }
    }
}
/*
1 4 2 3
1 3 6 12
k(a+b) = a*b;
k*a+k*b = a*b;
b= (k*a)/(a-k);

k*(k+i)/i

*/