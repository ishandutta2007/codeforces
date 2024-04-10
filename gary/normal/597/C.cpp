//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define U unsigned
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[100000+10][12];
LL a[100000+10];
LL seg_tree[100000*8][11];
int treen;
LL query(int now,int l,int r,int a,int b,int index){
	if(l>=b||r<=a){
		return 0;
	}
	if(l>=a&&r<=b){
		return seg_tree[now][index];
	}
	int mid=(l+r)>>1;
	return query(now<<1,l,mid,a,b,index)+query((now<<1)+1,mid,r,a,b,index);
}
LL sum(int l,int r,int index){
	return query(1,1,treen+1,l,r,index);
}
void _change(int now,int index,LL to_val){
	now+=treen;
	now--;
	seg_tree[now][index]=to_val;
	now>>=1;
	while(now){
		seg_tree[now][index]=seg_tree[now<<1][index]+seg_tree[(now<<1)+1][index];
		now>>=1;
	}
}
int main(){
//	freopen("hack.in","r",stdin);
//	freopen("mine.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	n++;
	treen=int(ceil(log2(double(n))));
	treen=1<<treen;
	a[0]=1;
	rb(i,2,n){
		scanf("%I64d",&a[i]);
		a[i]++;
	}
	k++;
	LL res=0;
	_change(1,0,1);
	rb(j,1,k){
		rb(i,2,n){
			dp[i][j]=sum(1,a[i],j-1);
			_change(a[i],j-1,dp[i][j-1]);
//			cout<<dp[i][j]<<" ";
			if(j==k){
				res+=dp[i][j];
			}
		}
//		cout<<endl;
//		res+=dp[i][k];
	}
	
	printf("%I64d\n",res);
	return 0;
}