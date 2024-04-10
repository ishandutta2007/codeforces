#include<bits/stdc++.h>
using namespace std;
#define N 1020
typedef long long ll;
int n,m;
istream& operator >> (istream &fin,__int128 &x){
	string s;
	fin>>s;
	x=0;
	for(auto c:s)x=x*10+c-'0';
	return fin;
}
ostream& operator << (ostream &fout,__int128 x){
	string s;
	if(!x)s="0";
	while(x)s+=x%10+'0',x/=10;
	reverse(s.begin(),s.end());
	fout<<s;
	return fout;
}
class Segment_Tree{
	int Len;
	struct node{
		__int128 g;
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].g=!t[ls].g&&!t[rs].g?0:__gcd(t[ls].g,t[rs].g);
	}
	void build(int u,int L,int R,__int128 *a,__int128 x){
		if(L==R){
			t[u].g=x/__gcd(x,a[L]);
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid,a,x);
		build(rs,mid+1,R,a,x);
		update(u);
	}
	void _del(int u,int L,int R,int p){
		if(L==R){
			t[u].g=0;
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?_del(ls,L,mid,p):_del(rs,mid+1,R,p);
		update(u);
	}
public:
	void init(int _n,__int128 *a,__int128 x){
		Len=_n;
		build(1,1,_n,a,x);
	}
	void Del(int p){
		_del(1,1,Len,p);
	}
	bool wei(){
		return t[1].g>1;
	}
}A[N],B[N];
bool check(__int128 x,const vector<__int128> &v){
	__int128 g=0;
	for(auto y:v){
		g=__gcd(g,x/__gcd(x,y));
		if(g==1)return true;
	}
	return false;
}
__int128 a[N],b[N];
bool da[N],db[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],da[i]=0;
	for(int i=1;i<=m;++i)cin>>b[i],db[i]=0;
	queue<pair<int,int> > q;
	for(int i=1;i<=n;++i){
		A[i].init(m,b,a[i]);
		if(A[i].wei())q.emplace(i,0),da[i]=1;
	}
	for(int i=1;i<=m;++i){
		B[i].init(n,a,b[i]);
		if(B[i].wei())q.emplace(i,1),db[i]=1;
	}
	while(!q.empty()){
		auto [u,opt]=q.front();
		q.pop();
		if(!opt){
			for(int i=1;i<=m;++i){
				if(!db[i]){
					B[i].Del(u);
					if(B[i].wei()){
						q.emplace(i,1);
						db[i]=1;
					}
				}
			}
		}
		else{
			for(int i=1;i<=n;++i){
				if(!da[i]){
					A[i].Del(u);
					if(A[i].wei()){
						q.emplace(i,0);
						da[i]=1;
					}
				}
			}
		}
	}
	vector<__int128> X,Y;
	for(int i=1;i<=n;++i){
		if(!da[i])X.push_back(a[i]);
	}
	for(int i=1;i<=m;++i){
		if(!db[i])Y.push_back(b[i]);
	}
	if(X.empty()||Y.empty()){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
		cout<<X.size()<<' '<<Y.size()<<'\n';
		for(auto x:X)cout<<x<<' ';
		cout<<'\n';
		for(auto x:Y)cout<<x<<' ';
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}