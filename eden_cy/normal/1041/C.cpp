#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)

typedef long long ll;

int Ans[200005];
struct node{
	int x,id;
	bool operator <(const node &s) const{
		return x>s.x;
	}
};
node Num[200005];
priority_queue<node> Que;
int main() {
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	FOR(i,1,n) {
		scanf("%d",&Num[i].x);
		Num[i].id=i;
	}
	sort(Num+1,Num+n+1);
	int res=0;
	DOR(i,n,1) {
		if(!Que.empty()) {
			node q=Que.top();
			if(Num[i].x-q.x>d) {
				Que.pop();
				Ans[Num[i].id]=Ans[q.id];
			} else {
				Ans[Num[i].id]=++res;
			}
		} else {
			Ans[Num[i].id]=++res;
		}
		Que.push(Num[i]);
	}
	printf("%d\n",res);
	FOR(i,1,n) printf("%d ",Ans[i]);
	putchar('\n');
	return 0;
}