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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int main(){
    int t;
    scanf("%d",&t);
    string s[100005];
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i = 0;i<k;i++)s[i]="";
        char c[100005];
        scanf("%s",c);
        sort(c,c+n);
        if(c[0]==c[n-1]){
            for(int i = 0;i<(n+k-1)/k;i++){
                printf("%c",c[0]);
            }
            printf("\n");
        }
        else if(c[k-1]==c[0]){
            if(c[k]==c[k-1]||c[k]!=c[n-1])
            printf("%c%s\n",c[0],c+k);
            else{
                printf("%c",c[0]);
                for(int i = 1;i<(n+k-1)/k;i++){
                    printf("%c",c[k]);
                }
                printf("\n");
            }
        }
        else{
            printf("%c\n",c[k-1]);
        }
    }
}