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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    vector<int> ans;
    int cnt=0;
    set<int> s;
    set<int> vis;
    for(int i = 0;i<n;i++){
        cnt++;
        int a;
        scanf("%d",&a);
        if(a>0){
            if(s.find(a)!=s.end()||vis.find(a)!=vis.end()){
                printf("-1\n");
                return 0;
            }
            s.insert(a);
            vis.insert(a);
        }
        else if(a<0){
            if(s.find(-a)==s.end()){
                printf("-1\n");
                return 0;
            }
            s.erase(-a);
        }
        if(s.empty()){
            ans.pb(cnt);
            cnt=0;
            vis.clear();
        }
    }
    if(!s.empty()){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",ans.size());
    for(auto it:ans)
    printf("%d ",it);
    printf("\n");
}