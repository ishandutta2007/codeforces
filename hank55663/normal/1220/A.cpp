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
#define MXN 15000
int main(){
    map<char,int> m;
    int n;
    scanf("%d",&n);
    char c[100005];
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        m[c[i]]++;
    }
    int z=m['z'],o=m['n'];
    for(int i = 0;i<o;i++)printf("1 ");
    for(int  i=0;i<z;i++)printf("0 ");
    printf("\n");
    return 0;
}