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
#define MXN 15000
int f[200005];
int Size[200005];
int Find(int x){
    if(f[x]==x)return x;
    return Find(f[x]);
}
vector<int> stk;
vector<pii> edge;
void merge(int x,int y){
    edge.pb(mp(x,y));
    if(Find(x)==Find(y)){
        stk.pb(0);
        return ;
    }
    int fx=Find(x),fy=Find(y);
    if(Size[fx]>Size[fy]){
        swap(fx,fy);
    }
    f[fx]=fy;
    Size[fy]+=Size[fx];
    stk.pb(fx);
}
void recover(){
    if(stk.back()==0){
        edge.pop_back();
        stk.pop_back();
        return ;
    }
    int fx=stk.back();
    stk.pop_back();
    edge.pop_back();
    Size[f[fx]]-=Size[fx];
    f[fx]=fx;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        f[i]=i;
        Size[i]=1;
    }
    vector<pair<int,pii> > v;//query;
    for(int i = 0;i<m;i++){
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);
        if(x>y)swap(x,y);
        v.pb(mp(op,mp(x,y)));
    }
    int SIZE=600;
    set<pii> save;
    string ans;
    int last=0;
    for(int i = 0;i<m;i++){
        if(i%SIZE==0){
            edge.clear();
            stk.clear();
            for(int j=1;j<=n;j++)
                f[j]=j,Size[j]=1;
            set<pii> s;
            for(int j =i;j<i+SIZE&&j<m;j++){
                if(v[j].x==1){
                    s.insert(v[j].y);
                    int x=v[j].y.x%n+1,y=v[j].y.y%n+1;
                    if(x>y)swap(x,y);
                    s.insert(mp(x,y));
                }
            } 
            vector<pii> v1,v2;
            for(auto it:save){
                if(s.find(it)==s.end()){
                    v1.pb(it);
                }
                else{
                    v2.pb(it);
                }
            }
            for(auto it:v1){
                merge(it.x,it.y);
            }
            for(auto it:v2){
                merge(it.x,it.y);
            }
        }
        if(v[i].x==1){
            int qx=v[i].y.x,qy=v[i].y.y;
            if(last){
                qx=qx%n+1,qy=qy%n+1;
            }
            if(qx>qy)swap(qx,qy);
            if(save.find(mp(qx,qy))==save.end()){
               // printf("add %d %d\n",qx,qy);
                save.insert(mp(qx,qy));
                merge(qx,qy);
            }
            else{
                vector<pii> tmp;
                while(edge.back()!=mp(qx,qy)){
                    tmp.pb(edge.back());
                    recover();
                }
                save.erase(mp(qx,qy));
                recover();
                while(tmp.size()){
                    merge(tmp.back().x,tmp.back().y);
                    tmp.pop_back();
                }
            }
        }
        else{
            int qx=v[i].y.x,qy=v[i].y.y;
            if(last){
                qx=qx%n+1,qy=qy%n+1;
            }
            if(Find(qx)==Find(qy)){
                printf("1");
                last=1;
            }
            else{
                printf("0");
                last=0;
            }
        }
    }
    printf("\n");
    return 0;
}
/*

Gah kove bababa
Gah kove bababa
*/