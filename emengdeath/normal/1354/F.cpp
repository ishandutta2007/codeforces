#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int T;
int n, k;
namespace KM {
    const int inf=1e9;
    const int N = 305;
    int sla[N],visx[N],visy[N],pre[N],q[N];
    int w[N][N],lx[N],ly[N],fl[N],fr[N];//flfr
    int n, tp;
    void clear(){
        memset(lx,0,sizeof(lx));
        memset(ly,0,sizeof(ly));
        memset(fl,0,sizeof(fl));
        memset(fr,0,sizeof(fr));
        memset(w, 0, sizeof(w));
    }
    void set(int _n) {
        n = _n;
    }
    void match(int x)
    {
        while(x)
        {
            fl[x]=pre[x];
            int y=fr[fl[x]];
            fr[fl[x]]=x;
            x=y;
        }
    }
    void find(int x)
    {
        fill(visx,visx+n+1,0);
        fill(visy,visy+n+1,0);
        fill(sla,sla+n+1,inf);
        q[tp=1]=x;visx[x]=1;
        while(1)
        {
            for(int i=1;i<=tp;i++)
            {
                int x=q[i];
                for(int y=1;y<=n;y++)
                {
                    int t=lx[x]+ly[y]-w[x][y];
                    if(visy[y]||t>sla[y])continue;
                    pre[y]=x;
                    if(t==0)
                    {
                        if(!fl[y]){match(y);return;}
                        q[++tp]=fl[y];visy[y]=1;visx[fl[y]]=1;
                    }
                    else sla[y]=t;
                }
            }
            int d=inf;tp=0;
            for(int i=1;i<=n;i++)if(!visy[i]&&d>sla[i])d=sla[i],x=i;
            for(int i=1;i<=n;i++)
            {
                if(visx[i])lx[i]-=d;
                if(visy[i])ly[i]+=d;
                else sla[i]-=d;
            }
            if(!fl[x]){match(x);return;}
            q[++tp]=fl[x];visy[x]=visx[fl[x]]=1;
        }
    }
    void pre_lx(){
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                lx[i] = max(lx[i], w[i][j]);
    }
    int get_all(){
        int ans = 0;
        for (int i = 1; i <= n ; i ++)
            ans += w[fl[i]][i];
        return ans;
    }
    void find_all(){
        pre_lx();
        for (int i =1; i <= n; i ++)find(i);
    }
}

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &k);
        KM::clear();
        KM::set(n);
        for (int i = 1; i <= n; i ++) {
            int a, b;
            scanf("%d %d", &a, &b);
            for (int j = 1; j <= n; j ++)
            {
               if (j <= k) {
                   KM::w[i][j] = a + (j - 1) * b;
               } else {
                   KM::w[i][j] = (k - 1) * b;
               }
            }
        }
        KM::find_all();
        vector<int> ans;
        for (int i = 1; i < k; i ++)
            ans.push_back(KM::fl[i]);
        for (int i = k + 1; i <= n; i ++)
            ans.push_back(KM::fl[i]), ans.push_back(-KM::fl[i]);
        ans.push_back(KM::fl[k]);
        printf("%d\n", (int)ans.size());
        for (auto u:ans)
            printf("%d ", u);
        puts("");
    }
    return 0;
}