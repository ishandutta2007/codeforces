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
#define less Less
int main(){
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=2;i<n;i++){
        if(a[i-1]+a[i-2]>a[i]){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}