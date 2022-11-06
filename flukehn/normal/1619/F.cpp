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
int n,m,k;
void print(vector<int> a){
  int u=(n+m-1)/m;
  int v=n/m;
  int p=0;
  For(i,0,n%m){
    cout<<u<<" ";
    For(j,0,u)cout<<a[p++]+1<<" \n"[j+1==u];
  }
  For(i,n%m,m){
    cout<<v<<" ";
    For(j,0,v)cout<<a[p++]+1<<" \n"[j+1==v]; 
  }
}
void solve(){
  cin>>n>>m>>k;
  vector<int> a(n),b(n,0);
  For(i,0,n)a[i]=i;
  For(i,0,k){ 
    sort(ALL(a),[&](int i,int j){
        return b[i]<b[j];
        });
    For(i,0,n%m*((n+m-1)/m)) b[a[i]]+=1;
    print(a);
  }
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)solve();
}