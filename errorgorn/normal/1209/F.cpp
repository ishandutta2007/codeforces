#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n,m;
vector<ii> al[1000005];
int w[1000005];
int extra=100005;
queue<int> q;
long long MOD=1000000007;
int main(){
    //freopen("input.txt","r",stdin);
    memset(w,-1,sizeof(w));
    scanf("%d%d",&n,&m);
    int a,b;
    int curr,val;
    for (int x=1;x<=m;x++){
        scanf("%d%d",&a,&b);
        curr=a;
        val=x;
        while (val>=10){
            al[extra].push_back(ii(curr,val%10));
            curr=extra++;
            val/=10;
        }
        al[b].push_back(ii(curr,val));
        curr=b;
        val=x;
        while (val>=10){
            al[extra].push_back(ii(curr,val%10));
            curr=extra++;
            val/=10;
        }
        al[a].push_back(ii(curr,val));
    }
    q.push(1);
    w[1]=0;
    int node;
    long long weight;
    vector<ii> super;
    while (!q.empty()){
        super.clear();
        weight=w[q.front()];
        while (!q.empty() && weight==w[q.front()]){
            node=q.front(),q.pop();
            for (vector<ii>::iterator it=al[node].begin();it!=al[node].end();it++){
                super.push_back(*it);
            }
        }
        sort(super.begin(),super.end(),[](ii i, ii j){
            return i.second<j.second;
        });
        for (vector<ii>::iterator it=super.begin();it!=super.end();it++){
            if (w[(*it).first]==-1){
                w[(*it).first]=(weight*10+(*it).second)%MOD;
                q.push((*it).first);
            }
        }
    }
    for (int x=2;x<=n;x++){
        printf("%d\n",w[x]);
    }
}