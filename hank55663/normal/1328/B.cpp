#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        k--;
        for(int i = n-1;i>=1;i--){
            if(k>=n-i)k-=n-i;
            else{
                char c[100005];
                fill(c+1,c+n+1,'a');
                c[n+1]=0;
                c[i]='b';
                c[n-k]='b';
                printf("%s\n",c+1);
                break;
            }
        }
    }
}