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
using namespace std;
void solve(){
    int m,k;
    scanf("%d %d",&m,&k);
    int a[100005];
    int Max=0;
    for(int i = 1;i<=k;i++){
        scanf("%d",&a[i]);
        Max=max(Max,a[i]);
    }
    for(int i = 1;;i++){
      
        int tot=0,other=0;
         int n=i;
        if(i%2==1){
            tot=((n+1)*(n+1))/4;
            other=((n+1)*(n+1))/2-n-1;
        }
        else{
            tot=n*n/4;
            other=n*n/2;
        }
        if(Max-tot<=other/2&&tot+other>=m){
            int ans[600][600];
           
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++)ans[i][j]=0;
            }
            priority_queue<pii> pq;
            for(int i =1;i<=k;i++)if(a[i])pq.push(mp(a[i],i));
            for(int i = 0;i<n;i+=2){
                for(int j = 0;j<n;j+=2){
                    if(pq.empty())break;
                    pii p=pq.top();
                    pq.pop();
                    ans[i][j]=p.y;
                    p.x--;
                    a[p.y]--;
                    if(p.x)pq.push(p);
                }
            }
            vector<pii> v;
            for(int i = 1;i<=k;i++){
                if(a[i])
                v.pb(mp(a[i],i));
            }
           /* if(n%2==0){
                for(int i = 1;i<n;i+=2){
                    for(int j = 0;j<n;j+=2){
                        if(v.empty())break;
                        ans[i][j]=v.back().y;
                        v.back().x--;
                        if(v.back().x==0)v.pop_back();
                    }
                }
                for(int i = 0;i<n;i+=2){
                    for(int j = 1;j<n;j+=2){
                        if(v.empty())break;
                        ans[i][j]=v.back().y;
                        v.back().x--;
                        if(v.back().x==0)v.pop_back();
                    }
                }
            }
            else{*/
                sort(v.begin(),v.end());
                reverse(v.begin(),v.end());
                int less=tot+other-m;
              //  printf("%d %d %d\n",tot,other,less);
                if(less)v.pb(mp(less,0));
                vector<pii> v1,v2;
                for(int i = 0;i<v.size();i++){
                    if(i&1)v1.pb(v[i]);
                    else v2.pb(v[i]);
                }
                reverse(v2.begin(),v2.end());
                for(auto it:v2)v1.pb(it);
                swap(v,v1);
                for(int i = 1;i<n;i+=2){
                    for(int j = 0;j<n;j+=2){
                        if(v.empty())break;
                        ans[i][j]=v.back().y;
                        v.back().x--;
                        if(v.back().x==0)v.pop_back();
                    }
                }
                for(int i = 0;i<n;i+=2){
                    for(int j = 1;j<n;j+=2){
                        if(v.empty())break;
                        ans[i][j]=v.back().y;
                        v.back().x--;
                        if(v.back().x==0)v.pop_back();
                    }
                }
               
            //}
            printf("%d\n",n);
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    printf("%d ",ans[i][j]);
                }
                printf("\n");
            }
            return;
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/