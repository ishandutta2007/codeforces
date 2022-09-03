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
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
int main(){
    int cnt[4];
    scanf("%d %d %d %d",&cnt[0],&cnt[1],&cnt[2],&cnt[3]);
    char c[55][55];
    MEM(c);
    vector<int> v;
    v.pb(1),v.pb(2),v.pb(3),v.pb(4);
    int ok=0;
    for(int i=0;i<50;i++){
        int st=i%4;
        int stop;
        for(int j=0;j<50;j++){
            c[i][j]=st+'A';
            cnt[st]--;
            if(cnt[st]==0){
                int next=(st+1)%4;
                stop=j;
                for(;j!=50;j++){
                    if(i!=0&&c[i-1][j]==next+'A')
                    cnt[next]++;
                    c[i][j]=next+'A';
                }
                cnt[next]--;
                ok=1;
                break;
            }
            st=(st+1)%4;
        }
        if(ok){
            i++;
            int next=(st+1)%4;
            for(int j=0;j<50;j++){
                c[i][j]=next+'A';
                if(j<stop&&c[i-1][j]==c[i][j]){
                    cnt[next]++;
                }
            }
            int now=0;
            while(now!=4){
                while(cnt[now]==0)now++;
                if(now==4)break;
                i++;
                for(int j=0;j<50;j++){
                    c[i][j]=st+'A';
                }
                i++;
                for(int j=0;j<50;j++){
                    if(j&1&&cnt[now]){
                        cnt[now]--;
                        c[i][j]=now+'A';
                    }
                    else{
                        c[i][j]=st+'A';
                    }
                }
            }
            printf("%d 50\n",i+1);
            for(int j=0;j<=i;j++){
                printf("%s\n",c[j]);
            }
            break;
        }
    }
}