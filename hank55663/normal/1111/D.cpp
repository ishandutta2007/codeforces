#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int dpf[54][100005];
int dpb[54][100005];
int dp[54][100005];
const int mod=1e9+7;
LL fra[100005];
LL inv[100005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    fra[0]=1;
    for(int i=1;i<=100000;i++)
    fra[i]=fra[i-1]*i%mod;
    inv[100000]=f_pow(fra[100000],mod-2);
    for(int i=99999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    char c[100005];
    scanf("%s",c);
    int len=strlen(c)/2;
    int cnt[55];
    MEM(cnt);
    for(int i=0;c[i]!=0;i++){
        if(c[i]<='Z'){
            cnt[c[i]-'A']++;
        }
        else{
            cnt[c[i]-'a'+26]++;
        }
    }
    LL tot=fra[len]*fra[len]%mod;
    for(int i=0;i<52;i++){
        tot=tot*inv[cnt[i]]%mod;
    }
    dp[0][0]=1;
    for(int j=0;j<52;j++){
        for(int k=0;k<=len;k++){
            dp[j+1][k]+=dp[j][k];
            dp[j+1][k]%=mod;
            if(cnt[j]&&k+cnt[j]<=len){
                dp[j+1][k+cnt[j]]+=dp[j][k];
                dp[j+1][k+cnt[j]]%=mod;
            }
        }
    }
    int v[55];
    for(int i=0;i<52;i++){
        //if(cnt[i])
        v[i]=cnt[i];
        //v.pb(cnt[i]);
    }
    int ans[55][55];
    MEM(ans);
    for(int i=0;i<52;i++){
        if(!cnt[i])continue;
        v[i]=0;
        MEM(dpf);
        MEM(dpb);
        dpf[0][0]=1;
        dpf[0][v[0]]=1;
        int sum=v[0];
        for(int j=1;j<52;j++){
            for(int k=0;k<=len&&k<=sum;k++){
                dpf[j][k]+=dpf[j-1][k];
                dpf[j][k]%=mod;
                if(v[j]!=0&&k+v[j]<=len){
                    dpf[j][k+v[j]]+=dpf[j-1][k];
                    dpf[j][k+v[j]]%=mod;
                }
            }
            sum+=v[j];
        }
        dpb[51][0]=1;
        dpb[51][v[51]]=1;
        sum=v[51];
        for(int j=50;j>=0;j--){
            for(int k=0;k<=len&&k<=sum;k++){
                dpb[j][k]+=dpb[j+1][k];
                dpb[j][k]%=mod;
                if(v[j]!=0&&k+v[j]<=len){
                    dpb[j][k+v[j]]+=dpb[j+1][k];
                    dpb[j][k+v[j]]%=mod;
                }
            }
            sum+=v[j];
        }
        for(int j=0;j<52;j++){
            if(j!=i&&cnt[j]){
                if(j==0)
                ans[i][j]=dpb[1][len];
                else if(j==51)
                ans[i][j]=dpf[50][len];
                else
                for(int k=0;k<=len;k++){
                    ans[i][j]+=(LL)dpf[j-1][k]*dpb[j+1][len-k]%mod;
                    ans[i][j]%=mod;
                }
            }
        }
        v[i]=cnt[i];
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;
        b--;
        if(c[a]==c[b]){
            printf("%lld\n",tot*dp[52][len]%mod);
        }
        else{
            int ba,bb;
            if(c[a]>='a'){
                ba=c[a]-'a'+26;
            }
            else{
                ba=c[a]-'A';
            }
            if(c[b]>='a'){
                bb=c[b]-'a'+26;
            }
            else{
                bb=c[b]-'A';
            }
            printf("%lld\n",tot*ans[ba][bb]*2%mod);
        }
    }
}
/*

i f f x f l b
*/