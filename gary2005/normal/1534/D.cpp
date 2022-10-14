/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=2002;
int n,d[MAXN],depth[MAXN],fa[MAXN];
void query(int r){
	cout<<"? "<<r<<endl;ff;
	rb(i,1,n) scanf("%d",&d[i]);
}
int main(){
	scanf("%d",&n);
	query(1);
	rb(i,1,n) depth[i]=d[i];
	rb(i,1,n) if(depth[i]==1) fa[i]=1;
	vector<int> v[2];
	rb(i,2,n) v[depth[i]&1].PB(i);
	if(v[0].size()>v[1].size()) swap(v[0],v[1]);
	for(auto it:v[0]){
		query(it);
		rb(i,1,n) if(d[i]==1){
			if(depth[i]<depth[it]) fa[it]=i;
			else fa[i]=it;
		}
	}
	cout<<"!"<<endl;
	rb(i,2,n) cout<<i<<" "<<fa[i]<<endl;
	ff; 
	return 0;
}