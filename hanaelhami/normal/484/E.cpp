#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define ld long double
#define pb push_back
#define F first
#define S second
using namespace std;

const int MAXN = 101 * 1001 ;


struct query1{
    int l , r , x , ind ;
};

bool cmp(query1 x , query1 y)
{
 //   cout<<66<<endl ;
    return ((make_pair(x.x,-x.ind)) > (make_pair(y.x,-y.ind))) ;
}

vector < query1 > query ;

struct query2{
    int l , r , x ;
}qury [ MAXN ];

int l [ MAXN ] , r [ MAXN ] , n;

struct node{

    int pre , suf , ans ;
}seg [ 4 * MAXN ];

int h [ MAXN ] , ans [ MAXN ] ;

vector < int > v ;


void upd(int i , int s , int e , int ind)
{
    if(e-s<2)
    {
        seg[ind] = {1,1,1};
        return ;
    }
    int mid = (s+e) / 2 ;
    if(i < mid)
        upd(i,s,mid,2*ind);
    else
        upd(i,mid,e,2*ind+1);

    seg[ind].pre = seg[2*ind].pre + (seg[2*ind].pre==mid-s?seg[2*ind+1].pre:0);
    seg[ind].suf = seg[2*ind+1].suf + (seg[2*ind+1].suf==e-mid?seg[2*ind].suf:0);
    seg[ind].ans = max(seg[2*ind].ans,seg[2*ind+1].ans);
    seg[ind].ans = max(seg[ind].ans,seg[2*ind].suf+seg[2*ind+1].pre);
}

node get(int l , int r , int s , int e , int ind)
{
    if(l <= s && e <= r )
        return seg[ind] ;
    if(e <= l || r <= s)
        return {0,0,0} ;
    int mid = (s+e)/2;
    node a = get(l,r,s,mid,2*ind);
    node b = get(l,r,mid,e,2*ind+1);
    node ans ;
    ans.pre = a.pre + (a.pre==mid-s?b.pre:0);
    ans.suf = b.suf + (b.suf==e-mid?a.suf:0);
    ans.ans = max(a.ans,b.ans);
    ans.ans = max(ans.ans,a.suf+b.pre);
    return ans ;
}

inline void solve()
{
    for(int i = 0 ; i < n ; i ++)
        query.pb({i,i+1,h[i],-1});
  //  cout <<  1 << endl ;
    sort(query.begin(),query.end(),cmp);
   // cout << 1 << endl ;
    int m = (int)query.size();
    for(int i = 0 ; i < 4 * MAXN ; i ++ )
        seg[i] = {0,0,0};
    for(int i = 0 ; i < m ; i ++ )
    {
      //  cout << query[i].l << ' ' << query[i].r << ' ' << query[i].x << ' ' << query[i].ind<<endl;
        if(query[i].ind==-1)
            upd(query[i].l,0,n,1) ;
        else
            ans[query[i].ind] = get(query[i].l,query[i].r,0,n,1).ans ;

    }
    query.clear() ;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    for(int i = 0 ; i < n ; i ++ )
    {
        cin >> h[i] ;
        v.pb(h[i]);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin() ) ;
    int q ;
    cin >> q ;
    for(int i = 0 ; i < q ; i ++ )
    {
        cin >> qury[i].l >> qury[i].r >> qury[i].x;
        qury[i].l -- ;
        l[i] = 0 , r[i]  = (int)v.size() ;
    }

  //  cout << v[0]<<endl;
    for(int qq = 0 ; qq < 18 ; qq ++ )
    {
        for(int i = 0 ; i < q ; i ++ )
        {
            int mid = (l[i]+r[i]) / 2 ;
            query.pb({qury[i].l,qury[i].r,v[mid],i});
        }
        solve() ;
        for(int i = 0 ; i < q ; i ++ )
        {
            int mid = (l[i]+r[i])/2;
            if(ans[i]>=qury[i].x)
                l[i] = mid ;
            else
                r[i] = mid ;

          //  cout << i << ' ' << ans[i]<<'\n';
        }
    }
    for(int i = 0 ; i <    q ; i ++ )
        cout << v[l[i]]<< '\n';









}