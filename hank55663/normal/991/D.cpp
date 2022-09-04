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
    char c[2][105];
    scanf("%s",c[0]);
    scanf("%s",c[1]);
    int ans=0;
    for(int i=0;c[0][i]!=0;i++){
        if(c[0][i]=='0'&&c[1][i]=='0'){
            c[0][i]='X',c[1][i]='X';
            ans++;
            if(i!=0&&c[1][i-1]=='0'){
                c[1][i-1]='X';
            }
            else if(i!=0&&c[0][i-1]=='0'){
                c[0][i-1]='X';
            }
            else if(c[0][i+1]=='0'){
                c[0][i+1]='X';
            }
            else if(c[1][i+1]=='0'){
                c[1][i+1]='X';
            }
            else  ans--;
        }
    }
    printf("%d\n",ans);
    return 0;
}