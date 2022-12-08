#include <iostream>
#include <cstdio>

#include <vector>
#include <stack>

using namespace std;

const int MN = 1e6 + 100;
int N, K;
int c[MN];

using vi = vector<int>;
#define pb push_back
vi a[MN];
using si = stack<int>;
#define sz size()
si s;
int o[MN][2];
void dfs(int n, int * c = new int(0))
{
  o[n][0] = (*c)++;
  for(int x : a[n])
    dfs(x, c);
  o[n][1] = *c;
}
template<int MS> struct ST
{
public:
  int v[MS], z[MS];
  int s;
  void init(int n, int l, int r)
  {
    if(r-l>1)
    {
      int m = l + ((r-l)>>1);
      init(n<<1, l, m), init(n<<1|1, m, r);
    }
    v[n] = z[n] = 0;
  }
  void init(int s) {init(1, 0, this->s = s);}
  void addz(int n, int x)
  {
    v[n] += x;
    z[n] += x;
  }
  void down(int n, int l, int r)
  {
    if(!z[n]) return;
    if(r-l>1)
      addz(n<<1, z[n]), addz(n<<1|1, z[n]);
    z[n] = 0;
  }
  void up(int n)
  {
    v[n] = max(v[n<<1], v[n<<1|1]);
  }
  void upd(int n, int l, int r, int ql, int qr, int q)
  {
    if(ql <= l&&r <= qr) return addz(n, q);
    down(n, l, r);
    int m = l + ((r-l)>>1);
    if(ql < m) upd(n<<1, l, m, ql, qr, q);
    if(m < qr) upd(n<<1|1, m, r, ql, qr, q);
    up(n);
  }
  void upd(int ql, int qr, int q) {upd(1, 0, s, ql, qr, q);}
  int qry() {return v[1];}
};
ST<MN*3> st;

int main(void)
{
  scanf("%d%d", &N, &K);
  for(int i = 0;i < N;i++)
    scanf("%d", c + i);
  s.push(N);
  for(int i = N-1;i >= 0;i--)
  {
    for(;s.sz>1&&c[s.top()] <= c[i];) s.pop();
    a[s.top()].pb(i);
    s.push(i);
  }
  dfs(N);
  st.init(N+1);
  for(int i = 0;i < K;i++)
    st.upd(o[i][0], o[i][1], 1);
  printf("%d\n", st.qry());
  for(int i = K;i < N;i++)
  {
    st.upd(o[i][0], o[i][1], 1);
    st.upd(o[i-K][0], o[i-K][1], -1);
    printf("%d\n", st.qry());
  }
  return 0;
}