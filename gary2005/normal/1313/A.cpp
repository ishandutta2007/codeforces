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
		pair<mp,int> A[7];
int main(){
	fastio;
	int t;
	cin>>t;
		A[0]=II(II(1,0),0);
		A[1]=II(II(0,1),0);
		A[2]=II(II(0,0),1);
		A[4]=II(II(1,0),1);
		A[5]=II(II(0,1),1);
		A[6]=II(II(1,1),1);
		A[3]=II(II(1,1),0);
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int res=0;
		int p[7]={1,2,3,4,5,6,7};
		do{
			int sa,sb,sc;
			sa=a,sb=b;
			sc=c;
			int tmp=0;
			rep(i,7){
				int x,y,z;
				x=A[p[i]-1].FIR.first;
				y=A[p[i]-1].FIR.SEC;
				z=A[p[i]-1].SEC;
				if(a>=x&&b>=y&&c>=z){
					a-=x;
					b-=y;
					c-=z;
					tmp++;
				} 
			}
			a=sa;	
			b=sb;
			c=sc;
			res=max(res,tmp);
		}while(next_permutation(p,p+7));
		cout<<res<<endl;
	}
	return 0;
}