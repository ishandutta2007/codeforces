#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
#define int long long
int t,n,ansx[300002],ansy[300002],cnt,a[300002],s1,s2;
priority_queue<int>q1,q2;
signed main(){
	t=read();
	while(t--){
		n=read(),s1=s2=cnt=0;
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		for(re int i=1;i<=n;++i){
			re int x=read();
			if(x&1)q1.push(x);
			else q2.push(x);
		}
		while(q1.size()+q2.size()){
			if(!q1.size()||(q2.size()&&q1.top()<q2.top())){
				if(cnt==0)s2+=q2.top();
				q2.pop();
			}
			else{
				if(cnt==1)s1+=q1.top();
				q1.pop();
			}
			cnt^=1;
		}
		if(s1<s2)puts("Alice");
		else if(s1^s2)puts("Bob");
		else puts("Tie");
	}
}