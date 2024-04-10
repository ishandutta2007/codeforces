#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
int main(){
    char c[5]="RBYG";
    sort(c,c+4);
    char cc[105];
    scanf("%s",cc);
    do{
        int r=0,b=0,y=0,g=0;
        int ok=1;
        for(int i =0;cc[i]!=0;i++){
            if(cc[i]=='!'){
                if(c[i%4]=='R')r++;
                if(c[i%4]=='B')b++;
                if(c[i%4]=='Y')y++;
                if(c[i%4]=='G')g++;
            }
            else if(cc[i]!=c[i%4]){
                ok=0;
            }
        }
        if(ok){
            printf("%d %d %d %d\n",r,b,y,g);
            break;
        }
    }while(next_permutation(c,c+4));
    return 0;
}