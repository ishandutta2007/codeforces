#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int uli;
typedef long double Lf;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define fastIO  std::ios::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define N 100005
#define NN 2005
#define SZ(x) ((lli) (x).size())
#define loop(i,s,n) for(int i=(s);i<(n);i++)
#define loopr(i,n,s) for(int i=(n)-1;i>=(s);i--)
#define pb push_back
#define o2(a,b) cout<<(a)<<" "<<(b)<<endl
#define o3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define o4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define cl cout<<endl
#define r0 return 0
#define e0 exit(0)
#define x first
#define y second

inline lli modadd(lli n,lli m,lli p=mod){
    return ((n+m)%p+p)%p;
}

inline lli modsub(lli n,lli m,lli p=mod){
    return ((n-m+p)%p+p)%p;
}

inline lli modpro(lli n,lli m,lli p=mod){
    return (((n%p)*(m%p))%p+p)%p;
}

uli powe(lli x,lli y){
    uli res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}

lli modpow(lli x,lli y,lli p=mod){
    lli res = 1;
    while (y > 0) {
        if (y & 1)
            res = modpro(res , x, p);
        y = y >> 1;
        x = modpro(x , x, p);
    }
    return res;
}

inline lli modInverse(lli n, lli p=mod)
{
    if(n==1) return 1;
    return modpow(n, p-2, p);
}

inline lli moddiv(lli n,lli m,lli p=mod){
    return modpro(n,modInverse(m,p),p);
}

inline lli modadd3(lli x, lli y, lli z,lli p=mod){
    return modadd(modadd(x,y,p),z,p);
}

inline lli modadd4(lli x, lli y, lli z, lli w,lli p=mod){
    return modadd(modadd(x,y,p),modadd(z,w,p),p);
}

inline lli modnCr(lli fac[], int n, int r, lli p=mod)
{
    if (r==0) return 1;
    return modpro(fac[n],modInverse(modpro(fac[r],fac[n-r],p),p),p);
}

template <typename T>
inline T max3(T x, T y, T z){
    return max(max(x,y),z);
}

template <typename T>
inline T max4(T x, T y, T z, T w){
    return max(max3(x,y,w),z);
}

template <typename T>
inline T min3(T x, T y, T z){
    return min(min(x,y),z);
}

template <typename T>
inline T min4(T x, T y, T z, T w){
    return min(min3(x,y,w),z);
}

template <typename T>
void printArr(T *arr, int s, int n){
    for(int i=s;i<=n;i++){

        cout<<arr[i]<<" ";
    }cout<<endl;
}

//template<class X, class Y, class Z>
//struct triple {
//    X x;
//    Y y;
//    Z z;
//
//     friend bool operator<(triple a, triple b)
//    {
//        if(a.x!=b.x) return a.x<b.x;
//        else if(a.y!=b.y) return a.y<b.y;
//        else return a.z<=b.z;
//    }
//};
//
//
//template<class X, class Y, class Z, class W>
//class quad {
//    public:
//    X x;
//    Y y;
//    Z z;
//    W w;
//
//     friend bool operator<(quad a, quad b)
//    {
//        if(a.x!=b.x) return a.x<b.x;
//        else if(a.y!=b.y) return a.y<b.y;
//        else if(a.z!=b.z)return a.z<b.z;
//        else return a.w<b.w;
//    }
//};


//template <typename T>
//T gcd(T a, T b)
//{
//    if (a == 0)
//        return b;
//    if(b==0)
//        return a;
//    T t;
//    while((a>0)&&(b>0)){
//     t = a;
//     a=b%a;
//     b=t;
// }
//
// return max(a,b);
//}



//
//uli choose(uli n, uli k){
//uli res = 1;
//
//    // Since C(n, k) = C(n, n-k)
//    if ( k > n - k )
//        k = n - k;
//
//    // Calculate value of
//    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
//    for (uli i = 0; i < k; ++i)
//    {
//        res *= (n - i);
//        res /= (i + 1);
//    }
//
//    return res;
//}
//

//
//  vector<vector<pii>> adj;
//   //vector<int> dist;
//   vector<int> d;
////   vector<bool> visited;
////     vector<int> pa;
//   //queue<int> q;
//
//  class Graph{
//
//   public:
//      int V;
//
//  Graph(int V){
//      this->V = V;
//      adj.resize(V);
////        visited.resize(V);
//      //color.resize(V);
//      //dist.resize(V);
//        d.resize(V);
//     //// dist.resize(V);
////     pa.resize(V);
//
//  }
//
//  ~Graph(){
// 	  adj.clear();
// 	  //visited.clear();
// 	 // color.clear();
// 	 // dist.clear();
////    pa.clear();
// 	  //dist.clear();
//// 	  visited.clear();
//d.clear();
//
//
//  }
//
//
//  void addEdge(int a, int b)
//  {
//      adj[a].pb(b);
//      adj[b].pb(a);
//      //adj[b].pb({a,in});
//  }
//
// //  void dfs(int x){
// //    //  color[x]=1;
// //
// //      for(auto u: adj[x]){
// //          if(visited[u]) continue;
// //
// //          dfs(u);
// //      }
// //
// //  }
// //
// //
// //
// //
// //
//  // void dfsTree(int x, int p){
//  //     for(auto u: adj[x]){
//  //         if(u==p) {continue;}
//  //         dfsTree(u,x);
//  //     }
//  // }
//
//
//void dijkstra(int s) {
//    d.assign(n, INF);
//    d[s] = 0;
//    set<pair<int, int>> q;
//    q.insert({0, s});
//    while (!q.empty()) {
//        int v = q.begin()->second;
//        q.erase(q.begin());
//        for (auto edge : adj[v]) {
//            int to = edge.first;
//            int len = edge.second;
//            if (d[v] + len < d[to]) {
//                q.erase({d[to], to});
//                d[to] = d[v] + len;
//                q.insert({d[to], to});
//            }
//        }
//    }
//}
//
//
////  void bfs(int x){
////      queue<int> q;
////      visited[x]=1;
////      q.push(x);
////      //dist[x]=0;
////      while(!q.empty()){
////          int s = q.front();
////          q.pop();
////
////          for(auto u : adj[s]){
////
////              if(visited[u]) continue;
////              pa[u]=s;
////              visited[u]=1;
////              //dist[u.x]=dist[s]+1;
////              q.push(u);
////          }
////      }
////  }
//
// //pair<int,int> farthest(int start){
// //    vector<int> dist(V,INT_MAX);
// //
// //    q.push(start);
// //    dist[start]=0;
// //    while(!q.empty()){
// //        int u = q.front();
// //        q.pop();
// //        for(int child: adj[u]){
// //            //if(keep[child])
// //            if(dist[child] > dist[u]+1) {
// //                dist[child] = dist[u]+1;
// //                q.push(child);
// //            }
// //        }
// //    }
// //    int big=-1,mi=-1;
// //    for(int i=1;i<n+1;i++){
// //        //if(keep[i])
// //        {
// //            if(dist[i]>big){
// //                big=dist[i];mi=i;
// //            }
// //        }
// //    }
// //    return make_pair(big,mi);
// //}
//
//
// //  int connectedcomponents(int n){
// //      int ans=0;
// //      loop(i,1,n+1){
// //          if(!visited[i]){
// //              ans++;
// //              dfs(i);
// //          }
// //
// //      }
// //      return ans;
// //  }
//
//  };


//template <typename T>
//T findpowerfactorial(T n,T p)
//{
//    T x = 0;
//    while (n)
//    {
//        n /= p;
//        x += n;
//    }
//    return x;
//}
//
//template <typename T>
//int getibit(T n, int i){
//    //cout<<(n&(1LL<<i))<<endl;
//    return (n&(1LL<<i))?1:0;
//}
//
//template <typename T>
//int findbits(T n, T p){
//    int x=0;
//    while(n>0){
//        n/=p;
//        x++;
//    }
//    return x;
//}



//
//
////
//vector<pair<lli,int>> v;
//void primeFactors(lli n)
//{
//    v.clear();
//    int c=0;
//    while (n % 2 == 0)
//    {
//        n = n/2;
//        c++;
//    }
//    if(c>0) v.pb({2,c});
//
//
//    for (lli i = 3; i*i <= n; i = i + 2)
//    {   c=0;
//
//        while (n % i == 0)
//        {
//            n = n/i;
//            c++;
//        }
//        if(c>0)v.pb({i,c});
//
//    }
//    if (n > 2)
//        v.pb({n,1});
//}

//lli fac_[N];
//void fac_init(int n){
//    fac_[0]=1;
//    loop(i,1,n+1)fac_[i]=modpro(fac_[i-1],i);
//}
//
/*BITMASK
for( int inum = 0 ; inum < ( 1 << n ) ; ++ inum ) {
     for ( int pos = 0; pos < n ; ++pos ) {
         if (  inum & ( 1 << pos )  ){
              results[inum] += s [pos] ; //DO SOMETHING
         }
     }
}
*/
pii p[N];
set<pii> s; // end, mid
int main(){
    fastIO;
    int erer=1;
//    cin>>erer;
    loop(erer2,1,erer+1){
        int n;
        cin>>n;
        lli x,y;
        cin>>x>>y;
        loop(i,0,n){
            cin>>p[i].x>>p[i].y;
        }
        sort(p,p+n);
        auto it = s.begin();
        int mm=0;
        lli ans=0;
        loop(i,0,n){
            if(!s.size() || s.begin() -> x >= p[i].first){
//                mac[mm].pb(i);
                ans += (x+modpro(y,(p[i].y-p[i].x)));
                ans%=mod;
                s.insert({p[i].y, mm});
                mm++;
                continue;
            }

            it = s.lower_bound(make_pair(p[i].x, -1));
            {
                it--;
                if(y*(p[i].x-it->x)<=x){
//                    mac[it->y].pb(i);
                    ans += modpro(y,(p[i].y-it->x));
                    ans%=mod;
                    s.insert({p[i].y, it->y});
                    s.erase(it);
                }
                else {
                    ans += (x+modpro(y,(p[i].y-p[i].x)));
                    ans%=mod;
//                    mac[mm].pb(i);
                    s.insert({p[i].y, mm});
                    mm++;
                }
            }
        }

        cout<<ans<<"\n";

    }
    return 0;
}