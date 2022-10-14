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
inline LL read(){
    LL x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e6+233;
int n;
int lg[MAXN];
LL c,w[MAXN],sum[MAXN][2],rmq[MAXN][2][20],fk[MAXN],a[MAXN];
int pre[2][MAXN];
bool dp[2][MAXN];
LL ok[MAXN];
LL query(int t,int l,int r){
	int len=lg[r-l+1];
	return min(rmq[l][t][len],rmq[r-(1<<len)+1][t][len]);
}
pair<LL,LL> queryrange(int l,int r){
	if(l==r) return II(0,w[l]);
	int t=l&1;
	LL R,L;
	R=query(t^1,l,r)-sum[l][t^1]+sum[l][t];
	L=-(query(t,l,r)-sum[l][t]+sum[l][t^1]);
	check_min(R,w[l]);
	return II(L,R);
}
void recover(int i,bool j,bool tag=0){
	if(i==n-1) return;
	if(j==0){
		fk[i]=ok[i];
		assert(ok[i]>=0);
	}
	else{
		fk[i]=w[i];
	}
	rb(k,i+1,abs(pre[j][i])-1){
		fk[k]=w[k]-fk[k-1];
//		if(fk[k]<0){
//			cout<<"!"<<w[k]<<' '<<fk[k-1]<<' '<<k<<' '<<i<<' '<<pre[j][i]<<endl;
//		}
	}
	if(tag) rb(k,i,abs(pre[j][i])-1) fk[k]*=-1;
	if(pre[j][i]<0){
		recover(-pre[j][i],0,tag^1);
	}
	if(pre[j][i]>0){
		recover(pre[j][i],1,tag^1);
	}
}
int main(){
	scanf("%d",&n);
	scanf("%lld",&c);
	rb(i,1,n-2) w[i]=read();
	w[0]=w[1];
	lg[1]=0;
	rb(i,2,n) lg[i]=lg[i>>1]+1;
	rep(i,n-1){
		if(i){
			sum[i][0]=sum[i-1][0];
			sum[i][1]=sum[i-1][1];
		}
		sum[i][i&1]+=w[i];
	}
	rep(i,n-1) rep(j,20) rep(k,2) rmq[i][k][j]=1e18;
	rep(i,n-1){
		int j=i&1;
		rmq[i][j][0]=sum[i][j]-sum[i][j^1];
	}
	rep(j,2){
		rb(k,1,19)
			rep(i,n-1){
				if(i+(1<<k)-1<n){
					rmq[i][j][k]=min(rmq[i][j][k-1],rmq[i+(1<<(k-1))][j][k-1]);
				}
			}
	}
	int lasf=n-1;
	map<LL,int> posib;
	LL tag=0;
	LL sgn=1;
	rl(i,n-2,0){
		if(lasf==n-1){
			pair<LL,LL> range=queryrange(i,n-2);
			if(range.FIR<=range.SEC){
				assert(range.SEC<=w[i]);
				dp[0][i]=1;
				ok[i]=range.FIR;
				pre[0][i]=lasf;
				if(range.SEC==w[i]){
					dp[1][i]=1;
					pre[1][i]=lasf;
				}
			}
		}
		else{
			pair<LL,LL> range=queryrange(i,lasf);
			if(range.FIR<=range.SEC){
				assert(range.SEC<=w[i]);
				dp[0][i]=1;
				ok[i]=range.FIR;
				pre[0][i]=lasf;
				if(range.SEC==w[i]){
					dp[1][i]=1;
					pre[1][i]=lasf;
				}
			}
		}
		if(posib.find((w[i]-tag)*sgn)!=posib.end()){
			dp[1][i]=1;
			pre[1][i]=-posib[(w[i]-tag)*sgn];
		}
//		cout<<"##"<<posib.size()<<endl;
		if(posib.size()){
			if(sgn==1){
				auto ite=posib.begin();
				if(ite->FIR<=w[i]-tag){
					dp[0][i]=1;
					ok[i]=ite->FIR+tag;
					pre[0][i]=-ite->SEC;
				}
			}
			else{
				auto ite=posib.end();
				ite--;
				if(ite->FIR>=tag-w[i]){
					dp[0][i]=1;
					ok[i]=tag-ite->FIR;
					pre[0][i]=-ite->SEC;
				}
			}
		}
		if(dp[1][i]) lasf=i;
		tag=w[i]-tag;
		sgn*=-1;
		if(dp[0][i]){
			posib[(w[i]-tag)*sgn]=i;
		}
		if(sgn==-1){
			while(posib.size()){
				auto ite=posib.end();
				ite--;
				if(ite->FIR>tag){
					posib.erase(ite);
				}
				else
				break;
			}
		}
		else{
			while(posib.size()){
				auto ite=posib.begin();
				if(ite->FIR<-tag){
					posib.erase(ite);
				}
				else
				break;
			}
		}
	}
	if(!dp[0][0]){
		puts("NO");
	}
	else{
		puts("YES");
		recover(0,0);
		rb(i,1,n-1) a[i]=a[i-1]+fk[i-1];
		LL mn=a[0];
		rep(i,n) check_min(mn,a[i]);
		rep(i,n) printf("%lld ",a[i]-mn);
		puts("");
//		rep(i,n-2) assert(w[i+1]==max(max(a[i],a[i+1]),a[i+2])-min(min(a[i+1],a[i]),a[i+2]));
	}
	return 0;
}

/*

7 20
4 8 12 16 20

3 20
3


*/