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
#define MXN 1500
#define hash Hash
int main(){
    int n;
    scanf("%d",&n);
    int last=0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x%2==0){
            printf("%d\n",x/2);
        }
        else{
            if(x<0){
                if(last){
                    printf("%d\n",x/2-1);
                    
                }
                else{
                    printf("%d\n",x/2);
                }
            }
            else{
                if(last){
                    printf("%d\n",x/2);
                }
                else{
                    printf("%d\n",x/2+1);
                }
            }
            last^=1;
        }
    }
}