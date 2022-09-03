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
#define MXN 3005
#define next Next
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
 /*   if(n==1){
        printf("0\n");
    }
    else{*/
        int vis[500000];
        fill(vis,vis+500000,0);
        vis[0]=1;
        int last=0;
        vector<int> v;
        vis[x]=1;
        while(true){
            int next=last+1;
            while(vis[next])next++;
            if(next>=(1<<n))
            break;
            v.pb(last^next);
            vis[next^x]=1;
            last=next;
        }
        printf("%d\n",v.size());
        if(v.size()){
        for(auto it:v)
        printf("%d ",it);
        printf("\n");}
   // }
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/