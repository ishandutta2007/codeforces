/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,A[200000+10];
mp a[200000+10];
pair<mp,int> query[200000+10];
int res[200000+10];
bool cmp(mp A,mp B){
	if(A.FIR!=B.FIR) return A>B;
	return A.SEC<B.SEC;
}
int size_n;
int tree[200000*8];
void _add(int point){
	int now=point+size_n-1;
	tree[now]++;
	int now_change=now>>1;
	while(now_change){
		tree[now_change]=tree[now_change<<1]+tree[(now_change<<1)+1];
		now_change>>=1;
	} 
}
int query_(int now,int l,int r,int a,int b,int k){
	if(l==r-1){
		return l;
	}
	int mid=(l+r)>>1;
	if(k-tree[now<<1]<=0){
		return query_(now<<1,l,mid,a,b,k);
	}
	else{
		return query_((now<<1)+1,mid,r,mid,b,k-tree[now<<1]);
	}
}
int _query(int l,int r,int k){
	return query_(1,1,size_n+1,l,r,k); 
}
int main(){
	cin>>n;
	size_n=1<<(int(ceil(log2(double(n)))));
	rb(i,1,n) scanf("%d",&a[i].FIR),A[i]=a[i].FIR,a[i].SEC=i;
	sort(a+1,a+1+n,cmp);
	cin>>m;
	rb(i,1,m){
		int k,pos;
		scanf("%d %d",&k,&pos);
		query[i]=II(II(k,pos),i);
	}
	sort(query+1,query+1+m);
	int las=0;
	rb(i,1,m){
		rb(j,las+1,query[i].FIR.FIR){
			_add(a[j].SEC);
		}
		las=query[i].FIR.FIR;
		res[query[i].SEC]=_query(1,size_n+1,query[i].FIR.SEC);
	} 
	rb(i,1,m){
		printf("%d\n",A[res[i]]);
	}
	return 0;
}