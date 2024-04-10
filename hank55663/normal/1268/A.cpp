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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    char c[200005];
    scanf("%s",c);
    char c2[200005];
    MEM(c2);
    for(int i = 0;i<n;i++){
        c2[i]=c[i%k];
    }
    printf("%d\n",n);
    int ok=1;
    for(int i= 0;i<n;i++){
        if(c2[i]>c[i])break;
        if(c2[i]<c[i]){
            ok=0;
            break;
        }
    }
    if(ok){
        printf("%s\n",c2);
    }
    else{
        c[k-1]++;
        int now=k-1;
        while(c[now]>'9'){
            c[now]='0';
            c[now-1]++;
            now--;
        }
        for(int i = 0;i<n;i++){
            c2[i]=c[i%k];
        }
        printf("%s\n",c2);
    }
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/