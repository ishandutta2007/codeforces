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
#define MXN 1500
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    set<int> s;
    queue<int> q;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(s.find(x)!=s.end()){
        }
        else{
            q.push(x);
            s.insert(x);
            if(q.size()>k){
                s.erase(q.front());
                q.pop();
            }
        }
    }
    vector<int> v;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        v.pb(x);
    }
    printf("%d\n",v.size());
    while(!v.empty()){
        printf("%d ",v.back());
        v.pop_back();
    }
    printf("\n");
    return 0;
}