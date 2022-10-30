#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef long long ll;
char s[N];int n,a,b,c;
ll solve(std::priority_queue<int,std::vector<int>,std::greater<int>> q,int cnt,int rest,int tot,int qwq,int t){
	ll ans=0,cur=0;bool flag=t==1;
	while(true){
		if(!t){
			if(!tot){
				if(cnt||!q.empty())ans=std::max(ans,cur+a);
				if(rest)cur-=c,--rest,++tot;
				else break;
			}
			else{
				if(!q.empty()){
					int x=q.top();q.pop();--x,cur+=a;
					if(x)q.push(x);else ++rest;
				}
				else if(cnt)cur+=a,--cnt;
				else if(rest)cur-=c,--rest,++tot;
				else if(qwq)cur-=c,--qwq;
				else break;
			}
		}
		else{
			if(!tot)break;
			cur+=b,--tot;
		}
		ans=std::max(ans,cur),t^=1;
	}
	return ans;
}
void MAIN(){
	read(n,a,b,c);scanf("%s",s+1);
	std::priority_queue<int,std::vector<int>,std::greater<int>> q;int cnt=0,rest=0,tot=0,qwq=0;
	for(int i=1;i<=n;++i){
		int j=i;while(j<n&&s[j+1]==s[i])++j;
		if(s[i]=='0'){
			if(i==1||j==n)cnt+=j-i,++qwq;
			else if(i==j)++rest;
			else q.push(j-i);
		}
		else if(s[i]=='1')tot+=j-i;
		i=j;
	}
	ll ans=std::max(solve(q,cnt,rest,tot,qwq,0),solve(q,cnt,rest,tot,qwq,1));
	printf("%lld\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}