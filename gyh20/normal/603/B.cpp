#include <cstdio>
using namespace std;
#define M 1000000007
#define ll long long
#define re register
int p,k;
inline int ksm(re int x,re int y){int sum=1;while(y){if(y&1)sum=1ll*sum*x%M;x=1ll*x*x%M;y>>=1;}return sum;}
int main(){
    scanf("%d%d",&p,&k);
    if(!k){printf("%d\n",ksm(p,p-1));return 0;}
    if(k==1){printf("%d\n",ksm(p,p));return 0;}
    int m=1,x=k;
    while(x!=1)++m,x=(ll)x*k%p;
	printf("%d\n",ksm(p,(p-1)/m));return 0;
}