/*
{

AuThOr Gwj
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MOD=1e9+7;
const int MAXN=1e5+20;
int n,a[MAXN],fake_vector[MAXN],siz,MAXA;
LL quick(LL A,LL B){
	if(!B) return 1ll;
	LL tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
		tmp=tmp*A%MOD;
	return tmp;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	fastio;
	R(n);
	MAXA=0;
	rb(i,1,n)
		R(a[i]),MAXA=max(MAXA,a[i]);
	sort(a+1,a+1+n);
	LL rest=0;
	rb(i,1,MAXA){
		siz=0;
		for(int j=1;j*j<=i;++j){
			if(i%j==0){
				fake_vector[++siz]=lower_bound(a+1,a+1+n,j)-a;//
				if(j*j!=i)
				{
					fake_vector[++siz]=lower_bound(a+1,a+1+n,i/j)-a;
				}
			}
		}
		sort(fake_vector+1,fake_vector+1+siz);
//		cout<<i<<":{";
//		rb(i,1,siz){
//			cout<<fake_vector[i];
//			if(i!=siz)
//			{
//				cout<<",";
//			}
//			else{
//				cout<<"}\n";
//			}
//		}
		fake_vector[++siz]=n+1;
		int have=0,las=1;
		LL tmp_rest=1;
		rb(j,1,siz){
			int total=fake_vector[j]-las;
			las=fake_vector[j];
			tmp_rest=(tmp_rest*quick(have,total))%MOD;
			have++;
		}
//		cout<<tmp_rest<<endl;
		LL tmp_cant=1ll;
		have=0,las=1;
		rb(j,1,siz){
			if(j==siz-1) continue;
			int total=fake_vector[j]-las;
			las=fake_vector[j];
			tmp_cant=(tmp_cant*quick(have,total))%MOD;
			have++;
		}
		rest=(rest+tmp_rest-tmp_cant+MOD)%MOD;
	}
	cout<<rest<<endl;
	return 0;
}
/*
4
1 4 3 2

2
6 3
*/