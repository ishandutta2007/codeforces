#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005;typedef long long ll;
int a[N];std::priority_queue<int,std::vector<int>,std::greater<int>> q;
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	std::sort(a+1,a+n+1,std::greater<int>());
	int c=0;ll ans=0;
	for(int i=1;i<=n;++i){
		int j=i;while(j<n&&a[j+1]==a[i])++j;
		std::vector<int> cur;
		int len=j-i+1,tmp=std::min(c,len);len-=tmp,c-=tmp;
		for(int k=0;k<tmp;++k)cur.pb(a[i]);
		while(len&&!q.empty()&&q.top()<=a[i]){
			int x=q.top();q.pop();
			ans+=x,--len,cur.pb(a[i]);
			if(len)--len,cur.pb(a[i]);else ++c;
		}
		while(!q.empty()&&len>=2&&q.top()<2*a[i]){
			int x=q.top();q.pop();
			ans+=x,len-=2,cur.pb(a[i]*2-x),cur.pb(x);
		}
		c+=len,ans+=1LL*len*a[i];
		for(auto it:cur)q.push(it);
		i=j;
	}
	printf("%lld\n",ans);
	return 0;
}