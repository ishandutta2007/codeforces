#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
struct node{
    node *n[26];
    pii p;
    node(){
        for(int i =0;i<26;i++)n[i]=NULL;
    }
}*root;
void add(char *c,int st){
    node *n=root;
    for(int i = 0;c[i]!=0;i++){
        if(!n->n[c[i]-'a'])n->n[c[i]-'a']=new node();
        n=n->n[c[i]-'a'];
        n->p=mp(st,st+i);
    }
}
vector<pii> v;
void dfs(node *n){
    if(!n)return;
    //for(auto it:n->v){
    if(n!=root)
        v.pb(n->p);
    for(int i = 0;i<26;i++){
        dfs(n->n[i]);
    }
}
LL dp[2005][2005];
LL cal(vector<pii> seg,int n,int m){
    MEM(dp);
    dp[0][0]=1;
    vector<int> v[2005];
    for(auto it:seg){
        v[it.y].pb(it.x);
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=m;j++){
            dp[i][j]+=dp[i-1][j];
            if(j!=0){
                for(auto it:v[i]){
                    dp[i][j]+=dp[it-1][j-1];
                    if(dp[i][j]>1e18){
                        dp[i][j]=1e18;
                    }
                }
            }
        }
    }
    return dp[n-1][m];
}
int main(){
//    printf("%lld\n",(LL)1e18);
    LL n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    char c[1005];
    scanf("%s",c);
    root = new node();
    for(int i = 0;c[i]!=0;i++)add(c+i,i);
    dfs(root);
    reverse(v.begin(),v.end());
    int Max = v.size()-1, Min = -1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int l=v[mid].x,r=v[mid].y;
        int st=-1;
        for(int i = 0;i<=r-l;i++){
            st=i+1;
            if(c[i]>c[i+l]){
                //st=i+1;
                break;
            }
            else if(c[i]<c[i+l]){
                st=-1;
                break;
            }
        }
        if(st==-1){
            Min=mid;
        }
        else{
            vector<pii> seg;
            for(int i = st;i<n;i++){
                int en=-1;
                for(int j=0;j<=r-l;j++){
                    en=i+j;
                    if(c[i+j]>c[l+j]){
                        break;
                    }
                    else if(c[i+j]<c[l+j]){
                        en=-1;
                        break;
                    }
                }
                if(en!=-1)seg.pb(mp(i,en));
            }
            if(cal(seg,n,m-1)<k){
                Min=mid;
            }
            else{
                Max=mid;
            }
        }
    }
    //printf("%d\n",Max);
    for(int i=v[Max].x;i<=v[Max].y;i++){
        printf("%c",c[i]);
    }
    printf("\n");
}