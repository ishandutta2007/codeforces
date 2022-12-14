#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int n,m;
int a[MAXN];
priority_queue<int> Q;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	int maxa=a[1];
	for(int i=2;i<=n;i++) if(a[i]>maxa) maxa=a[i];
	for(int i=1;i<=n;i++) Q.push(-a[i]);
	maxa+=m;
	while(m--){
		int x=-Q.top(); Q.pop();
		Q.push(-(x+1));
	}
	int ans1=0;
	while(!Q.empty()) ans1=max(ans1,-Q.top()),Q.pop();
	printf("%d %d\n",ans1,maxa);
}