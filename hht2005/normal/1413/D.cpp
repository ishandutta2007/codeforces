#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],sk[maxn],top;
priority_queue<int>q;
int main() {
	int n;
	char op[3];
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++) {
		scanf("%s",op);//asdfrgthy
		if(op[0]=='+')sk[++top]=i;
		else {
			scanf("%d",a+i);
			if(!top)return puts("NO"),0;
			a[sk[top--]]=-a[i];
		}
	}
	for(int i=1;i<=2*n;i++) {
		if(a[i]<0)q.push(a[i]);
		else {
			if(q.top()!=-a[i])return puts("NO"),0;
			q.pop();
		}
	}
	puts("YES");
	for(int i=1;i<=2*n;i++)
		if(a[i]<0)printf("%d ",-a[i]);
	return 0;
}