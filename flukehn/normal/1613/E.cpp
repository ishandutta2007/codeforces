#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using ll=long long;
using pa=pair<int,int>;
template<class A,class B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<class A,class B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
const int mo=998244353;
constexpr int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
constexpr int reduce(int x){return x+(x>>31&mo);}
constexpr int& inc(int &x,int y){return x=reduce(x+y-mo);}
constexpr int& dec(int &x,int y){return x=reduce(x-y);}
#ifdef flukehn
void debug_out(){cerr<<endl;}
template <typename Head,typename... Tail>
void debug_out(Head H,Tail... T){
  cerr<<" "<<H;//to_string(H);
  debug_out(T...);
}
#define dbg(...) cerr<<"L"<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1e6+11;
char pool[N*2];
char *s[N];
int n,m;
int S,T;
int poolv[N],*vis[N];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int chk(int x,int y){
  int p=0,q=0;
  For(i,0,4){
    int u=x+dx[i];
    int v=y+dy[i];
    if(u<0||u>=n||v<0||v>=m||s[u][v]=='#')continue;
    p+=1;
    q+=vis[u][v];
  }
  dbg(x,y,p,q);
  return q&&q+1>=p;
}
void work(){
  cin>>n>>m;
  cin.getline(pool,100);
  s[0]=pool;
  For(i,0,n){
    s[i+1]=s[i]+m+1;
    cin.getline(s[i],m+2);
  }
  For(i,0,n)s[i][m]=0;
  vis[0]=poolv;
  For(i,1,n)vis[i]=vis[i-1]+m;
  For(i,0,n)For(j,0,m)vis[i][j]=0;
  For(i,0,n)dbg(s[i]);
  For(i,0,n)For(j,0,m){
    if(s[i][j]=='L'){
      S=i;
      T=j;
    }
  }
  dbg(S,T);
  queue<pa>Q;
  Q.push(pa(S,T));
  vis[S][T]=1;
  while(!Q.empty()){
    auto [x,y]=Q.front();
    dbg(x,y);
    Q.pop();
    For(i,0,4){
      int u=x+dx[i];
      int v=y+dy[i];
      dbg(u,v);
      if(u<0||u>=n||v<0||v>=m||vis[u][v]||s[u][v]!='.')continue;
      dbg(u,v);
      if(chk(u,v)){
        vis[u][v]=1;
        s[u][v]='+';
        Q.push(pa(u,v));
      }
    }
  }
  For(i,0,n)cout<<s[i]<<"\n";
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)work();
}