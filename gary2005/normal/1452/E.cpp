/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
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
LL chafen[2002];
LL R[2002];
LL L[2002]; 
int n,m;
int k;
int l[2002],r[2002];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rb(i,1,m){
		scanf("%d%d",&l[i],&r[i]);
	}
	LL rest=0;
	rb(Z,1,n-k+1){
		memset(chafen,0,sizeof(chafen));
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		LL tmp=0;
		LL MAX=0;
		rb(j,1,m){
			int cro=max(0,min(r[j],Z+k-1)-max(Z,l[j])+1);
			int lb,rb;
			lb=l[j]+cro-1-k+1;
			rb=l[j]-1;
			check_max(lb,1);
			check_min(rb,r[j]-k+1);
			if(lb<=rb){
				chafen[lb]-=l[j];
				chafen[rb+1]+=l[j];
				chafen[lb]-=cro;
				chafen[rb+1]+=cro;
				R[lb]++;
				R[rb+1]--;	
			}
//			cout<<j<<' '<<cro<<' '<<lb<<' '<<rb<<' '<<' '<<l[j]<<endl; 
			lb=l[j];
			rb=r[j]-k+1;
			if(lb<=rb){
				chafen[lb]+=k;
				chafen[rb+1]-=k;
				chafen[lb]-=cro;
				chafen[rb+1]+=cro;
			}
//			cout<<j<<'-'<<cro<<' '<<lb<<' '<<rb<<endl; 
			rb=r[j]-cro+1;
			lb=r[j]+1-k+1;
			check_max(lb,l[j]);
			if(lb<=rb){
				chafen[lb]-=cro;
				chafen[rb+1]+=cro;
				chafen[lb]+=r[j];
				chafen[rb+1]-=r[j];
				L[lb]++;
				L[rb+1]--;
			}
			lb=r[j]+1-k+1;
			rb=l[j]-1;
			check_max(lb,1);
			if(lb<=rb){
				chafen[lb]-=cro;
				chafen[rb+1]+=cro;
				chafen[lb]+=r[j]-l[j]+1;
				chafen[rb+1]-=r[j]-l[j]+1;
			}
//			cout<<j<<'-'<<cro<<' '<<lb<<' '<<rb<<' '<<r[j]<<endl; 
			tmp+=cro;
		}
		rb(i,1,n-k+1)
			chafen[i]+=chafen[i-1];
//		rb(i,1,n-k+1){
//			cout<<chafen[i]<<' ';
//		}cout<<endl;
		rb(i,1,n-k+1)
			R[i]+=R[i-1];
//		rb(i,1,n-k+1){
//			cout<<R[i]<<' '; 
//		}
//		cout<<endl;
//		rb(i,1,n-k+1){
//			cout<<chafen[i]<<' '; 
//		}
//		cout<<endl;
		rb(i,1,n-k+1)
			R[i]*=(i+k);
	//	rb(i,1,n-k+1){
//			cout<<R[i]<<' '; 
//		}
//		cout<<endl;
		rb(i,1,n-k+1){
			L[i]+=L[i-1];
		}
//		rb(i,1,n-k+1){
//			cout<<L[i]<<' '; 
//		}
//		cout<<endl;
		rb(i,1,n-k+1) L[i]*=-(i-1);
//		rb(i,1,n-k+1){
//			cout<<L[i]<<' '; 
//		}
//		cout<<endl;
//		rb(i,1,n-k+1) cout<<L[i]<<' ';cout<<endl;
		rb(i,1,n-k+1) chafen[i]+=R[i]+L[i],check_max(MAX,chafen[i]);
		tmp+=MAX;
		check_max(rest,tmp);
//		cout<<Z<<' '<<tmp<<' '<<MAX<<endl;
//		break;
	}
	cout<<rest<<endl;
	return 0;
}