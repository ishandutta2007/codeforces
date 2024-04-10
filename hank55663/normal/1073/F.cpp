#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
vector<int> v[200005];
/*int p[200005];
void dfs(int x,int f){
    p[x]=f;
    for(auto it:v[x]){
        if(it!=f)
            dfs(it,x);
    }
}*/
int ok[200005];
pii dfs2(int x,int f){
    pii p =mp(0,x);
    for(auto it:v[x]){
        if(ok[it]&&it!=f){
            p=max(p,dfs2(it,x));
        }
    }
    p.x++;
    return p;
}
vector<pii> ch[200005];
void dfs3(int s,int x,int f,int d){
    if(v[x].size()==1)
    {
        ch[s].pb(mp(d,x));
    }
    for(auto it:v[x]){
        if(it!=f&&!ok[it]){
            dfs3(s,it,x,d+1);
        }
    }
    if(s==x){
        sort(ch[s].begin(),ch[s].end());
        reverse(ch[s].begin(),ch[s].end());
    }
}
vector<int> stk;
bool dfs4(int x,int f,int t){
    stk.pb(x);
    if(x==t){
        return true;
    } 
    for(auto it:v[x]){
        if(it!=f&&ok[it]){
            if(dfs4(it,x,t)){
                return true;
            }
        }
    }
    stk.pop_back();
    return false;
}
int dis[200005];
void dfs5(int x,int f,int d){
    dis[x]=d;
    for(auto it:v[x]){
        if(it!=f&&ok[it]){
            dfs5(it,x,d+1);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
   /* dfs(1,0);
    if(v[1].size()==1){
        p[1]=v[1][0];
    }*/
   // printf("?\n");
    int a,b,c,d;
    int x=0;
    for(int i=1;i<=n;i++){
        if(v[i].size()>=3){
            x=i;
        }
    }
 //   if(x!=0){
        fill(ok,ok+n+1,1);
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(v[i].size()==1)
            q.push(i),ok[i]=0;
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto it:v[x]){
                if(ok[it]&&v[it].size()<3){
                    q.push(it);
                    ok[it]=0;
                }
            }
        }
       /* for(int i=1;i<=n;i++)
        printf("%d ",ok[i]);
        printf("\n");*/
        for(int i=1;i<=n;i++){
            if(ok[i]){
                int cnt=0;
                for(auto it:v[i])
                    if(ok[it])cnt++;
                if(cnt<=1)
                dfs3(i,i,0,0);
             //   break;
            }
        }
       // printf("!\n");
        pii p=dfs2(x,0);
        if(p.x!=1){
            pii p2=dfs2(p.y,0);
            dfs4(p.y,0,p2.y);
            int mid=stk[stk.size()/2];
            int l=(p2.x-1)/2,r=p2.x/2;
            int acx=-1,ai=0,bdx=-1;
            MEMS(dis);
            dfs5(mid,0,0);
            //printf("%d\n",mid);
            for(int i=1;i<=n;i++){
                if(dis[i]==r&&ch[i].size()>=2){
                    if(ch[i][0].x+ch[i][1].x>acx){
                        acx=ch[i][0].x+ch[i][1].x;
                        a=ch[i][0].y;
                        c=ch[i][1].y;
                        ai=i;
                    }
                }
            }
         //   printf("%d %d %d\n",l,r,ai);
            //printf("%d\n",ai);
            dfs5(ai,0,0);
            for(int i=1;i<=n;i++){
                if(dis[i]==stk.size()-1&&ch[i].size()>=2){
                    if(ch[i][0].x+ch[i][1].x>bdx){
                        bdx=ch[i][0].x+ch[i][1].x;
                        b=ch[i][0].y;
                        d=ch[i][1].y;
                    }
                }
            }
        }
        else{
            a=ch[x][0].y;
            b=ch[x][1].y;
            c=ch[x][2].y;
            d=ch[x][3].y;
        }
    /*
    }
    else{
       // printf("?\n");
        a=b=c=d=0;
        for(int i=1;i<=n;i++){
            if(v[i].size()==1){
                if(a==0)
                a=i;
                else{
                    c=i;
                    break;
                }
            }
        }
        d=v[c][0];
        for(auto it:v[d]){
            if(it!=c)
            b=it;
        }
    }*/
    printf("%d %d\n%d %d\n",a,b,c,d);
}
/*
21 3
3 1
4 1
5 1
6 2
7 2
8 2
1 2
9 1
9 10
9 11
9 12
10 13
10 14
10 15
11 16
11 17
11 18
12 19
12 20
12 21

*/