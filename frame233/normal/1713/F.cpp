#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=(1<<19)+5;
int sum[N];
std::vector<int> solve(const std::vector<int> &a){
	if(SZ(a)==1)return a;
	int n=SZ(a),q=0;while((1<<q)<n)++q;
	std::vector<int> b;for(int i=0;i<n-(1<<(q-1));++i)b.pb(a[i]^a[i+(1<<(q-1))]);
	std::vector<int> ans=solve(b);
	memset(sum,0,4<<(q-1));
	for(int i=0;i<SZ(ans);++i)sum[i]=ans[i];
	for(int len=1;len<1<<(q-1);len*=2){
		for(int i=0;i<1<<(q-1);i+=len*2){
			for(int j=0;j<len;++j)sum[i+j+len]^=sum[i+j];
		}
	}
	std::vector<int> c;
	for(int i=SZ(a)-(n-(1<<(q-1)));i<SZ(a);++i)c.pb(a[i]);
	for(int i=n-(1<<(q-1)),cur=(1<<q)-n-1;i<SZ(a)-(n-(1<<(q-1)));++i,--cur)c.pb(a[i]^sum[cur]);
	std::vector<int> res=solve(c);
	res.insert(res.end(),ans.begin(),ans.end());
	return res;
}
int main(){
	int n;read(n);std::vector<int> a(n);for(auto &&it:a)read(it);
	std::vector<int> ans=solve(a);std::reverse(ans.begin(),ans.end());
	for(auto it:ans)printf("%d ",it);
	printf("\n");
	return 0;
}