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
//#define N 262144
#define ULL unsigned long long
#define ll long long
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int col[55],row[55];
        MEM(col);
        MEM(row);
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;
                scanf("%d",&x);
                if(x)col[i]=row[j]=1;
            }
        }
        int a=0,b=0;
        for(int i = 0;i<n;i++){
            if(!col[i])a++;
        }
        for(int i=0;i<m;i++){
            if(!row[i])b++;
        }
        if(min(a,b)&1){
            printf("Ashish\n");
        }
        else{
            printf("Vivek\n");
        }
    }
}
/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/