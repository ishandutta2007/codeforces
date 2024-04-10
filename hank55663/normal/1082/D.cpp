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
#define cpdd const pdd
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define Line pll
#define EPS 1e-12
int main(){
    int n;
    scanf("%d",&n);
    int a[505];
    int tot=0;
    vector<int> x,y;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        tot+=a[i];
        if(a[i]==1){
            y.pb(i);
        }
        else{
            x.pb(i);
        }
    }
    if(tot<2*(n-1)){
        printf("NO\n");
    }
    else{
        printf("Yes %d\n",x.size()+min((int)y.size(),2)-1);
        printf("%d\n",n-1);
        if(y.empty()){
        }
        else if(y.size()==1){
            printf("%d %d\n",x[0],y[0]);
        }
        else{
            for(int i=0;i<x.size();i++)
            a[x[i]]-=2;
            printf("%d %d\n",x[0],y[0]);
            printf("%d %d\n",x.back(),y[1]);
            int now=0;
            for(int i=2;i<y.size();i++){
                while(a[x[now]]==0)now++;
                printf("%d %d\n",x[now],y[i]);
                a[x[now]]--;
            }
        }
        for(int i=1;i<x.size();i++)
            printf("%d %d\n",x[i-1],x[i]);
    }
}