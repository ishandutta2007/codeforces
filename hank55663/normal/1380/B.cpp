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
void solve(){
    char c[200005];
    map<char,int> m;
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        m[c[i]]++;
    }
    for(int i = 0;c[i]!=0;i++){
        int Max=0;
        char cc;
        for(auto it:m){
            if(it.y>Max)Max=it.y,cc=it.x;
        }
        if(cc=='R')printf("P");
        if(cc=='S')printf("R");
        if(cc=='P')printf("S");
       // m[c[i]]--;
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}