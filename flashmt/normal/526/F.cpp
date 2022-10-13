#include <iostream>
#include <cstdio>
#include <stack>
#define MAXS 3000000
#define MAXN 300005
#define INF 1000000000000LL
using namespace std;
int S[MAXN], N, TC;
long long mn[MAXS], ct[MAXS], carry[MAXS];
void init(int sn,int l,int r) { // inits all minimums to INF
	mn[sn] = INF;
	carry[sn] = 0;
	ct[sn] = r-l+1;
	if(l == r) return;
	int m = (l+r)/2;
	init(sn*2+1,l,m);
	init(sn*2+2,m+1,r);
}
void update(int sn,int l,int r,long long delta,int ql,int qr) { // adds delta to range [q1,qr]
	if (ql <= l && qr >= r) {
		carry[sn] += delta;
		return;
	}
	int m = (l+r)/2, lsn = sn*2+1, rsn = sn*2+2;
	if(ql <= m) update(lsn,l,m,delta,ql,qr);
	if(qr > m) update(rsn,m+1,r,delta,ql,qr);
	long long lm = mn[lsn] + carry[lsn];
	long long rm = mn[rsn] + carry[rsn];
	mn[sn] = min(lm, rm);
	if(lm == rm) ct[sn] = ct[lsn] + ct[rsn];
	else if(lm < rm) ct[sn] = ct[lsn];
	else ct[sn] = ct[rsn];
}
stack<pair<int,int> > mxst, mnst; // stores pair (right_index_of_range, max(i) or min(i))
int main () {
  int x, y;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    scanf("%d%d",&x,&y);
    S[x] = y;
  }
  init(0,1,N);
  long long ans = 0;
  while (!mxst.empty()) mxst.pop();
  while (!mnst.empty()) mnst.pop();
  mxst.push(make_pair(0,N+1));
  mnst.push(make_pair(0,0));
  for (int i = 1; i <= N; i++) {
    int prev = i-1;
    while (!mxst.empty() && mxst.top().second < S[i]) {
      pair<int,int> t = mxst.top();
      mxst.pop();
      update(0,1,N,S[i]-t.second,mxst.top().first+1,prev);
      prev = mxst.top().first;
    }
    prev = i-1;
    while (!mnst.empty() && mnst.top().second > S[i]) {
      pair<int,int> t = mnst.top();
      mnst.pop();
      update(0,1,N,t.second-S[i],mnst.top().first+1,prev);
      prev = mnst.top().first;
    }
    mxst.push(make_pair(i,S[i]));
    mnst.push(make_pair(i,S[i]));
    update(0,1,N,-INF+i,i,i);
    if (mn[0] + carry[0] == i) ans += ct[0];
  }
  cout << ans << endl;
}