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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
int S[1000005];
void add(int x,int k){
    for(int i = x;i<1000005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i=x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
int Min[300005],Max[300005];
int pos[300005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int now=500000;
    for(int i = 1;i<=n;i++){
        Min[i]=Max[i]=i;
        add(i+500000,1);
        pos[i]=i+500000;
    }
    for(int i = 1;i<=m;i++){
        int x;
        scanf("%d",&x);
        Min[x]=1;
        Max[x]=max(Max[x],query(pos[x]-1)+1);
        add(pos[x],-1);
        pos[x]=now--;
        add(pos[x],1);
    }
    for(int i = 1;i<=n;i++){
        Max[i]=max(Max[i],query(pos[i]-1)+1);
        printf("%d %d\n",Min[i],Max[i]);
    }
}
//a+a+1=10a+1
//3a+2=10a+2