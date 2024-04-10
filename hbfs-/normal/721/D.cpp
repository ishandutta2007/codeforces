#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define N 200050

using namespace std;

typedef long long LL;

LL Abs(LL x) { if (x < 0) return -x; return x; }

struct Monster{ int id;LL v;}a[N];
bool operator < (Monster p1,Monster p2) { return Abs(p1.v) > Abs(p2.v); }
int n,k,x;
int s[N];
LL ans[N];

priority_queue<Monster> q;
vector<int> pq;

int main()
{
	int cnt = 1 , flag = 0 , paul = 1;
	scanf("%d%d%d",&n,&k,&x);
	for (int i=1;i<=n;i++) {
		scanf("%d",&s[i]);
		if (Abs( s[i] ) < Abs( s[paul] )) paul = i;
		if (s[i] == 0) {
			pq.push_back(i);
			flag = i;
		}
		if (s[i] < 0) {
			cnt = cnt * (-1);
		}
	}
	
	if (flag) {
		
		if (cnt > 0) s[flag] -= x; else s[flag] += x;
		k--;
		
		for (int i=0;i<pq.size()-1 && k>0;i++) {
			k--;
			s[pq[i]] += x;
		}
		
	} else {
		if (cnt > 0) {
			flag = s[paul] > 0 ? 1 : -1;
			while (k && flag) {
				k--;
				if (flag > 0) {
					s[paul] -= x;
					if (s[paul] < 0) flag = 0;
				} else {
					s[paul] += x;
					if (s[paul] > 0) flag = 0;
				}
			}
		}
		
	}
	
	for (int i=1;i<=n;i++) {
		Monster tmp;
		tmp.id = i;
		tmp.v = 1LL * s[i];
		q.push(tmp);
	}
	
	for (int i=1;i<=k;i++) {
		Monster u = q.top(); q.pop();
		if (u.v > 0) 
			u.v += x;
		else
			u.v -= x;
		q.push(u);
	}
	
	while (!q.empty()) {
		Monster u = q.top(); q.pop();
		ans[ u.id ] = u.v;
	}
	
	printf("%I64d",ans[1]);
	for (int i=2;i<=n;i++) printf(" %I64d",ans[i]);
	printf("\n");
	
	return 0;
}