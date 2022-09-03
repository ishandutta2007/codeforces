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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int f[10005];
void KMP(int *a,int n){
    f[0]=-1;
    int j=-1;
    for(int i = 1;i<n;i++){
        while(j!=-1&&a[i]!=a[j+1])j=f[j];
        if(a[i]==a[j+1])j++;
        f[i]=j;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[1005];
    a[0]=0;
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i = n;i>=1;i--)
        a[i]-=a[i-1];
    for(int i = 0;i<n;i++)
        a[i]=a[i+1];
    KMP(a,n);
    vector<int> v;
    int k=f[n-1];
    while(k!=-1){
        v.pb(n-k-1);
        k=f[k];
    }
    v.pb(n);
    sort(v.begin(),v.end());
    printf("%d\n",v.size());
    for(auto it:v)
        printf("%d ",it);
    printf("\n");
}

/*

23847657 
23458792534

102334155
111111111 
111111111
*/