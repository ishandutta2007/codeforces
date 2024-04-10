#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
bool solve(){
    int n;
    scanf("%d",&n);
    char c[105][105];
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
    }
    int ans=0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k =j+1;k<n;k++){
                if(c[i][j]=='C'&&c[i][k]=='C')ans++;
                if(c[j][i]=='C'&&c[k][i]=='C')ans++;
            }
        }
    }
    printf("%d\n",ans);
    return true;
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();//solve();
}
/*

4 7 2 1 7 4 3 1 7 2
*/