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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define double long double
using namespace std;
void solve(){  
    int n;
    scanf("%d",&n);
    int a[505],b[505];
    vector<pii> v1,v2;
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++)scanf("%d",&b[i]);
    for(int i =1;i<n;i++){
        int x=a[i],y=a[i+1];
        if(x>y)swap(x,y);
        v1.pb(mp(x,y));
        x=b[i],y=b[i+1];
        if(x>y)swap(x,y);
        v2.pb(mp(x,y));
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1!=v2){
        printf("NO\n");
        return;
    }
    if(a[1]!=b[1]){
        printf("NO\n");
        return;
    }
    printf("YES\n");
    vector<pii> ans;
    for(int i = 1;i<=n;i++){
        if(a[i]!=b[i]){
         //   printf("%d\n",i);
            int ok=0;
            for(int j = i+1;j<n;j++){
                if(b[i]==a[j]&&a[j+1]==a[i-1]){
                    //printf("%d %d\n",i-1,j+1);
                    ans.pb(mp(i-1,j+1));
                    reverse(a+i,a+j+1);
                    ok=1;
                    break;
                }
            }
           // for(int j=1;j<=n;j++)printf("%d ",a[j]);
           // printf("\n");
            if(!ok){
                for(int j = i+1;j<=n;j++){
                    if(b[i]==a[j]&&a[i-1]==a[j-1]){
                        int vis[505];
                        MEM(vis);
                        int ook=0;
                        for(int k = i-1;k<j-1;k++)vis[a[k]]=k;
                        for(int k = j+1;k<=n;k++){
                            if(vis[a[k]]){
                                ans.pb(mp(vis[a[k]],k));
                                reverse(a+vis[a[k]],a+k+1);
                                ook=1;
                                break;
                            }
                        }
                    //    for(int j=1;j<=n;j++)printf("%d ",a[j]);
                     //   printf("?\n");
                        if(!ook){
                            for(int k = i-1;k<j;k++){
                                if(a[k]==a[j]){
                                    reverse(a+k,a+j+1);
                                    ans.pb(mp(k,j));
                                    ook=1;
                                    break;
                                }
                            }
                        }
                        if(ook){
                             for(int j = i+1;j<=n;j++){
                                if(b[i]==a[j]&&a[j+1]==a[i-1]){
                                    //printf("%d %d\n",i-1,j+1);
                                    ans.pb(mp(i-1,j+1));
                                    reverse(a+i,a+j+1);
                                    ok=1;
                                    break;
                                }
                            }
                         //   for(int j=1;j<=n;j++)printf("%d ",a[j]);
                        //    printf("\n");
                            assert(ok);
                            break;
                        }
                    }
                }
                assert(ok);
             //   assert(0);
            }
        }
    }
    printf("%d\n",ans.size());
    for(auto it:ans){
        printf("%d %d\n",it.x,it.y);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/