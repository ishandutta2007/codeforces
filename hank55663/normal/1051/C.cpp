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
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
typedef long long LL;
int main(){
    int n;
    scanf("%d",&n);
    vector<pii> v;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        v.pb(mp(x,i));
    }
    sort(v.begin(),v.end());
    set<pii> single;
    set<pii> multi;
    pii temp=mp(0,0);
    int cnt[105];
    fill(cnt,cnt+105,0);
    for(int i=0;i<v.size();i++){
        if((i==0||v[i].x!=v[i-1].x)&&(i==v.size()-1||v[i].x!=v[i+1].x)){
           // if(i==v.size()-1||v[i].x!=v[i+1].x){
                single.insert(v[i]);
           // }
        }
        else{
            multi.insert(v[i]);
        }
        cnt[v[i].x]++;
        if(cnt[v[i].x]==3){
            temp=v[i];
        }
    }
    char ans[105];
    fill(ans,ans+n+5,0);
    if(single.size()&1){
        if(temp!=mp(0,0)){
            int now=0;
            for(auto it:single){
                ans[it.y]=now+'A';
             //   printf("%d\n",it.y);
                now=1-now;
            }
            ans[temp.y]=now+'A';
            multi.erase(temp);
           // printf("! %d\n",temp.y);
            for(auto it:multi){
                ans[it.y]='A';
               // printf("%d\n",it.y);
            }
            printf("YES\n%s\n",ans);
        }
        else 
        printf("NO\n");
    }
    else{
        printf("YES\n");
        int now=0;
        for(auto it:single){
            ans[it.y]=now+'A';
            now=1-now;
        }
        for(auto it:v){
            if(single.find(it)==single.end())
            ans[it.y]='A';
        }
        printf("%s\n",ans);
    }
    return 0;
}