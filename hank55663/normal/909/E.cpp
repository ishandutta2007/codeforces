#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
vector<int> v[100005];
int degree[100005];
int e[100005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++)
        scanf("%d",&e[i]);
    for(int i = 0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[b].pb(a);
        degree[a]++;
    }
    queue<int> q[2];
    for(int i = 0;i<n;i++){
        if(degree[i]==0){
            q[e[i]].push(i);
        }
    }
    int cnt=0;
    for(int i = 0;;i++){
        while(q[0].size()){
            int x=q[0].front();
            q[0].pop();
            cnt++;
            for(auto it:v[x]){
                if(--degree[it]==0){
                    q[e[it]].push(it);
                }
            }
        }
        if(cnt==n){
            printf("%d\n",i);
            break;
        }
        while(q[1].size()){
            int x=q[1].front();
            q[1].pop();
            cnt++;
            for(auto it:v[x]){
                if(--degree[it]==0){
                    q[e[it]].push(it);
                }
            }
        }
    }
}