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
#define MXN 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[200005];
        scanf("%s",c);
        vector<int> v;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='o'&&c[i+1]=='n'&&c[i+2]=='e')v.pb(i+1),i++;
            else if(c[i]=='t'&&c[i+1]=='w'&&c[i+2]=='o'&&c[i+3]=='n'&&c[i+4]=='e')v.pb(i+2),i+=2;
            else if(c[i]=='t'&&c[i+1]=='w'&&c[i+2]=='o')v.pb(i+1),i++;
        }
        printf("%d\n",v.size());
        for(auto it:v)printf("%d ",it+1);
        printf("\n");
    }
}
/*
7 8
1 3 1
2 3 9
2 4 3
2 5 4
4 5 7
3 6 6
3 7 7
6 7 8

*/