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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[105];
        scanf("%s",c);
        int z=0,o=0;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='0')z=1;
            else o=1;
        }
        if(z&&o){
            for(int i = 0;c[i]!=0;i++){
                printf("01");
            }
            printf("\n");
        }
        else{
            printf("%s\n",c);
        }
    }
}

/*

3 2 +2
3 1 +1
2 1 +1
3 1 +1
2 1 +1

*/
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/