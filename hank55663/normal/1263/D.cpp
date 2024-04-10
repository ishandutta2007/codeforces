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
#define MXN 200005
set<int> v[26];
int p[200005];
int Find(int x){
    if(p[x]==x)return x;
    return p[x]=Find(p[x]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        char c[55];
        scanf("%s",c);
        for(int j =0;c[j]!=0;j++){
            v[c[j]-'a'].insert(i);            
        }
        p[i]=i;
    }
    for(int i = 0;i<26;i++){
        if(v[i].size()){
            int x=Find(*v[i].begin());
            for(auto it:v[i]){
                int y=Find(it);
                p[y]=x;
            }
        }
    }
    int ans=0;
    for(int i = 0;i<n;i++){
        if(p[i]==i)ans++;
    }
    printf("%d\n",ans);
}