/*
AuThOr Gwj
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
int n,m,a,b,mat[3003][3003];
LL g[9000000];
const int N=1<<12;
int tree[N*2+1];
mp q[3000+2][3000+2];int t[3000+2],h[3000+2];
void change(int X,int val){
	X+=N-1;
	tree[X]=val;
	X>>=1;
	while(X){
		tree[X]=min(tree[X<<1],tree[(X<<1)+1]); 
		X>>=1;
	}
}
int query(int l1,int r1,int now=1,int l=1,int r=N+1){
	if(r<=l1||l>=r1){
		return INF;
	}
	if(r<=r1&&l>=l1){
		return tree[now];
	}
	int mid=(l+r)>>1;
	return min(query(l1,r1,now<<1,l,mid),query(l1,r1,(now<<1)+1,mid,r));
}
int main(){
	fastio;
	cin>>n>>m>>a>>b;
	int x,y,z;
	cin>>g[0]>>x>>y>>z;
	memset(tree,0x3f,sizeof(tree));
	rb(i,1,9000000-1)
		g[i]=(g[i-1]*x+y)%z;
	rb(i,1,n)
		rb(j,1,m)
			mat[i][j]=g[(i-1)*m+j-1];
//	rb(i,1,n){
//		rb(j,1,m)
//			cout<<mat[i][j]<<" ";
//		cout<<endl;
//	}
	rb(j,1,m)
		t[j]=0,h[j]=1;
	rb(i,1,a-1)
	{
		rb(j,1,m)
		{
			while(t[j]>=h[j]&&q[j][t[j]].FIR>=mat[i][j]){
				t[j]--;
			}
			q[j][++t[j]]=II(mat[i][j],i);
		}
	}
	LL res=0;
	rb(i,1,n-a+1)
	{
		rb(j,1,m){
			while(t[j]>=h[j]&&q[j][t[j]].FIR>=mat[i+a-1][j]){
				t[j]--;
			}
			q[j][++t[j]]=II(mat[i+a-1][j],i+a-1);
			while(q[j][h[j]].SEC<i){
				h[j]++;
			}
			change(j,q[j][h[j]].FIR);
//			cout<<q[j][h[j]].FIR<<" "; 
		}
//		cout<<endl;
		rb(j,1,m-b+1){
			res+=query(j,j+b);
		}
	}
	cout<<res;
	return 0;
}