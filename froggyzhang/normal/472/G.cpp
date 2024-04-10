#include<bits/stdc++.h>
using namespace std;
#define N 200110
#define M 10001000
typedef unsigned long long ull;
string S,T;
int n,m,Q,ans[M];
ull a[N],b[N];
struct Query{
	int l1,l2,len;
}q[M];
vector<int> c0[N],c1[N];
void Solve(vector<int> *c){
	for(int j=0;j<m;++j){
		static int s[N];
		for(int i=0;i<n&&i+j<m;i+=64){
			if(i>0)s[i]=s[i-64];
			else s[i]=0;
			s[i]+=__builtin_popcountll(a[i]^b[i+j]);
		}
		for(auto id:c[j]){
			while(q[id].len&&q[id].l1&63){
				ans[id]+=S[q[id].l1]!=T[q[id].l2];
				++q[id].l1,++q[id].l2,--q[id].len;
			}
			while(q[id].len&63){
				ans[id]+=S[q[id].l1+q[id].len-1]!=T[q[id].l2+q[id].len-1];
				--q[id].len;
			}
			if(q[id].len){
				ans[id]+=s[q[id].l1+q[id].len-64]-(!q[id].l1?0:s[q[id].l1-64]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>S>>T;
	n=S.length(),m=T.length();
	cin>>Q;
	for(int i=1;i<=Q;++i){
		cin>>q[i].l1>>q[i].l2>>q[i].len;
		if(q[i].l2>=q[i].l1)c0[q[i].l2-q[i].l1].push_back(i);
		else c1[q[i].l1-q[i].l2].push_back(i),swap(q[i].l1,q[i].l2);
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<64&&i+j<m;++j){
			b[i]=b[i]<<1|(T[i+j]-'0');
		}	
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<64&&i+j<n;++j){
			a[i]=a[i]<<1|(S[i+j]-'0');
		}
	}
	Solve(c0);
	swap(n,m),swap(S,T),swap(a,b);
	Solve(c1);
	for(int i=1;i<=Q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}