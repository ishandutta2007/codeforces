#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define re register
#define in inline
using namespace std;
in int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
int n,rd[200002],a[200002];
long long ans;
priority_queue<int>q;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		while(!q.empty())q.pop();
		ans=0;n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),ans+=a[i];
		for(re int i=1;i<n;++i)++rd[read()],++rd[read()];
		for(re int i=1;i<=n;++i)while(--rd[i])q.push(a[i]);
		for(re int i=1;i<n;++i){printf("%lld ",ans);if(!q.empty())ans+=q.top(),q.pop();
		}
		puts("");
	}
}