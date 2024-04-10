#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    int cnt=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt+=a[i];
    }
    if(cnt%2==1){
        printf("NO\n");
    }
    else{
        vector<int> v;
        for(int i = 1;i<=n;i++){
            if(a[i]==1)v.pb(i);
        }
        int cnt=0;
        vector<int> ans;
        for(int i = 1;i<=n;i++){
            cnt+=a[i];
            if(a[i]==0){
                if(cnt%2==1){
                    ans.pb(i-1);
                    int t=a[i-1]^a[i]^a[i+1];
                    if(t==0){
                        cnt--;
                        a[i-1]=a[i]=a[i+1]=0;
                    }
                    else{
                         a[i-1]=a[i]=a[i+1]=1;
                         cnt++;
                         continue;
                    }
                }
                if(cnt%2==0){
                    printf("YES\n");
                    for(int j = i-1;j>=1;j--){
                        if(a[j]==1){
                            if(a[j-1]==1){
                                ans.pb(j-1);
                                a[j-1]=0;
                                a[j]=0;
                            }
                            else{
                                ans.pb(j-2);
                                ans.pb(j-1);
                                a[j]=0;
                                a[j-2]^=1;
                            }
                        }
                    }
                    for(int j = i+1;j<=n;j++){
                        if(a[j]==1){
                            if(a[j+1]==1){
                                ans.pb(j-1);
                                a[j]=0;
                                a[j+1]=0;
                            }
                            else{
                                ans.pb(j);
                                ans.pb(j-1);
                                a[j+2]^=1;
                            }
                        }
                    }
                     printf("%d\n",ans.size());
                    for(auto it:ans)printf("%d ",it);
                    printf("\n");
                    return;
                }
                
            }
            
        }
        printf("NO\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
000010000
001010000
001010100
001011100

1 1 2
1 1 2 1
2 1
2


XOXOXOXOOXOXXOXOXOXOOXOX
*/