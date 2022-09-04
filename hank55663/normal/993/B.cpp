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
    int n,m;
    scanf("%d %d",&n,&m);
    pii p[20],p1[20];
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a>b)
        swap(a,b);
        p[i]=mp(a,b);
    }
    set<int> ans,ans2;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a>b)
        swap(a,b);
        p1[i]=mp(a,b);
    }
    int ok=1;
    for(int i=0;i<n;i++){
        set<int> s;
        for(int j=0;j<m;j++){
            if(p[i].x==p1[j].x&&p[i].y==p1[j].y)
            continue;
            if(p[i].x==p1[j].y||p[i].x==p1[j].x){
                s.insert(p[i].x);
            }
            if(p[i].y==p1[j].y||p[i].y==p1[j].x){
                s.insert(p[i].y);
            }
        }
        if(s.size()==1)
        for(auto it:s)
        ans.insert(it);
        if(s.size()==2){
           // printf("%d %d\n",p[i].x,p[i].y);
            ok=0;
        }
    }
    for(int i=0;i<m;i++){
        set<int> s;
        for(int j=0;j<n;j++){
            if(p[j].x==p1[i].x&&p[j].y==p1[i].y)
            continue;
            if(p[j].x==p1[i].y||p[j].y==p1[i].y){
                s.insert(p1[i].y);
            }
            if(p[j].x==p1[i].x||p[j].y==p1[i].x){
                s.insert(p1[i].x);
            }
        }
        if(s.size()==1)
        for(auto it:s)
        ans2.insert(it);
         if(s.size()==2){
           // printf("%d %d\n",p1[i].x,p1[i].y);
            ok=0;
        }
    }
    if(ans.empty()||ans2.empty()||!ok)
    printf("-1\n");
    else if(ans.size()==1)
    printf("%d\n",*ans.begin());
    else
    printf("0\n");
}