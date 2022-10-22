//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL cnt1[21][400000+10],cnt2[21][400000+10],_move[21][400000+10],tot=0,a[400000+10],put_off[21][21];LL dp[2000000];
vector<int> each[21];
map<int,int> Lisan; 
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n) scanf("%I64d",&a[i]),Lisan[a[i]]=1;
	for(map<int,int> :: IT ite=Lisan.begin();ite!=Lisan.end();ite++){
		ite->SEC=++tot;
	}
	rb(i,1,n) a[i]=Lisan[a[i]],cnt1[a[i]][i]=cnt2[a[i]][i]=1,each[a[i]].PB(i);
	rb(i,1,n){
		rb(j,1,tot) cnt1[j][i]+=cnt1[j][i-1];
	}
	rl(i,n,1) 
		rb(j,1,tot) cnt2[j][i]+=cnt2[j][i+1];
	rb(i,1,tot){
		int tot=1;
		for(auto it:each[i]){
//			cout<<i<<" "<<it<<endl;
			_move[i][1]+=it-(tot++);
		}
	}
		
	rb(j,1,tot)
		rb(i,2,n)
			_move[j][i]=_move[j][i-1]-cnt1[j][i-1]-(a[i]==j)-cnt2[j][i+1];
//	cout<<_move[2][3]<<endl;
//	rb(i,1,3)0
//		cout<<_move[3][i]<<" ";cout<<endl;
	rb(i,1,tot) sort(ALL(each[i]));
	rb(i,1,tot)
		rb(j,1,tot)
		{
			for(auto it:each[j]){
				put_off[i][j]+=cnt2[i][it+1];
			}
		}
//	cout<<_move[3][3]<<endl;
	int To=(1<<(tot))-1;
	rb(i,1,To){
		dp[i]=160000000000+INF;
		rb(ik,1,tot){
			int nmask=i;
//			cout<<i<<" "<<ik<<" "<<((1<<(ik-1)))<<endl;
			if(i&(1<<(ik-1))){
//				cout<<i<<" "<<ik<<endl;
				nmask^=(1<<(ik-1));
				LL tmpres=dp[nmask];
				LL MOOM=1;
				rb(ik2,1,tot){
					if(nmask&(1<<(ik2-1))){
						MOOM+=each[ik2].size();
						tmpres+=put_off[ik2][ik];
					}
				}
				tmpres+=_move[ik][MOOM];
				dp[i]=min(dp[i],tmpres);
			}
		}
//		cout<<i<<" "<<dp[i]<<endl;
		if(i==To){
			printf("%I64d\n",dp[i]);
		}
	}
//	cout<<To<<endl;
//	cout<<endl<<dp[2]<<endl;
	return 0;	
}