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
vector<int> v[505];
int degree[505];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        degree[y]++;
    }
    for(int i =1;i<=n;i++){
        int temp[505];
        for(int j = 1;j<=n;j++)
            temp[j]=degree[j];
        degree[i]--;
        queue<int> q;
        for(int j=1;j<=n;j++){
            if(degree[j]==0)
                q.push(j);
        }
        int cnt=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cnt++;
            for(auto it:v[x]){
                if(--degree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==n){
            printf("YES\n");
            return 0;
        }
        for(int j =1;j<=n;j++){
            degree[j]=temp[j];
        }
    }
    printf("NO\n");
}
/*

262143999937856
*/