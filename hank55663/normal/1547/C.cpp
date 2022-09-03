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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
void solve(){
    int n,m,k;
    scanf("%d %d %d",&k,&n,&m);
    queue<int> q1,q2;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        q1.push(x);
    }
 //    printf("?\n");
    for(int i = 0;i<m;i++){
        int x;
        scanf("%d",&x);
        q2.push(x);
    }
    vector<int> ans;
    while(q1.size()||q2.size()){
       // printf("?\n");
        if(q1.size()&&q1.front()==0){
            k++;
            ans.pb(0);
            q1.pop();
        }
        else if(q1.size()&&q1.front()<=k){
            ans.pb(q1.front());
            q1.pop();
        }
        else if(q2.size()&&q2.front()==0){
            ans.pb(q2.front());
            q2.pop();
            k++;
        }
        else if(q2.size()&&q2.front()<=k){
              ans.pb(q2.front());
            q2.pop();
        }
        else{
            printf("-1\n");
            return;
        }
    }
    for(auto it:ans)printf(
    "%d ",it
    );
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}