#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
struct CHT
{
    static const int INF=1e18;

    struct Line
    {
        int a, b; //y = ax + b
        double xLeft; //Stores the intersection wiith previous line in the convex hull. First line has -INF

        enum Type {line, maxQuery, minQuery} type;
        int val;

        explicit Line(int aa=0, int bb=0): a(aa), b(bb), xLeft(-INF), type(Type::line), val(0) {}

        int valueAt(int x) const
        {
            return a*x + b;
        }
        friend bool isParallel(const Line &l1, const Line &l2)
        {
            return l1.a == l2.a;
        }
        friend double intersectX(const Line &l1, const Line &l2)
        {
            return isParallel(l1, l2)?INF:1.0*(l2.b-l1.b)/(l1.a-l2.a);
        }
        bool operator<(const Line& l2) const
        {
            if(l2.type == line)
                return this->a < l2.a;
            if(l2.type == maxQuery)
                return this->xLeft < l2.val;
            if(l2.type == minQuery)
                return this->xLeft > l2.val;
        }
    };

    bool isMax=false;
    set<Line> hull;

    bool hasPrev(set<Line>::iterator it)
    {
        return it!=hull.begin();
    }   
    bool hasNext(set<Line>::iterator it)
    {
        return it!=hull.end() && next(it)!=hull.end();
    }
    bool irrelevant(const Line &l1, const Line &l2, const Line &l3)
    {
        return intersectX(l1, l3) <= intersectX(l1, l2);
    }
    bool irrelevant(set<Line>::iterator it)
    {
        return hasPrev(it) && hasNext(it) && ( 
            (isMax && irrelevant(*prev(it), *it, *next(it))) 
            || (!isMax && irrelevant(*next(it), *it, *prev(it))));
    }
    //Updates xValue of line pointed by it
    set<Line>::iterator updateLeftBorder(set<Line>::iterator it)
    {
        if(isMax && !hasPrev(it) || !isMax && !hasNext(it))
            return it;
        double val=intersectX(*it, isMax?(*prev(it)):(*next(it)));
        Line temp(*it);
        it=hull.erase(it);
        temp.xLeft=val;
        it=hull.insert(it, temp);
        return it;
    }
    void add(int a, int b) //Add ax + b in logN time
    {
        Line l3=Line(a, b);
        auto it=hull.lower_bound(l3);

        //If parallel liune is already in set, one of the lines becomes irrelevant
        if(it!=hull.end() && isParallel(*it, l3))
        {
            if(isMax && it->b<b || !isMax && it->b>b)
                it=hull.erase(it);
            else
                return;
        }

        it=hull.insert(it, l3);
        if(irrelevant(it))
        {
            hull.erase(it);
            return;
        }

        //Remove lines which became irrelevant after inserting
        while(hasPrev(it) && irrelevant(prev(it)))
            hull.erase(prev(it));
        while(hasNext(it) && irrelevant(next(it)))
            hull.erase(next(it));

        //Update xLine
        it=updateLeftBorder(it);
        if(hasPrev(it))
            updateLeftBorder(prev(it));
        if(hasNext(it))
            updateLeftBorder(next(it));
    }

    int query(int x)
    {
        Line q;
        q.val=x;
        q.type = isMax?Line::Type::maxQuery : Line::Type::minQuery;

        auto bestLine=hull.lower_bound(q);
        if(isMax)
            --bestLine;
        return bestLine->valueAt(x);
    }
};
int n,root,dp[500005],ans=hell,s[500005];
vi a[500005];
void go(int node,int par){
    s[node]=1;
    for(auto i:a[node]){
        if(i!=par){
            go(i,node);
            s[node]+=s[i];
        }
    }
}
void dfs(int node,int par){
    CHT cht;
    bool isleaf=1;
    for(auto i:a[node]){
        if(i!=par){
            isleaf=0;
            dfs(i,node);
            dp[node]=min(dp[node],dp[i]+(s[node]-s[i])*(s[node]-s[i]));
            if(sz(cht.hull)) ans=min(ans,cht.query(n-s[i])+(n-s[i])*(n-s[i])+dp[i]);
            cht.add(-2*s[i],dp[i]+s[i]*s[i]);
        }
    }
    if(isleaf) dp[node]=1;
}
void solve(){
    memset(dp,1,sizeof dp);
    cin>>n;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    if(n==2){
        cout<<2<<endl;
        return;
    }
    rep(i,1,n+1){
        if(sz(a[i])!=1){
            root=i;
            break;
        }
    }
    go(root,-1);
    dfs(root,-1);
    cout<<n*(n-1)/2+(n*n-ans)/2<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}