#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
int X[8]={-1,-1,-1,0,0,1,1,1};
int Y[8]={-1,0,1,-1,1,-1,0,1};
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[1010][1010];
    MEM(c);
    for(int i=2;i<=n+1;i++)
        scanf("%s",c[i]+2);
    for(int i=2;i<=n+1;i++){
        for(int j=2;j<=m+1;j++){
            if(c[i][j]=='#'){
                int ook=0;
                for(int k=0;k<8;k++){
                    int x=X[k]+i,y=Y[k]+j;
                    int ok=1;
                    for(int l=0;l<8;l++){
                        if(c[x+X[l]][y+Y[l]]!='#'){
                            ok=0;
                        }
                    }
                    if(ok){
                        ook=1;
                        break;
                    }
                }
                if(!ook){
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    return 0;
}