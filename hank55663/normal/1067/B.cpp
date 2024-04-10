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
vector<int> v[100005];
int degree[100005];
int cnt[100005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
        degree[a]++;
        degree[b]++;
    }
    queue<int> q1;
    vector<int> v2,v3;
    for(int i=1;i<=n;i++){
        if(degree[i]==1)
        q1.push(i);
    }
    int tot=0;
    while(!q1.empty()){
        tot++;
        while(!q1.empty()){
            int x=q1.front();
            q1.pop();
            for(auto it:v[x]){
                if(cnt[it]==0&&degree[it]>1)
                v3.pb(it);
                degree[it]--;
                cnt[it]++;
                if(degree[it]==1)
                v2.pb(it);
            }
        }
        for(auto it:v2){
            if(cnt[it]<3){
                printf("No\n");
                return 0;
            }
            q1.push(it);
        }
        /*for(auto it:v2)
        printf("%d ",it);
        printf("\n");
        for(auto it:v3)
        printf("%d ",it);
        printf("\n");*/
        if(v2.size()!=v3.size()){
            printf("No\n");
            return 0;
        }
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());
        for(int i=0;i<v2.size();i++){
            if(v2[i]!=v3[i]){
                printf("No\n");
                return 0;
            }
        }
        v2.clear();
        v3.clear();
        if(q1.size()==1)
        break;
    }
    if(tot!=k||q1.size()!=1){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
}