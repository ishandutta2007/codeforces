#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb emplace_back
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
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
#define debug(...) cerr<<__VA_ARGS__//fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1e5+11;
int n;
string s,t;
int c[N];
void add(int x,int v){
  for(;x<=n;x+=x&-x)c[x]+=v;
}
int qry(int x){
  int r=0;
  for(;x;x-=x&-x)r+=c[x];
  return r;
}
const ll inf=~0uLL>>4;
int f[N];
vector<int> e[N];
ll solve(){
  cin>>n>>s>>t;
  string w=s;
  sort(ALL(w));
  if(w>=t) return -1;
  for(int i=0;i<=n+1;++i)c[i]=0;
  for(int i=0;i<=n+1;++i)e[i].clear();
  queue<int> q[26];
  For(i,0,n)s[i]-='a',t[i]-='a';
  For(i,0,n)q[s[i]].push(i);
  /*For(i,0,n){
    int x=q[t[i]].front();
    q[t[i]].pop();
    f[x]=qry(x);
    add(x+1,1);
  }
  for(int i=0;i<=n+1;++i)c[i]=0;*/
  ll now=0;
  ll ans=inf;
  For(i,0,n){
    For(j,0,t[i]){
      if(!q[j].empty()){
        int x=q[j].front();
        int p=x-qry(x);
        dbg(i,(char)(j+'a'),now,x,qry(x),now+p);
        upmn(ans,now+p);
      }
    }
    if(q[t[i]].empty())break;
    int x=q[t[i]].front();
    q[t[i]].pop();
    now+=x-qry(x);
    add(x+1,1);
    //e[x].pb(i);
    //for(int x:e[i])add(x+1,1);
  }
  return ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)cout<<solve()<<"\n";
}