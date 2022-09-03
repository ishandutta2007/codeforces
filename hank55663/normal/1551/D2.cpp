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
vector<int> v[10005];
char cc[10005];
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int c[105][105];
    MEM(c);
    for(int i = 0;i<n*m;i++)v[i].clear(),cc[i]=0;
    if(n%2==0&&m%2==0){
        if(k%2==0){
            int index=0;
            for(int a=0;a<n;a+=2){
                for(int b = 0;b<m;b+=2){
                    if(k){
                        c[a][b]=c[a][b+1]=index++;
                        c[a+1][b]=c[a+1][b+1]=index++;
                        k-=2;
                    }
                    else{
                        c[a][b]=c[a+1][b]=index++;
                        c[a][b+1]=c[a+1][b+1]=index++;
                    }
                }
            }
            printf("YES\n");
        }
        else{
            printf("NO\n");
            return ;
        }
    }
    else if(n%2==0){
        if(k%2==0&&n*m/2-k>=n/2){
            printf("YES\n");
            int index=0;
            for(int j = 0;j<n;j+=2)c[j][0]=c[j+1][0]=index++;
            for(int a=0;a<n;a+=2){
                for(int b = 1;b<m;b+=2){
                    if(k){
                        c[a][b]=c[a][b+1]=index++;
                        c[a+1][b]=c[a+1][b+1]=index++;
                        k-=2;
                    }
                    else{
                        c[a][b]=c[a+1][b]=index++;
                        c[a][b+1]=c[a+1][b+1]=index++;
                    }
                }
            }
        }
        else{ printf("NO\n"); return ;}
    }
    else if(m%2==0){
        k-=m/2;
        if(k>=0&&k%2==0){
            int index=0;
            for(int j = 0;j<m;j+=2)c[0][j]=c[0][j+1]=index++;
             for(int a=1;a<n;a+=2){
                for(int b = 0;b<m;b+=2){
                    if(k){
                        c[a][b]=c[a][b+1]=index++;
                        c[a+1][b]=c[a+1][b+1]=index++;
                        k-=2;
                    }
                    else{
                        c[a][b]=c[a+1][b]=index++;
                        c[a][b+1]=c[a+1][b+1]=index++;
                    }
                }
            }
            printf("YES\n");
        }
        else{ printf("NO\n");return ;}
    }  
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
           // printf("%d",c[i][j]);
            if(i!=0&&c[i][j]!=c[i-1][j])v[c[i][j]].pb(c[i-1][j]),v[c[i-1][j]].pb(c[i][j]);//printf("%d %d\n",c[i][j],c[i-1][j]);
            if(j!=0&&c[i][j]!=c[i][j-1])v[c[i][j]].pb(c[i][j-1]),v[c[i][j-1]].pb(c[i][j]);//printf("%d %d\n",c[i][j],c[i][j-1]);
        }
     //   printf("\n");
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(cc[c[i][j]]);
            else{
                for(int a='a';a<='z';a++){
                    int ok=1;
                    for(auto it:v[c[i][j]]){
                        if(cc[it]==a)ok=0;
                    }
                    if(ok){cc[c[i][j]]=a;break;};
                }
            }
            printf("%c",cc[c[i][j]]);
        }
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
*/