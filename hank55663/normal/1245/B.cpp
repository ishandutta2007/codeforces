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
#define MXN 1500
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        char ans[105];
        MEM(ans);
        char cc[105];
        scanf("%s",cc);
        int tot=0;
        for(int i =0;i<n;i++){
            if(cc[i]=='R'){
                if(b){
                    ans[i]='P';
                    b--;
                    tot++;
                }
            }
            if(cc[i]=='P'){
                if(c){
                    ans[i]='S';
                    c--;
                    tot++;
                }
            }
            if(cc[i]=='S'){
                if(a){
                    ans[i]='R';
                    a--;
                    tot++;
                }
            }
        }
        if(tot<(n+1)/2){
            printf("NO\n");
        }
        else{
            for(int i=0;i<n;i++){
                if(ans[i]==0){
                    if(a){
                        ans[i]='R';
                        a--;
                    }
                    else if(b){
                        ans[i]='P';
                        b--;
                    }
                    else{
                        ans[i]='S';
                    }
                }
            }
            printf("YES\n%s\n",ans);
        }
    }
}