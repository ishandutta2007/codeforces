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
#define MXN 200005

int main(){
    int n;
    scanf("%d",&n);
    char c[1000005];
    scanf("%s",c);
    int l=0,r=0;
    int sum=0;
    for(int i = 0;c[i]!=0;i++){
        //if(r>l)sum++;
        if(c[i]=='(')l++;
        else r++;
        if(c[i]=='('&&r==l)sum++;
        if(r>l)sum++;
    }
    if(l!=r){
        printf("-1\n");
    }
    else{
        printf("%d\n",sum);
    }
}