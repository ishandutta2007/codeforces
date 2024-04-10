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
#define N 100005
#define MXN 2000005
int main(){
    int n;
    scanf("%d",&n);
    char c[1005][10];
    int ok=0;
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
        if(!ok){
            if(c[i][0]=='O'&&c[i][1]=='O'){
                c[i][0]='+',c[i][1]='+';
                ok=1;
            }
            else if(c[i][3]=='O'&&c[i][4]=='O'){
                c[i][3]=c[i][4]='+';
                ok=1;
            }
        }
    }
    if(ok){
        printf("YES\n");
        for(int i = 0;i<n;i++)
            printf("%s\n",c[i]);
    }
    else{
        printf("NO\n");
    }
    return 0;
}