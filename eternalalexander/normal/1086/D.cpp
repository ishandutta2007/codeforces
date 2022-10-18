#include <bits/stdc++.h>
#define maxn 200005
std::set<int>P[4];
int D[maxn],n,q,cnt[10];
char opt[10],s[maxn];

struct segmentTree {
	int sum[maxn<<2];
	void modify(int p,int v,int l=1,int r=n,int rt=1){
		if(l==r){sum[rt]=v;return;}
		int mid=(l+r)>>1;
		if(p<=mid)modify(p,v,l,mid,rt<<1);
		else modify(p,v,mid+1,r,rt<<1|1);
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	}int query(int l,int r,int L=1,int R=n,int rt=1){
		if(l>R||r<L||l>r)return 0;
		if(l<=L&&R<=r)return sum[rt];
		return query(l,r,L,(L+R)>>1,rt<<1) + query(l,r,((L+R)>>1)+1,R,rt<<1|1);
	}
}A[4];

int first(int x) {return *P[x].begin();}
int last(int x){auto it = P[x].end();it--;return *it;}
void ins(int p,int x){
	cnt[x]++;
	A[x].modify(p,1);
	P[x].insert(p);
	D[p]=x;
}void del(int p){
	cnt[D[p]]--;
	A[D[p]].modify(p,0);
	P[D[p]].erase(p);
	D[p]=0;
}

void answer(){
	if(cnt[1]==n || cnt[2] == n || cnt[3] == n) { printf("%d\n",n); return ; }
	if(!cnt[1])printf("%d\n",cnt[2]);
	else if(!cnt[2])printf("%d\n",cnt[3]);
	else if(!cnt[3])printf("%d\n",cnt[1]);
	else {
		int dec = 0;
		dec += A[1].query(first(3),first(2)) + A[1].query(last(2),last(3));
		dec += A[2].query(first(1),first(3)) + A[2].query(last(3),last(1)); 
		dec += A[3].query(first(2),first(1)) + A[3].query(last(1),last(2));
		printf("%d\n",n-dec);
	}
}

int main(){
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='R') ins(i,1);
		if(s[i]=='S') ins(i,2);
		if(s[i]=='P') ins(i,3);
	}answer();
	while(q--){
		int p,d;
		scanf("%d%s",&p,opt+1);
		if(opt[1]=='R')d=1;
		if(opt[1]=='S')d=2;
		if(opt[1]=='P')d=3;
		del(p);
		ins(p,d);
		answer();
	}
	return 0;
}