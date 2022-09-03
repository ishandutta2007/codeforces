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

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[105];
        for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
        int Min=1e9,Mini=1;
        while(Mini!=n){
            Min=1e9;
            int tmp=Mini;
            for(int i=Mini;i<n;i++){
                if(a[i]<Min){
                    Min=a[i];
                    Mini=i+1;
                }
            }
            for(int j=Mini-1;j>tmp;j--){
                swap(a[j],a[j-1]);
            }
            if(a[tmp]<a[tmp-1])swap(a[tmp],a[tmp-1]);
            /*for(int i = 0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");*/
        }
        for(int i = 0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");
    }
}