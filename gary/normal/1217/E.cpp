//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=2000000000;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int ai;int m1[10][200000*8],m2[10][200000*8],A[200000+10];
int treen;
void change2(int index,int wei,int val){
	wei+=treen-1;
	m1[index][wei]=val;
	wei>>=1;
	while(wei){
		m1[index][wei]=min(m1[index][wei<<1],m1[index][(wei<<1)+1]);
		int M1,M2;
		M1=M2=INF;
		M2=min(M2,m1[index][(wei<<1)]);
		if(M1>M2) swap(M1,M2);
		M2=min(M2,m1[index][(wei<<1)+1]);
		if(M1>M2) swap(M1,M2);
		M2=min(M2,m2[index][(wei<<1)+1]);
		if(M1>M2) swap(M1,M2);
		M2=min(M2,m2[index][(wei<<1)]);
		if(M1>M2) swap(M1,M2);
		m2[index][wei]=M2;
		wei>>=1;
	}
}
int min1(int index,int now,int l,int r,int a,int b){
	if(r<=a||l>=b) return INF;
	if(r<=b&&l>=a) return m1[index][now];
	int mid=(l+r)>>1;
	return min(min1(index,now<<1,l,mid,a,b),min1(index,(now<<1)+1,mid,r,a,b));
}
int process[2];
void min2(int index,int now,int l,int r,int a,int b){
	if(r<=a||l>=b) return ;
	if(r<=b&&l>=a){
		process[1]=min(process[1],m1[index][now]);
		if(process[0]>process[1]) swap(process[0],process[1]);
		process[1]=min(process[1],m2[index][now]);
		if(process[0]>process[1]) swap(process[0],process[1]);
		return ;
	}
	int mid=(l+r)>>1;
	min2(index,now<<1,l,mid,a,b),min2(index,(now<<1)+1,mid,r,a,b);
}
int main(){
	memset(m1,0x3f,sizeof(m1)),memset(m2,0x3f,sizeof(m2));
	int n,q;
	cin>>n>>q;
	int Tmp=n;
	treen=1;
	while(Tmp){
		treen<<=1;
		Tmp>>=1;
	}
	rb(i,1,n){
		scanf("%d",&ai);
		int Save=ai;
		A[i]=Save; 
		rb(j,1,9){
			if(ai%10){
//				seg_tree[j][i+treen-1]++;
				m1[j][i+treen-1]=Save;
			}
			ai/=10;
		}
	}
//	rb(i,1,9)
//	build(i,1,1,treen+1);
	rb(i,1,n){
		int Tmp=A[i];
		rb(j,1,9){
			if(Tmp%10) change2(j,i,A[i]);
			Tmp/=10;
		}
	}
	
	while(q--){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			int I,x;
			scanf("%d %d",&I,&x);
			int Tmp=A[I];
			rb(j,1,9){
				if(Tmp%10){
				change2(j,I,INF);
				}
				Tmp/=10;
			}
			Tmp=x;
			rb(j,1,9){
				if(Tmp%10){
					change2(j,I,x);
				}
				Tmp/=10;
			}
			A[I]=x; 
//			rb(j,1,9){
//				if(aply(j,I)&&!(x%10)) change(j,I,-1);
//				 if(!aply(j,I)&&x%10) change(j,I,1);
//				x/=10;
//			}
		}
		else{
			int li,ri;
			scanf("%d %d",&li,&ri);
			int OK=INF;
			rb(i,1,9){
//				if(query(i,1,1,treen+1,li,ri+1)>=2){
					process[0]=process[1]=INF;
					min2(i,1,1,treen+1,li,ri+1);
					if(process[1]>=0x3f3f3f3f) continue;
					int Two=min1(i,1,1,treen+1,li,ri+1);
					if(Two>=0x3f3f3f3f) continue;
					OK=min(OK,Two+process[1]);
//				}
			}
			printf("%d\n",((OK==INF)? -1:OK));
		}
	}
	return 0;
}