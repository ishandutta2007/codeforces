#include<bits/stdc++.h>
using namespace std;
#pragma optimizer(-Ofast)
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
#define pdd pair<double,double>
#define cpdd const pdd
#define rank Rank
#define MXN 15000
bool check(char *cc,char *c){
    for(int i = 0;i<3;i++)
    if(c[0]==cc[i]&&c[1]==cc[(i+1)%3])return false;
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    char c[4],c1[4];
    scanf("%s %s",c,c1);
    printf("YES\n");
    if(c[0]==c1[0]&&c1[1]!=c[1]&&c1[1]!=c[0]&&c[1]!=c[0]){
        for(int i = 0;i<n;i++)
        printf("%c",c1[1]);
        for(int i = 0;i<n;i++)
        printf("%c",c[1]);
        for(int i = 0;i<n;i++)
        printf("%c",c1[0]);
        printf("\n");
    }
    else if(c[1]==c1[1]&&c1[0]!=c[0]&&c1[1]!=c1[0]&&c[1]!=c[0]){
        for(int i = 0;i<n;i++)
        printf("%c",c1[1]);
        for(int i = 0;i<n;i++)
        printf("%c",c[0]);
        for(int i = 0;i<n;i++)
        printf("%c",c1[0]);
        printf("\n");
    }
    else if(c[0]==c1[1]&&c[1]==c1[0]&&c[0]!=c[1]){
         for(int i = 0;i<n;i++)
        printf("%c",c[0]);
        for(int i = 0;i<n;i++)
        printf("%c",'c'-c[0]+'b'-c[1]+'a');
        for(int i = 0;i<n;i++)
        printf("%c",c[1]);
        printf("\n");
    }
    else{
        char cc[10]="abc";
        do{
            if(check(cc,c)&&check(cc,c1)){
                for(int i = 0;i<n;i++)
                printf("%s",cc);
                printf("\n");
                return 0;
            }
        }while(next_permutation(cc,cc+3));
    }
    return 0;
}