#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
int Max=1e9;
int vis[30000007];
vector<int> stk;
vector<vector<int> > ans;
int res;
bool search(int i,int n,int *b,int need,int sum){
       //printf("%d\n",sum);
    if(need==0){
//        printf("! %d\n",sum);
        if(vis[sum]){
            res=sum;
  //          printf("end\n");
            return true;
        }
        else vis[sum]=1;
        return false;
    }
    if(i==n+1)return false;
    for(int j=i;j<=n;j++){
        if(search(j+1,n,b,need-1,sum+b[j]))return true;
    }
   // if(search(i+1,n,b,need,sum))return true;
    //stk.pb(i);
   // if(search(i+1,n,b,need-1,sum+b[i]))return true;
    //stk.pop_back();
    return false;
}
bool go(int i,int n,int *b,int need,int sum,int res){
       //printf("%d\n",sum);
    if(need==0){
        if(sum==res){
            ans.pb(stk);
        }
        if(ans.size()==2)return true;
        return false;
    }
    if(i==n+1)return false;
    for(int j=i;j<=n;j++){
        stk.pb(j);
        if(go(j+1,n,b,need-1,sum+b[j],res))return true;
        stk.pop_back();
    }
    return false;
}
void solve(){
    int n;
    scanf("%d",&n);
    int b[1005];
  //  b[0]=1;
    for(int i = 0;i<n;i++){
       // b[i]=b[i-1]+(i%20+1)*2;
        scanf("%d",&b[i]);
       // printf("%d ",b[i]);
    }
   // printf("\n");
    sort(b,b+n);
    if(n==2){
        if(b[0]!=b[1]){
            printf("NO\n");
            return;
        }
        else{
            printf("YES\n%d %d\n",0,b[0]);
        }
    }
    else if(n==3){
        int tot=b[0]+b[1]+b[2];
        if(tot%2==1){
            if(b[0]==b[1]){
                printf("YES\n0 %d %d\n",b[1],b[2]);
            }
            else if(b[1]==b[2]){
                printf("YES\n0 %d %d\n",b[0],b[1]);
            }
            else
            printf("NO\n");
        }
        else{
            tot/=2;
            printf("YES\n%d %d %d\n",tot-b[0],tot-b[1],tot-b[2]);
        }
    }
    else{
        for(int i = 0;i+1<n;i++){
            if(b[i]==b[i+1]){
                printf("YES\n");
                printf("0");
                for(int j = 0;j<n;j++){
                    if(j==i)continue;
                    printf(" %d",b[j]);
                }
                printf("\n");
                return;
            }
        }
        vector<int> odd,even;
        for(int i = 0;i<n;i++){
            if(b[i]%2==0){
                even.pb(b[i]);
            }
            else{
                odd.pb(b[i]);
            }
        }
        if(even.size()>=3){
            int tot=even[0]+even[1]+even[2];
            tot/=2;
            int a[3]={tot-even[0],tot-even[1],tot-even[2]};
            printf("YES\n");
            printf("%d %d %d",a[0],a[1],a[2]);
            for(auto it:odd)printf(" %d",it-a[0]);
            for(int i = 3;i<even.size();i++){
                printf(" %d",even[i]-a[0]);
            }
            printf("\n");
            return;
        }
        else if(odd.size()>=2&&even.size()>=1){
            int tot=odd[0]+odd[1]+even[0];
            tot/=2;
            int a[3]={tot-odd[0],tot-odd[1],tot-even[0]};
            printf("YES\n");
            printf("%d %d %d",a[0],a[1],a[2]);
           // for(auto it:odd)printf(" %d",it-a[0]);
            for(int i = 2;i<odd.size();i++){
                printf(" %d",odd[i]-a[0]);
            }
            for(int i = 1;i<even.size();i++){
                printf(" %d",even[i]-a[0]);
            }
            printf("\n");
            return;
        }
        else{
            for(int i = 2;i<=n;i++){
                fill(vis,vis+i*1000000+1,0);
                if(search(0,n,b,i,0)){
                    go(0,n,b,i,0,res);
                 //   printf("%d\n",res);
                    vector<int> q;
                    for(int j=0;j<i;j++)q.pb(ans[0][j]),q.pb(ans[1][j]);
                    int a[1005];
                    a[0]=0;
                    int vis[1005];
                    MEM(vis);
                    //printf("%d\n",q.size());
                    for(int i=0;i+1<q.size();i++){
                        a[i+1]=b[q[i]]-a[i];
                       // printf("%d ",q[i]);
                        vis[q[i]]=1;
                    }
                    vis[q.back()]=1;
                   // printf("%d\n",q.back());
                    assert(a[0]+a[i*2-1]==b[q.back()]);
                    printf("YES\n");
                    for(int i = 0;i<q.size();i++)printf("%d ",a[i]);
                    for(int i = 0;i<n;i++){
                        if(!vis[i])printf("%d ",b[i]);
                    }
                    printf("\n");
                    return;
                }
            }
            printf("NO\n");
        }
    }
}
int main(){

    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
60.0 0.0 50.0 170.0 
3
40.0 0.0 0.0 0.0
5.0 20.0 5.0 170.0
95.0 0.0 95.0 80.0


0.0 1.0 4.0 1.0 
1
0.0 0.0 4.0 0.0
*/