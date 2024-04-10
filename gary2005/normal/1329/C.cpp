/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[(1<<22)];
int depth[1<<22];
vector<int> res;
int deep(int now){
	if(a[now<<1]==0&&a[(now<<1)+1]==0) return depth[now];
	if(a[now<<1]>a[(now<<1)+1]){
		return deep(now<<1);
	}
	else{
		return deep((now<<1)+1);
	}
}
int m[1<<22]={0};
void f(int now){
	if(a[now<<1]==0&&a[(now<<1)+1]==0){
		a[now]=0;
		return ;
	}
	else{
		if(a[now<<1]>a[(now<<1)+1]){
			a[now]=a[now<<1];
			m[a[now<<1]]=now;
			f(now<<1);
		}
		else{
			m[a[(now<<1)+1]]=now;
			a[now]=a[(now<<1)+1];
			f((now<<1)+1);
		}
	}
}
int h,g;
bool cmp(int A,int B){
	return A>B;
}
void solve(){
	res.clear();
	cin>>h>>g;
	int need=(1<<h)-(1<<g);
	vector<int> v;
	depth[1]=1;
	rb(i,2,(1<<h)-1)
	depth[i]=depth[i/2]+1;
	rb(i,1,(1<<h)-1){
		cin>>a[i];
		v.PB(a[i]);
		m[a[i]]=i;
	}
	sort(ALL(v),cmp);
	int it=0;
	rb(i,1,need){
		while(deep(m[v[it]])==g){
			it++;
		}
		res.PB(m[v[it]]);
		f(m[v[it]]);
		it++;
	}
	LL sum=0;
	rb(i,1,(1<<g)-1){
		sum+=a[i];
	}
	rb(i,1,1<<h)
		a[i]=depth[i]=0;
	cout<<sum<<endl;
	for(auto it:res) cout<<it<<" ";
	cout<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}