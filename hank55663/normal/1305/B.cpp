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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
int main(){
    char c[2005];
    scanf("%s",c+1);
    int l=1,r=strlen(c+1);
    vector<int> v;
    while(l<r){
        if(c[l]==')')l++;
        else if(c[r]=='(')r--;
        else{
            v.pb(l);
            v.pb(r);
            l++;
            r--;
        }
    }
    sort(v.begin(),v.end());
    if(v.empty()){
        printf("0\n");
        return 0;
    }
    printf("1\n");
    printf("%d\n",v.size());
    for(auto it:v)printf("%d ",it);
    printf("\n");
}