#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n/2%2==1){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            LL sum=0;
            for(int i = 1;i<=n/2;i++){
                printf("%d ",i*2);
                sum+=i*2;
            }
            for(int i = 1;i<n/2;i++){
                printf("%d ",i*2-1);
                sum-=i*2-1;
            }
            printf("%lld\n",sum);
        }
    }
}