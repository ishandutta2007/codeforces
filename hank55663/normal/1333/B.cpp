#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[100005];
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int b[100005];
        for(int i = 0;i<n;i++){
            scanf("%d",&b[i]);
        }
        int pos=0,neg=0,ok=1;
        for(int i = 0;i<n;i++){

            if(a[i]!=b[i]){
                if(b[i]>a[i]){
                    if(!pos)ok=0;
                }
                else if(b[i]<a[i]){
                    if(!neg)ok=0;
                }
            }
            if(a[i]>0)pos=1;
            if(a[i]<0)neg=1;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}
/*

*/