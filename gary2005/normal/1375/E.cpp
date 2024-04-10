/*
{By GWj
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int a[1001];int pos[1001];
vector<mp> v;

int main(){
	R(n);
	rb(i,1,n)
		R(a[i]);
	int N=n;
	int rest=0;
	rb(i,1,n)
		rb(j,i+1,n)
			if(a[i]>a[j]) rest++;
	cout<<rest<<endl;
	rb(j,1,n)
		v.PB(II(a[j],j));
	sort(ALL(v));
	rb(i,1,n)
		a[v[i-1].SEC]=i,pos[i]=v[i-1].SEC;
	rl(i,N,1){
		n=i;
		rb(i,a[n]+1,n){
			int u,v;
			v=n;
			u=pos[i];
			cout<<u<<" "<<v<<endl;
			swap(a[u],a[v]);
			swap(pos[a[u]],pos[a[v]]);
		}
	}
//	rb(i,1,N)
//		cout<<a[i]<<" ";
//	cout<<endl;
	return 0;
}