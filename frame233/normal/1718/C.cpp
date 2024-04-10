#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
std::vector<int> vec;std::vector<ll> s[N];int a[N];
template<typename _Tp>
class heap{
public:
	std::priority_queue<_Tp> q1,q2;int siz;
	inline bool empty(){return !siz;}
	inline int size(){return siz;}
	inline void push(const _Tp &o){q1.push(o);++siz;}
	inline void pop(const _Tp &o){q2.push(o);--siz;}
	inline _Tp top(){
		while(!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();
		return q1.top();
	}
};
heap<ll> q;
inline ll getans(){return q.top();}
void MAIN(){
	while(!q.empty())q.pop(q.top());
	int n,m;read(n,m),vec.clear();int x=n;
	for(int i=2;i*i<=x;++i)if(x%i==0){
		vec.pb(n/i);while(x%i==0)x/=i;
	}
	if(x>1)vec.pb(n/x);
	std::sort(vec.begin(),vec.end());
	for(int i=0;i<SZ(vec);++i)s[i].resize(vec[i]),s[i].assign(SZ(s[i]),0);
	for(int i=0;i<n;++i){
		read(a[i]);
		for(int j=0;j<SZ(vec);++j)s[j][i%vec[j]]+=a[i];
	}
	for(int i=0;i<SZ(vec);++i)for(int j=0;j<vec[i];++j)q.push(s[i][j]*vec[i]);
	printf("%lld\n",getans());
	while(m--){
		int x,y;read(x,y),--x;
		if(y!=a[x]){
			for(int j=0;j<SZ(vec);++j){
				int k=x%vec[j];q.pop(s[j][k]*vec[j]);
				s[j][k]+=y-a[x],q.push(s[j][k]*vec[j]);
			}
			a[x]=y;
		}
		printf("%lld\n",getans());
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}