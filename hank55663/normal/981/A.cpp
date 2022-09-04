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
#define last Last
using namespace std;
typedef long long LL;
int main(){
	char c[155];
    scanf("%s",c);
    int ans=0;
    for(int i=0;c[i]!=0;i++){
        for(int j=1;c[j]!=0;j++){
            int ok=0;
            for(int k=0;i+k<j;k++){
                if(c[i+k]!=c[j-k])
                ok=1;
            }
            if(ok){
                ans=max(ans,j-i+1);
            }
        }
    }
    printf("%d\n",ans);
}