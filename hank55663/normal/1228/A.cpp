




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
bool check(int x){
    set<int> s;
    while(x){
        int y=x%10;
        x/=10;
        if(s.find(y)!=s.end())return false;
        s.insert(y);
    }
    return true;
}
int main(){
    int l,r;
    scanf("%d %d",&l,&r);
    for(int i=l;i<=r;i++){
        if(check(i)){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}