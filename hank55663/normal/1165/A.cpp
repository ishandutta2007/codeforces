#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    char c[200005];
    scanf("%s",c);
    int ans=0;
    for(int i = n-x;i<n;i++){
        if(c[i]=='1'){
            if(i!=n-y-1)
            ans++;
        }
        else{
            if(i==n-y-1)
            ans++;
        }
    }
    printf("%d\n",ans);
}