#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int q[maxn],dis[maxn],pre[maxn],n,k,ans,now;
vector<int>A,B,tmp;
void print(int x) {
	if(x==0)return;
	print(pre[x]);
	int I=(pre[x]+k-x)/2;
	printf("?");
	for(int i=0;i<I;i++) {
		printf(" %d",A.back());
		tmp.push_back(A.back());
		A.pop_back();
	}
	for(int i=0;i<k-I;i++) {
		printf(" %d",B.back());
		A.push_back(B.back());
		B.pop_back();
	}
	cout<<endl;
	scanf("%d",&now);
	ans^=now;
	for(int i=0;i<I;i++) {
		B.push_back(tmp.back());
		tmp.pop_back();
	}
}
int main() {
	int h,e;
	scanf("%d%d",&n,&k);
	memset(dis,-1,sizeof(dis));
	dis[0]=0;
	q[h=e=1]=0;
	for(int i=1;i<=n;i++)B.push_back(i);
	while(h<=e) {
		int x=q[h++];
		for(int i=0;i<=k;i++) {
			if(i<=x&&n-x>=k-i&&dis[x+k-2*i]==-1) {
				dis[x+k-2*i]=dis[x]+1;
				q[++e]=x+k-2*i;
				pre[q[e]]=x;
			}
		}
	}
	if(dis[n]==-1)puts("-1");
	else {
		print(n);
		printf("! %d\n",ans);
	}
	return 0;
}