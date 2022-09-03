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
using namespace std;
LL dp[30][30];
LL add[30];
LL pro[30];
LL from[30][30];
LL DP(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    from[l][r]=-1;
    if(l==r)return dp[l][r]=pro[l];
    dp[l][r]=1;
    from[l][r]=-1;
    for(int i = l;i<=r;i++){
        dp[l][r]*=pro[i];
    }
    for(int i = l;i<r;i++){
        LL val=DP(l,i)+add[i]+DP(i+1,r);
        if(val>dp[l][r]){
            dp[l][r]=val;
            from[l][r]=i;
        }
    }
    return dp[l][r];
}
int need[50];
void go(int l,int r){
    if(from[l][r]==-1){
        need[l-1]=need[r]=1;
        return;
    }
    go(l,from[l][r]);
    go(from[l][r]+1,r);
}
void solve2(int *a,int n){
    vector<int> tmp;
    int st=0;
    for(int i = 0;i<=n;i++){
        if(a[i]==0||i==n){
            if(tmp.size()){
                LL tot=1;
                int end=0;
                int from=0;
                while(tmp.size()&&tmp.back()==1)end++,tmp.pop_back();
                reverse(tmp.begin(),tmp.end());
                while(tmp.size()&&tmp.back()==1)from++,tmp.pop_back();
                reverse(tmp.begin(),tmp.end());
                if(tmp.size()){
                    if(st!=0)printf("+");
                    for(int i  =0;i<from;i++)printf("1+");
                    LL tot=1;
                    for(auto it:tmp){
                        tot=tot*it;
                        if(tot>1e9)break;
                    }
                    if(tot>1e9){
                        printf("%d",tmp[0]);
                        for(int i = 1;i<tmp.size();i++){
                            printf("*%d",tmp[i]);
                        }
                    }
                    else{
                        int now=1;
                        LL val=1;
                        LL cnt=0;
                        for(int i = 0;i<tmp.size();i++){
                            if(tmp[i]!=1)val*=tmp[i];
                            else cnt++;
                            if(i==tmp.size()-1||(tmp[i]==1&&tmp[i+1]!=1)){
                                pro[now]=val;
                                add[now]=cnt;
                                //printf("%d %d %d\n",now,val,cnt);
                                now++;
                                
                                val=1;
                                cnt=0;
                            }
                        }
                        memset(dp,-1,sizeof(dp));
                        DP(1,now-1);
                        //printf("%lld\n",dp[1][now-1]);
                        memset(need,0,sizeof(need));
                        go(1,now-1);
                        now=1;
                        printf("%d",tmp[0]);
                        for(int i = 1;i<tmp.size();i++){
                            if(tmp[i]!=1&&tmp[i-1]==1){
                                    //tmp[i]==1&&tmp[i+1])
                                if(need[now])printf("+");
                                else printf("*");
                                now++;
                            }
                            else if(tmp[i]==1){
                                if(need[now])printf("+");
                                else printf("*");
                            }
                            else{
                                printf("*");
                            }
                            printf("%d",tmp[i]);
                        }
                    }
                    for(int i = 0;i<end;i++)printf("+1");
                }
                else{
                    if(st==0)printf("1");
                    else printf("+1");
                    for(int i = 1;i<end;i++)printf("+1");
                }
            }
            tmp.clear();
            if(i!=n){
                if(i!=0)
                printf("+0");
                else{
                    printf("0");
                }
            }
            st=i+1;
        }
        else{
            tmp.pb(a[i]);
        }
    }
    printf("\n");
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    char c[10];
    scanf("%s",c);
    sort(c,c+strlen(c));
    //printf("%s\n",c);
    if(strlen(c)==1){
        printf("%d",a[0]);
        for(int i = 1;i<n;i++){
            printf("%c%d",c[0],a[i]);
        }
        printf("\n");
    }
    else if(strlen(c)==2){
        if(c[0]=='*'&&c[1]=='-'){
            printf("%d",a[0]);
            for(int i = 1;i<n;i++){
                if(a[i]==0)
                printf("-%d",a[i]);
                else{
                    printf("*%d",a[i]);
                }
            }
            printf("\n");
        }
        if(c[0]=='*'&&c[1]=='+'){
            solve2(a,n);
        }
        if(c[0]=='+'){
            printf("%d",a[0]);
            for(int i = 1;i<n;i++){
                printf("+%d",a[i]);
            }
            printf("\n");
        }
    }
    else{
        solve2(a,n);
    }
}
int main(){
    int t=1;//00000;  
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}