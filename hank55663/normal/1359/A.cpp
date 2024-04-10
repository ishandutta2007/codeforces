#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int n;
bool cmp(LL *a,LL *b){
    for(int i = 0;i<n;i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}
bool check(LL *b){
    for(int i= 1;i<n;i++){
        if(b[i]<=b[i-1])return false;
    }
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int need=n/k;
        if(m<=need){
            printf("%d\n",m);
        }
        else{
            m-=need;
           // printf("%d\n",(m+n-2)/(n-1));
            printf("%d\n",need-(m+k-2)/(k-1));
        }
    }
}
/*
2 11 14
9 3


000111222
001112220
*/