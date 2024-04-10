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
#define N 200005
#define rank Rank
#define index Index
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[105];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    int b[105];
    for(int i = 0;i<k;i++){
        scanf("%d",&b[i]);
    }
    sort(b,b+k);
    reverse(b,b+k);
    int now=0;
    for(int i = 0;i<n;i++){
        if(a[i]==0){
            a[i]=b[now++];
        }
    }
    for(int i =1;i<n;i++){
        if(a[i]<a[i-1]){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}