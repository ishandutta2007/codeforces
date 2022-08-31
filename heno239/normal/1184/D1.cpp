#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  int k,n,m,t;
  cin >> n >> k >> m >> t;
  int c,x;
  rep(q,t){
    cin >> c >> x;
    if(c==0){
      if(x<k){
        n-=x;
        k-=x;
      }else{
        n-=n-x;
      }
    }else{
      n++;
      if(x<=k){
        k++;
      }
    }
    cout << n SP k << endl;
  }
  return 0;
}