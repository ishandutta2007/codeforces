#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
} 
priority_queue<int> q;
int n;long long ans;
int main(){
    n=read();
    while(n--){
        re int x=read();q.push(x);
        if(x<q.top()){
            ans+=q.top()-x;
            q.pop();q.push(x);
        }
    }
    printf("%lld\n",ans);
}