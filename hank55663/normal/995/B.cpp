#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    int n;
    scanf("%d",&n);
    int a[305];
    for(int i=0;i<2*n;i++)
    scanf("%d",&a[i]);
    int ans=0;
    for(int i=0;i<2*n;i+=2){
        for(int j=i+1;j<2*n;j++){
            if(a[i]==a[j]){
                for(int k=j;k>i+1;k--)
                swap(a[k],a[k-1]),ans++;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}