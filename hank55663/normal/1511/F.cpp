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
const int mod=998244353;
struct matrix{
    LL a[455][455];
    int n;
    matrix(){
        MEM(a);
    }
};
int num[40][40];
int aa[1005][1005];
matrix operator*(const matrix &a,const matrix &b){
    matrix c;
    c.n=a.n;
    for(int i = 0;i<c.n;i++){
        for(int k =0;k<c.n;k++){
            if(a.a[i][k]){
                for(int j=0;j<c.n;j++){
                    if(b.a[k][j])
                        c.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
                }
            }
           // c.a[i][j]%=mod;
        }
    }
    for(int i = 0;i<c.n;i++){
        for(int j=0;j<c.n;j++){
            c.a[i][j]%=mod;
        }
    }
    return c;
}
matrix f_pow(matrix a,int b){
    matrix res,tmp=a;
    res.n=a.n;
    for(int i = 0;i<res.n;i++)res.a[i][i]=1;
    while(b){
        if(b&1)res=res*tmp;
        tmp=tmp*tmp;
        b>>=1;
    }
    return res;
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[8][20];
    int val[8][20];
    pii rval[50];
    int index=1;
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
        for(int j=0;c[i][j]!=0;j++){
            if(c[i][j+1]==0)val[i][j]=0;
            else rval[index]=mp(i,j),val[i][j]=index++;
        }
    }
    MEMS(num);
    queue<pii> q;
    q.push(mp(0,0));
    num[0][0]=0;
    index=1;
    //int index=1;
    int ok[1777];
    MEM(ok);
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        for(int i = 0;i<26;i++){
            if(p.x==0){
                if(p.y==0){
                    for(int j = 0;j<n;j++){
                        if(c[j][0]==i+'a'){
                            for(int k = 0;k<n;k++){
                                if(c[k][0]==i+'a'){
                                    int a=val[j][0],b=val[k][0];
                                    if(num[a][b]==-1)num[a][b]=index++,q.push(mp(a,b));
                                    aa[num[p.x][p.y]][num[a][b]]++;
                                    ok[num[p.x][p.y]]=1;
                                }
                            }
                        }
                    }
                }
                else{
                    pii p1=rval[p.y];
                    if(c[p1.x][p1.y+1]==i+'a'){
                        for(int j = 0;j<n;j++){
                            if(c[j][0]==i+'a'){
                                int a=val[j][0],b=val[p1.x][p1.y+1];
                                if(num[a][b]==-1)num[a][b]=index++,q.push(mp(a,b));
                                aa[num[p.x][p.y]][num[a][b]]++;
                                ok[num[p.x][p.y]]=1;
                            }
                        }
                    }
                }
            }
            else if(p.y==0){
                pii p1=rval[p.x];
                if(c[p1.x][p1.y+1]==i+'a'){
                    for(int j = 0;j<n;j++){
                        if(c[j][0]==i+'a'){
                            int a=val[p1.x][p1.y+1],b=val[j][0];
                            if(num[a][b]==-1)num[a][b]=index++,q.push(mp(a,b));
                            aa[num[p.x][p.y]][num[a][b]]++;
                            ok[num[p.x][p.y]]=1;
                        }
                    }
                }
            }
            else{
                pii p1=rval[p.x],p2=rval[p.y];
                if(c[p1.x][p1.y+1]==i+'a'&&c[p2.x][p2.y+1]==i+'a'){
                    int a=val[p1.x][p1.y+1],b=val[p2.x][p2.y+1];
                    if(num[a][b]==-1)num[a][b]=index++,q.push(mp(a,b));
                    aa[num[p.x][p.y]][num[a][b]]++;
                    ok[num[p.x][p.y]]=1;
                }
            }
        }
    }
    int val2[1777];
    MEM(val2);
    int now=0;
    for(int i = 0;i<index;i++){
        if(ok[i])val2[i]=now++;
    }
   // printf("%d %d\n",index,now);
    matrix a;
    a.n=now;
    for(int i = 0;i<index;i++){
        for(int j =0;j<index;j++){
            if(ok[i]&&ok[j])
            a.a[val2[i]][val2[j]]=aa[i][j];
        }
    }
    a=f_pow(a,m);
    printf("%lld\n",a.a[0][0]);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    //for(int i = 2)
    while(t--){
        solve();
    }
}