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
#define MXN 200005
vector<int> v[4];
int main(){
    int a[4];
    scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
    if(a[0]==0&&a[1]==0){
        if(a[2]-a[3]<=1&&a[2]>a[3]){
            printf("YES\n");
            for(int i = 0;i<a[3];i++){
                printf("2 3 ");
            }
            if(a[2]!=a[3])printf("2");
            printf("\n");
        }
        else if(a[3]-a[2]<=1&&a[3]>=a[2]){
            printf("YES\n");
            for(int i = 0;i<a[2];i++){
                printf("3 2 ");
            }
            if(a[2]!=a[3])printf("3");
            printf("\n");
        }
        else{
            printf("NO\n");
        }
    }
    else if(a[2]==0&&a[3]==0){
        if(a[0]-a[1]<=1&&a[0]>a[1]){
            printf("YES\n");
            for(int i = 0;i<a[1];i++){
                printf("0 1 ");
            }
            if(a[0]!=a[1])printf("0");
            printf("\n");
        }
        else if(a[1]-a[0]<=1&&a[1]>=a[0]){
            printf("YES\n");
            for(int i = 0;i<a[0];i++){
                printf("1 0 ");
            }
            if(a[1]!=a[0])printf("1");
            printf("\n");
        }
        else{
            printf("NO\n");
        }
    }
    else{
        if(a[1]<a[0]||a[2]<a[3]){
            printf("NO\n");
        }
        else{
            a[1]-=a[0];
            a[2]-=a[3];
            if(abs(a[1]-a[2])>1){
                printf("NO\n");
            }
            else{
                printf("YES\n");
                if(a[1]>a[2]){
                    printf("1 ");
                    for(int i = 0;i<a[0];i++)
                    printf("0 1 ");
                    for(int i = 0;i<a[2];i++)
                    printf("2 1 ");
                    for(int i = 0;i<a[3];i++)
                    printf("2 3 ");
                    printf("\n");
                }
                else if(a[1]==a[2]){
                    for(int i = 0;i<a[0];i++)
                    printf("0 1 ");
                    for(int i = 0;i<a[1];i++)
                    printf("2 1 ");
                    for(int i = 0;i<a[3];i++)
                    printf("2 3 ");
                    printf("\n");
                }
                else if(a[1]<a[2]){
                    //printf("1 ");
                    for(int i = 0;i<a[0];i++)
                    printf("0 1 ");
                    for(int i = 0;i<a[1];i++)
                    printf("2 1 ");
                    for(int i = 0;i<a[3];i++)
                    printf("2 3 ");
                    printf("2\n");
                }
            }
        }
    }
}