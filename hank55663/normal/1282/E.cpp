
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
vector<int> v[100005];
void insert(set<pii> &s, pii p){
    if(s.find(p)!=s.end()){
        s.erase(p);
    }
    else{
        s.insert(p);
    }
}
vector<int> stk;
void dfs(int x,int f){
   // printf("%d\n",x);
    if(!stk.empty()&&x==stk[0])return;
    stk.pb(x);
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 1;i<=n;i++)
            v[i].clear();
        set<pii> s;
        map<pii,vector<int> > m;
        int node[100005][3];
        for(int i = 1;i<=n-2;i++){
            int a[3];
            for(int i = 0;i<3;i++)
                scanf("%d",&a[i]);
            sort(a,a+3);
            node[i][0]=a[0];
            node[i][1]=a[1];
            node[i][2]=a[2];
            m[mp(a[0],a[1])].pb(i);
            m[mp(a[0],a[2])].pb(i);
            m[mp(a[1],a[2])].pb(i);
            insert(s,mp(a[0],a[1]));
            insert(s,mp(a[0],a[2]));
            insert(s,mp(a[1],a[2]));
        }
        for(auto it:s){
            v[it.x].pb(it.y);
            v[it.y].pb(it.x);
        }
        dfs(1,v[1][0]);
        for(auto it:stk)
        printf("%d ",it);
        int cnt[200005];
        fill(cnt,cnt+n+1,0);
        queue<int> q;
        for(int i = 0;i<n;i++){
            int a=stk[i],b=stk[(i+1)%n];
            if(a>b){
                swap(a,b);
            }
            for(auto it:m[mp(a,b)]){
                cnt[it]++;
                if(cnt[it]==2)
                    q.push(it);
            }
        }
        printf("\n");
        while(!q.empty()){
            int x=q.front();
            printf("%d ",x);
            q.pop();
            for(int i =0;i<3;i++)
                for(int j=i+1;j<3;j++)
                    for(auto it:m[mp(node[x][i],node[x][j])]){
                        if(++cnt[it]==2)
                            q.push(it);
                    }
        }
        printf("\n");
        stk.clear();
    }
}