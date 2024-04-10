#include<cstdio>
#include<queue>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
priority_queue <int> q;
int main(){
	int t=read(),n;
	while(t--){
		n=read();
		int ans=0,tmp=0;
		while(n--){
			q.push(read());
		}
		while(!q.empty()){
			if(q.top()&1){
				q.pop();
				continue;
			}
			else{
				if(q.top()==tmp){
					q.push(q.top()/2);
					q.pop();
					continue;
				}
				else{
					++ans;
					q.push(q.top()/2);
					tmp=q.top();
					q.pop();
					}
			}
		}
		printf("%d\n",ans);
	}
}