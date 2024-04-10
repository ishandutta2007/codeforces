#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
const int N=60;
set <int> ans;
mt19937_64 gen(time(0));
bool vis[maxn];
int _,n,m,p[maxn],q[maxn];

int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d",&n,&m); ans.clear();
        for (int i=0;i<n;i++){
            scanf("%d",&p[i]);
            p[i]--;
        }
        for (int T=0;T<N;T++){
            int x=gen()%n;
            int k=(x-p[x]+n)%n;
            for (int i=0;i<n;i++) q[i]=p[(i+k)%n],vis[i]=0;
            int res=0;
            for (int i=0;i<n;i++) if (q[i]!=i&&!vis[i]){
                vis[i]=1;
                int tmp=q[i];
                while (tmp!=i) vis[tmp]=1,res++,tmp=q[tmp];
            }
            if (res<=m) ans.insert(k);
        }
        printf("%d ",ans.size());
        for (auto x:ans) printf("%d ",x);puts("");
    }
}