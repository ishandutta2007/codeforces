#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
int t,n,m,a[500002],b[500002],ans,head[500002],cnt;
struct edge{int to,next;}e[1000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]};head[x]=cnt;}
inline void pls(re int &x,re int y){(x+=y)>=M?x-=M:x;}
char s[500002];
stack<int>st,q;
signed main(){
	cin>>n;n*=2;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		if(s[i]=='-')cin>>a[i];
	}
	for(re int i=n;i;--i){
		if(s[i]=='+'){
			if(!st.empty()){
				q.push(st.top());
				st.pop();
			}
			else return puts("NO"),0;
		}
		else{
			if(st.empty())st.push(a[i]);
			else if(a[i]>st.top())return puts("NO"),0;
			else st.push(a[i]);
		}
	}
	puts("YES");
	while(!q.empty())printf("%d ",q.top()),q.pop();
}