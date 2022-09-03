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
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    reverse(c,c+n);
    vector<int> stk;
    int color[200005];
    for(int i = 0;i<n;i++){
        if(stk.empty()||stk.back()<c[i]){
            stk.pb(c[i]);
            color[i]=stk.size();
        }
        else{
            auto it=lower_bound(stk.begin(),stk.end(),(int)c[i])-stk.begin();
            color[i]=it+1;
            stk[it]=c[i];
        }
    }
    printf("%d\n",stk.size());
    reverse(color,color+n);
    for(int i = 0;i<n;i++)
        printf("%d ",color[i]);
    printf("\n");
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/