#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
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
        int w[55];
        for(int i = 0;i<n;i++)scanf("%d",&w[i]);
        int ans=0;
        for(int i = 2;i<=2*n;i++){
            int cnt[105];
            fill(cnt,cnt+105,0);
            int sum=0;
            for(int j =0;j<n;j++){
                if(i>=w[j]){
                    if(cnt[i-w[j]]){
                        sum++;
                        cnt[i-w[j]]--;
                    }
                    else{
                        cnt[w[j]]++;
                    }
                }
            }
            ans=max(ans,sum);
        }
        printf("%d\n",ans);
    }
}