#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
vector<int> v[200005];
int degree[200005];
int val[200005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i = 1;i<=n;i++){
            v[i].clear();
            degree[i]=0;
            val[i]=0;
        }
        for(int i = 1;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
            degree[x]++;
            degree[y]++;
        }
        if(k==1){
            printf("%d\n",n-1);
            continue;
        }
        int cnt=0;
        queue<int> q;
        for(int i = 1;i<=n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cnt+=val[x]/k;
            val[x]%=k;
          //  printf("%d %d\n",x,val[x]/k);
            if(val[x]%k==0){
           // printf("!%d %d\n",x,val[x]/k);
            for(auto it:v[x]){
                degree[it]--;
                val[it]++;
                if(degree[it]==1)q.push(it);
            }
            }
        }
        for(int i = 1;i<=n;i++)cnt+=val[i]/k;
        printf("%d\n",cnt);
    }
}