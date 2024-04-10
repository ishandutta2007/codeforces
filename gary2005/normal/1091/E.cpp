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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int d[500000+3],cnt[500000+3],d2[500000+3];
LL n;
LL sum=0;
int check(int x){//cout<<n<<endl;
	int now=1;
	rb(i,1,n+2) cnt[i]=0;
	int tmpx=x;
	rb(i,1,n+1){
		if(d[now]<x){
			d2[i]=x;
			x=-INF;
		}
		else{
			d2[i]=d[now++];
		}
	}
	x=tmpx;
	LL S=0,S2=0;
	rb(i,1,n+1){
		S+=d2[i];//cout<<d2[i]<<" ";
	}//cout<<endl;
//	cout<<S<<endl;
	rl(k,n+1,1){
	//cout<<k<<endl;
		if(k!=n+1&&d2[k+1]==x) {
			x=-1;
			}
		S2+=min(k,d2[k+1]);
		cnt[min(k,d2[k+1])]++;
		S2-=cnt[k+1];
		cnt[k]+=cnt[k+1];
		if(S>S2+(LL)(k)*(k-1)){
			if(x>=0){
				return -1;//too big
			}
			else{
				return 1;//too small
			}
			return 0;
		}
		S-=d2[k];
	}
	return 0;
}
bool cmp(int A,int B){
	return A>B;
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n)
		cin>>d[i],sum+=d[i];
	sort(d+1,d+1+n,cmp);
	int L,R;
	int l,r;
	l=0,r=n+1;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid)==-1){
			r=mid;
		}
		else{
			l=mid;
		}
	}
//	cout<<check(35)<<endl;
	if(check(l)!=0){
		cout<<-1<<endl;	return 0;
	}
	R=l;
	l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)==1){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	if(check(l)!=0){
		cout<<-1<<endl;return 0;
	}
	L=l;
	rb(i,L,R){
		if((sum+i)%2==0) cout<<i<<" ";
	}
	return 0;
}