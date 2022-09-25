#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n;
int s[200005];
int parent[200005];
vector<int> al[200005];
const int MOD=1000000007;
int dfs(int i){
    int ans=0;
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (s[*it]==-1){
            parent[*it]=i;
            s[*it]=0;
            if (!ans) ans=dfs(*it);
            else dfs(*it);
            s[i]+=s[*it];
        }
        else if (*it==i){
            ans=-2;
        }
        else if (parent[i]!=*it){
            ans=-1;
        }
    }
    s[i]++;
    return ans;
}
int main(){
    memset(s,-1,sizeof(s));
    scanf("%d",&n);
    int a,b;
    for (int x=0;x<n;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    long long ans=1;
    int res;
    for (int x=1;x<=(n<<1);x++){
        if (!(al[x].size()==0 || (al[x].size()==2 && al[x][0]==x)) && s[x]==-1){
            s[x]=0;
            res=dfs(x);
            if (res==0) ans*=s[x];
            else if (res==-1) ans*=2;
            ans%=MOD;
        }
    }
    printf("%lld\n",ans);
}