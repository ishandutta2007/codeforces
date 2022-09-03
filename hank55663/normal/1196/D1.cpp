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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define next Next
int main() {
    int q;
    scanf("%d",&q);
    while(q--){
        int n,k;
        scanf("%d %d",&n,&k);
        char c[200005];
        scanf("%s",c);
        char tmp[3][10]={"RGB","GBR","BRG"};
      //  printf("%s %s %s\n",tmp[0],tmp[1],tmp[2]);
        int ans=1e9;
        for(int i = 0;i<3;i++){
            queue<int> q;
            int sum=0;
            for(int j=0;j<k-1;j++){
                if(c[j]!=tmp[i][j%3]){
                    q.push(1);
                    sum++;
                }
                else{
                    q.push(0);
                }
            }       
            for(int j = k-1;j<n;j++){
                if(c[j]!=tmp[i][j%3]){
                    q.push(1);
                    sum++;
                }
                else{
                    q.push(0);
                }
                ans=min(ans,sum);
                sum-=q.front();
                q.pop();
            }
        }
        printf("%d\n",ans);
    }
}