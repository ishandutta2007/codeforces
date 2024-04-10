#include <cstdio>
#include <vector>
using namespace std;

int n,q;
int arr[200005];
vector<int> al[200005];

int pre[200005];
int post[200005];
bool parity[200005];

int counter=0;
void dfs(int i,int p){
    pre[i]=++counter;
    for (auto &it:al[i]){
        if (it==p) continue;
        parity[it]=parity[i]^true;
        dfs(it,i);
    }
    post[i]=counter;
}

int fen[200005];

int query(int i){
    int res=0;
    while (i){
        res+=fen[i];
        i-=i&-i;
    }
    return res;
}

void update(int i,int j){
    while (i<200005){
        fen[i]+=j;
        i+=i&-i;
    }
}

void update(int i,int j,int k){
    update(i,k);
    update(j+1,-k);
}

int main(){
    scanf("%d%d",&n,&q);
    
    for (int x=1;x<=n;x++) scanf("%d",&arr[x]);
    
    int a,b;
    for (int x=1;x<n;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    dfs(1,-1);
    
    while (q--){
        scanf("%d",&a);
        if (a==1){
            scanf("%d%d",&a,&b);
            update(pre[a],post[a],b*(parity[a]?1:-1));
        }
        else{
            scanf("%d",&a);
            printf("%d\n",query(pre[a])*(parity[a]?1:-1)+arr[a]);
        }
    }
}