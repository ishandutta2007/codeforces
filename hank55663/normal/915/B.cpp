#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
    int n,pos,l,r;
    scanf("%d %d %d %d",&n,&pos,&l,&r);
    if(l==1){
        if(r==n){
            printf("0\n");
        }
        else{
            printf("%d\n",1+abs(pos-r));
        }
    }
    else if(r==n){
        printf("%d\n",1+abs(pos-l));
    }
    else{
        int ans= 2+r-l+min(abs(pos-l),abs(pos-r));
        printf("%d\n",ans);
    }
}
/*

262143999937856
*/