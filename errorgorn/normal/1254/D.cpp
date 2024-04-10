#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int n,q;
vector<int> al[150005];

int subtree[150005];
int hroot[150005]; //this is the heavy root
int heavy[150005];
long long lazy[150005];
int pre[150005];
int post[150005];
int parent[150005];

const int MOD=998244353;
const string inverse_pow="111011011111111111111111111111";

int counter=1;
void dfs(int i,int p){
    pre[i]=counter++;
    subtree[i]=1;
    for (auto it:al[i]){
        if (it==p) continue;
        parent[it]=i;
        dfs(it,i);
        subtree[i]+=subtree[it];
    }
    post[i]=counter++;
}

void dfs2(int i,int p){
    heavy[i]=0;
    for (auto it:al[i]){
        if (it==p) continue;
        if (subtree[it]>subtree[heavy[i]]){
            heavy[i]=it;
        }
    }

    for (auto it:al[i]){
        if (it==p) continue;
        if (it==heavy[i]) hroot[it]=hroot[i];
        else hroot[it]=it;
        dfs2(it,i);
    }
}


long long arr[300005]; //initialize to 0, this is 1-indexed
void update(long long i,long long j){ //adds j to ith term
    while (i<=300005){
        arr[i]+=j;
        i+=(i&(-i));
    }
}
long long query(int i){ //calculate the sum of the 0-i terms
    long long k=0;
    while (i>0){
        k+=arr[i];
        i-=(i&(-i));
    }
    return k;
}

int main(){
    scanf("%d%d",&n,&q);

    long long inv=1;
    for (int x=0;x<inverse_pow.size();x++){
        inv=(inv*inv)%MOD;
        if (inverse_pow[x]=='1') inv=(inv*n)%MOD;
    }


    long long a,b;
    for (int x=1;x<n;x++){
        scanf("%lld%lld",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }

    dfs(1,-1);
    hroot[1]=1;
    dfs2(1,-1);

    while (q--){
        scanf("%d",&a);
        if (a==1){
            scanf("%lld%lld",&a,&b);
            lazy[a]+=b;
            ///we need to add to itself and parent and haevy child
            ///update everything
            update(1,b);
            ///update itself
            update(pre[a],b*(n-1));
            update(pre[a]+1,-b*(n-1));
            if (subtree[a]==1) continue;
            ///update parent
            update(1,b*(subtree[a]-1));
            update(pre[a],-b*(subtree[a]-1));
            update(post[a],b*(subtree[a]-1));
            ///update heavy child
            update(pre[heavy[a]],b*(n-subtree[heavy[a]]-1));
            update(post[heavy[a]],-b*(n-subtree[heavy[a]]-1));
        }
        else{
            scanf("%lld",&a);
            long long res=query(pre[a]);
            a=hroot[a];
            while (a!=1){
                res+=lazy[parent[a]]*(n-subtree[a]-1);
                a=hroot[parent[a]];
            }
            printf("%lld\n",(res%MOD)*inv%MOD);
        }
    }
}