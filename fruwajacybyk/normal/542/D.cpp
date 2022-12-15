#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;

#define max_n 100005

lint A;

int pr[1040005];
VI primes;
int nrp;

bool check(lint x){
  FOR(i,0,nrp){
    if(x%primes[i]==0) return false;
    if(primes[i]*1LL*primes[i]>x) return true;
  }
  return true;
}

vector<lint> kutas[1040000];
vector<int> gp;
vector<lint> diw;
int memo[10000][2500];
map<lint,int> wdruga;

int rob(int l, int k){
  lint x = diw[l];
  if(x==1){
    memo[l][k] = 1;
    return 1;
  }
  if(k==gp.size()){
    if(x-1>primes[gp.back()]){
      if(check(x-1)){
        memo[l][k] = 1;
        return 1;
      }
    }
    memo[l][k] = 0;
    return 0;
  }
  if(x<primes[gp[k]]) return 0;
  int ans = memo[l][k+1];
  int myp = gp[k];
  FOR(j,0,kutas[myp].size()){
    if(x%kutas[myp][j]==0){
      ans+=memo[wdruga[x/kutas[myp][j]]][k+1];
    }
    if(kutas[myp][j]>x) break;
  }
  memo[l][k] = ans;
  return ans;
}


int main(){
  IOS; cin>>A;
  if(A==1){
    cout<<1<<endl;
    return 0;
  }
  if(A==2){
    cout<<0<<endl;
    return 0;
  }
  FOR(i,0,1e6+2) pr[i] = 0;
  for(int i=2;i<=1e6;i++){
    if(pr[i]==0){
      primes.pb(i);
      for(lint j=i*1LL*i;j<=1e6;j+=i) pr[j] = 1;
    }
  }
  for(lint i=1; i*i<=A;i++){
    if(A%i==0){
      diw.pb(i);
      if(i!=A/i) diw.pb(A/i);
    }
  }
    
  set<int> dupa;
  FOR(i,0,primes.size()){
    lint pot = primes[i];
    int act = 1;
    while(pot<=A){
      if(A%(pot+1)==0){
        kutas[i].pb(pot+1);
        dupa.insert(i);
      }
      pot*=primes[i];
      act++;
    }
  }
  FORE(i,dupa) gp.pb(*i);
  if(gp.size()==0){
    cout<<0<<endl;
    return 0;
  }
  nrp = primes.size();
  sort(all(diw));
  FOR(j,0,diw.size()) wdruga[diw[j]] = j;
  FOR(i,0,diw.size()) FORD(j,gp.size(),0){
    rob(i,j);
  }
  cout<<memo[diw.size()-1][0]<<endl;
}