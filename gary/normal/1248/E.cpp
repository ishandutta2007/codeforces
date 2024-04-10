/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,q,treen,a[200000+10],used[200000+10];
LL res[100000+10];
mp tree[(100000+10)*8];
mp find_(int now,int l,int r,int a,int b){
//	cout<<l<<" "<<r<<endl;
	if(r<=a||l>=b) return II(INF,INF);
	if(r<=b&&l>=a) return tree[now];
	int mid=(l+r)>>1;
	return min(find_(now<<1,l,mid,a,b),find_((now<<1)+1,mid,r,a,b));
}
void change(int now){
	now+=treen-1;
	tree[now]=II(INF,INF);
	now>>=1;
	while(now){
		tree[now]=min(tree[now<<1],tree[(now<<1)+1]);now>>=1;
	}
}
void build(int now){
	if(now>=treen){
		tree[now]=II(a[now-treen+1],now-treen+1);
		return;
	}
	build(now<<1),build((now<<1)+1);
	tree[now]=min(tree[now<<1],tree[(now<<1)+1]);
}
priority_queue<int> Q; 
int main(){
	cin>>n>>q;
	treen=1<<int(ceil(log2(double(n))));
	rb(i,1,n) scanf("%d",&a[i]);
	build(1);
//	cout<<treen+1<<endl;
	mp now=find_(1,1,treen+1,1,n+1);
	LL tmp=(LL)a[now.SEC]+q;
	res[now.SEC]=tmp;
	change(now.SEC);
	rb(i,1,n-1){
//		cout<<i<<endl;
		mp one=find_(1,1,treen+1,1,now.SEC),two=find_(1,1,treen+1,now.SEC+1,n+1);
		if((one.FIR<=tmp&&one.FIR!=INF)||(one.FIR>tmp&&one.FIR<=two.FIR&&one.FIR<=Q.top())){
			now=one;
			tmp=max(tmp+q,(LL)a[now.SEC]+q);
		}	
		else 
		{
//			cout<<i<<endl;
			while(n){
				if(two.FIR>tmp||two.FIR==INF){
					break;
				}
				Q.push(-two.SEC);
				change(two.SEC);
				two=find_(1,1,treen+1,now.SEC+1,n+1);
				if(two.FIR>tmp||two.FIR==INF){
					break;
				}	
			}
			if(Q.empty()){
				two=find_(1,1,treen+1,1,n+1);
				now=two;
				tmp=(LL)a[now.SEC]+q;
			}
			else{
//				while(Q)
				now.SEC=-Q.top();
				Q.pop();
				tmp=tmp+q; 
			}
		}
//		cout<<i<<endl;
		change(now.SEC);
		res[now.SEC]=tmp;
	}
	rb(i,1,n) printf("%I64d ",res[i]);puts("");
	return 0;
}