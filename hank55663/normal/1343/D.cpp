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
        int n,k;
        scanf("%d %d",&n,&k);
        int cnt[500005];
        fill(cnt,cnt+k*2+10,0);
        int a[200005];
        for(int i = 0;i<n;i++)scanf("%d",&a[i]);
        for(int i = 0;i<n/2;i++){
            int l=a[i],r=a[n-i-1];
            cnt[0]+=2;
            cnt[min(l,r)+1]--;
            cnt[l+r]--;
            cnt[l+r+1]++;
            cnt[max(k+r,k+l)+1]++;
           // printf("%d %d %d %d\n",0,l+r,l+r+1,max(k+r,k+l)+1);
        }
        int sum=0;
        int ans=1e9;
        for(int i = 0;i<=2*k;i++){
            sum+=cnt[i];
           // printf("%d ",sum);
            ans=min(ans,sum);
        }
       // printf("\n");
        printf("%d\n",ans);
    }
}