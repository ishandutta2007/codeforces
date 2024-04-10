#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
LL s[1005][1005];
LL s2[26][1005][1005];
void add(int x,int y,int k,LL S[1005][1005]){
    for(int i = x;i<1005;i+=i&-i){
        for(int j=y;j<1005;j+=j&-j){
            S[i][j]+=k;
        }
    }
}
LL query(int x,int y,LL S[1005][1005]){
    LL res=0;
    for(int i = x;i>0;i-=i&-i){
        for(int  j =y;j>0;j-=j&-j){
            res+=S[i][j];
        }
    }
    return res;
}
char c[1005][1005];
LL cnt[26][1005][1005];
LL val[1005][1005];
vector<int> v[300005];
char color[300005];
int main(){
    int n,m,K;
    scanf("%d %d %d",&n,&m,&K);
    for(int i = 1;i<=n;i++)
        scanf("%s",c[i]+1);

    for(int i=0;i<K;i++){
        int a,b,c,d;
        char co;
        scanf("%d %d %d %d %c",&a,&b,&c,&d,&co);
        color[i]=co;
        v[i]=vector<int>{a,b,c,d};
        add(a,b,1,s);
        add(a,d+1,-1,s);
        add(c+1,b,-1,s);
        add(c+1,d+1,1,s);
        add(a,b,1,s2[co-'a']);
        add(a,d+1,-1,s2[co-'a']);
        add(c+1,b,-1,s2[co-'a']);
        add(c+1,d+1,1,s2[co-'a']);
    }
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            LL mycnt[26];
            MEM(mycnt);
            mycnt[c[i][j]-'a']=K;
            mycnt[c[i][j]-'a']-=query(i,j,s);
            for(int k = 0;k<26;k++){
                mycnt[k]+=query(i,j,s2[k]);
                cnt[k][i][j]+=mycnt[k];
                val[i][j]+=abs(k-(c[i][j]-'a'))*mycnt[k];
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k = 0;k<26;k++){
                cnt[k][i][j]=cnt[k][i][j]-cnt[k][i-1][j-1]+cnt[k][i-1][j]+cnt[k][i][j-1];
            }
            val[i][j]=val[i][j]-val[i-1][j-1]+val[i][j-1]+val[i-1][j];
        }
    }
    LL ans=1e18;
    for(int i = 0;i<K;i++){
        LL tot=val[n][m];
        int a=v[i][0],b=v[i][1],c=v[i][2],d=v[i][3];
        char co=color[i];
        tot-=val[c][d]-val[a-1][d]-val[c][b-1]+val[a-1][b-1];
        for(int j = 0;j<26;j++){
            LL totc=cnt[j][c][d]-cnt[j][a-1][d]-cnt[j][c][b-1]+cnt[j][a-1][b-1];
            tot+=totc*abs(j-(co-'a'));
        }
        ans=min(ans,tot);
    }
    printf("%lld\n",ans);
    return 0;
}