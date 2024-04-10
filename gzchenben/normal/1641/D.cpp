#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Trie
{
    public:
    struct Node
    {
        map<int,int> Son;
        int val;
        int dep;
    }a[10000005];// Root = 1
    int cnt = 1;
    void Modify(vector<int> &x,int flag)
    {
        // printf("Modify : ");
        // for(auto px : x) printf("%d ",px);
        // printf(" - %d\n",flag);
        vector<int> Now;
        Now.push_back(1);
        for(auto px : x)
        {
            vector<int> tmp = Now;
            for(auto ptmp : tmp)
            {
                if(!a[ptmp].Son[px]) 
                {
                    a[ptmp].Son[px] = ++cnt;
                    a[cnt].dep = a[ptmp].dep + 1;
                }
                Now.push_back(a[ptmp].Son[px]);
            }
        }
        for(auto pNow : Now)
        {
            a[pNow].val += flag;
        }
    }
    bool Query(vector<int> &x)
    {
        // printf("Query : ");
        // for(auto px : x) printf("%d ",px);
        // printf("\n");
        vector<int> Now;
        Now.push_back(1);
        for(auto px : x)
        {
            vector<int> tmp = Now;
            for(auto ptmp : tmp)
            {
                if(!a[ptmp].Son[px]) continue;
                Now.push_back(a[ptmp].Son[px]);
            }
        }
        int ans = 0;
        for(auto pNow : Now)
        {
            ans += (a[pNow].dep % 2 == 0 ? 1 : -1) * a[pNow].val; 
        }
        // printf("ans = %d\n",ans);
        return ans != 0;
    }
}T;
int n,m;
struct Arr
{
    vector<int> vec;
    int val;
}a[100005];
bool operator < (Arr &x,Arr &y)
{
    return x.val < y.val;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int x;
            scanf("%d",&x);
            a[i].vec.push_back(x);
        }
        scanf("%d",&a[i].val);
        sort(a[i].vec.begin(),a[i].vec.end());
    }
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) 
    {
        T.Modify(a[i].vec,1);
    }
    int NowL = 1, NowR = n, ans = 2e9+1;
    while(1)
    {
        while(T.Query(a[NowL].vec) && NowL <= NowR)
        {
            T.Modify(a[NowR].vec,-1);
            NowR--;
        }
        if(NowL > NowR) break;
        if(NowR != n) ans = min(ans,a[NowL].val + a[NowR+1].val);
        T.Modify(a[NowL].vec,-1);
        NowL++;
    }
    printf("%d\n",(ans == 2e9+1 ? -1 : ans));
}