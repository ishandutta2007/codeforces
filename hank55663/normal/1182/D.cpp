#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
vector<int> v[100005];
vector<int> dep[100005];
pii dfs(int x,int f){
    pii Max=mp(0,x);
    for(auto it:v[x]){
        if(it!=f){
            Max=max(dfs(it,x),Max);
        }
    }
    Max.x++;
    return Max;
}
int mydep[100005];
void dfs2(int x,int f,int d){
    dep[d].pb(x);
    mydep[x]=d;
    for(auto it:v[x]){
        if(it!=f){
            dfs2(it,x,d+1);
        }
    }
}
vector<int> stk;

bool dfs3(int x,int f,int t){
   // printf("%d %d\n",x,f);
    stk.pb(x);
    if(x==t)return true;

    for(auto it:v[x]){
        if(it!=f){
            if(dfs3(it,x,t)){
                return true;
            }
        }
    }
    stk.pop_back();
    return false;
}
int candi;
bool check(int x,int flag=0){
   // printf("%d\n",x);
    for(int i = 0;i<100005;i++)
        dep[i].clear();
    //printf("!\n");
    dfs2(x,0,0);
   // printf("?\n");
    for(int i = 0;;i++){
        if(dep[i].empty()){
            break;
        }
        int x=v[dep[i][0]].size();
        int Min=x,Mini=dep[i][0];
        int ok=1;
        for(auto it:dep[i]){
            if(x!=v[it].size()){
                if(v[it].size()<Min){
                    Min=v[it].size();
                    Mini=it;
                }
                ok=0;
                //return false;
            }
        }
        if(!ok&&flag){
            candi=Mini;
          //  printf("%d\n",candi);
            while(v[candi].size()!=1){
                for(auto it:v[candi]){
                    if(mydep[it]>mydep[candi]){
                        candi=it;
                        break;
                    }
                }
            }
        }
        if(!ok)
        return false;
    }
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    pii p1=dfs(1,0);
    pii p2=dfs(p1.y,0);
    if(check(p1.y)){
        printf("%d\n",p1.y);
    }
    else if(check(p2.y)){
        printf("%d\n",p2.y);
    }
    else{
       // printf("?\n");
        dfs3(p1.y,0,p2.y);
       // printf("%d %d\n",p1.y,p2.y);
        if(stk.size()%2==0){
            printf("-1\n");
        }
        else{
            
            int mid=stk.size()/2;
            //printf("%d\n",stk[mid]);
            if(check(stk[mid],1)){
                printf("%d\n",stk[mid]);
            }
            else{
                //printf("%d\n",candi);
                if(check(candi)){
                    printf("%d\n",candi);
                }
                else{
                    printf("-1\n");
                }
            }
        }
    }
}