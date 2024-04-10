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
8.dp: dp[i][..]->i 
9. 
10.<-1> 
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
int n,m,q,lca_record[14][14];LL dp[14][8192+3];
mp edge[14];
bool check(int root,int root1,int mask1,int mask2){
	rb(i,1,m)
	{
		int ui=edge[i].FIR,vi=edge[i].SEC;
		if((ui==root&&vi==root1)||(ui==root1&&vi==root)) continue; 
//		cout<<i<< " "<<ui<<" "<<vi<<endl;
		if((mask1>>(ui-1))&1)
			if((mask2>>(vi-1))&1)
				return 0;
		swap(ui,vi);
		if((mask1>>(ui-1))&1)
			if((mask2>>(vi-1))&1)
				return 0;
	}int mask=mask1|mask2;
	rb(i,1,n)
		rb(j,i+1,n)
			if(lca_record[i][j])
				{
					if(((mask1>>(i-1))&1)&&((mask2>>(j-1))&1)){
						if(lca_record[i][j]!=root){
//							if(root==1&&mask==(1<<n)-1)cout<<i<<" "<<j<<endl;
//							cout<<root<<" "<<root1<<" "<<mask1<<" "<<mask2<<endl;
							return 0;
						} 
					}
					swap(i,j);
					if(((mask1>>(i-1))&1)&&((mask2>>(j-1))&1)){
//					if(root==1&&mask==(1<<n)-1)	cout<<i<<" "<<j<<endl;
//							cout<<root<<" "<<root1<<" "<<mask1<<" "<<mask2<<endl;
						if(lca_record[i][j]!=root) return 0;
					}
					swap(i,j);
				}
	
	mask-=(1<<(root-1));
	while(mask){
		if(mask&1)
		{
			if(mask2&1){
				return 1;
			}
			else return 0;
		}
		if(mask2&1) return 0;
		mask2>>=1;
		mask>>=1;
	}
	return 1;
}
int main(){	
	scanf("%d %d %d",&n,&m,&q);
	rb(i,1,m){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		edge[i]=II(ui,vi);
//		cout<<i<<"s"<<ui<<" "<<vi<<endl; 
	}
	rep(i,q){
		int ui,vi,a;
		scanf("%d %d %d",&ui,&vi,&a);
		if(ui==vi&&ui!=a){
			puts("0");
				return 0;
		}
		if(lca_record[ui][vi]) {
			if(lca_record[ui][vi]!=a){
				puts("0");
				return 0;
			}
			continue;
		}
		lca_record[ui][vi]=lca_record[vi][ui]=a;
	}
	rb(i,1,n) dp[i][1<<(i-1)]=1;
	rb(mask,1,(1<<(n))-1){
		if((mask-1)&mask){
			for(int s=mask;s;s=(s-1)&mask){
				if(s==mask) continue;
				int s2=mask xor s;
				rb(r1,1,n)
					if((s>>(r1-1))&1);
					else
					rb(r2,1,n)
						if(((s2>>(r1-1))&1)&&((s>>(r2-1))&1)){
//						if(r1==1&&mask==(1<<n)-1) cout<<r2<<" "<<s<<" "<<s2<<endl;
							if(check(r1,r2,s2,s)){
								dp[r1][mask]+=dp[r2][s]*dp[r1][s2];
								
								
							}
						}
			}
		}
	}
	cout<<dp[1][(1<<n)-1]<<endl;
	return 0;
}