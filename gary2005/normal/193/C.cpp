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
struct Data{
	int num[7];
};
void update(Data& A,Data B)
{
//	cout<<"!"<<endl;
	int res1,res2;
	res1=res2=0;
	rep(i,7){
		res1+=A.num[i];
	}
	rep(i,7){
		res2+=B.num[i];
	}
	if(res1>res2){
		A=B;
	}
}
Data res;
string s[7]={"aabb","aaab","aaba","abaa","abab","abba","abbb"};
void op(){
	vector<char> Res[4];
	int all=0;
	rep(i,7){
		all+=res.num[i];
		
	}
	if(all>1000000)
	{
		cout<<-1;
		return ;
	}
	rep(i,7){
		if(res.num[i]==INF){
			cout<<-1<<endl;
			exit(0);
		}
		rep(j,res.num[i]){
			Res[0].PB(s[i][0]);
			Res[1].PB(s[i][1]);
			Res[2].PB(s[i][2]);
			Res[3].PB(s[i][3]);
			
		}
	}
	cout<<Res[0].size()<<endl;
	rep(i,4){
		
	rep(j,Res[i].size())
		cout<<Res[i][j];
	cout<<endl;
	}
}
double a[10][10];
int id[4][4];
void solve(){
	int cnt=0;
	rep(i,4)
		rep(j,4)
			if(j>i)
				id[i][j]=cnt++;
	rep(k,7){
		rep(i,4)
			rep(j,4)
				if(j>i)
					a[id[i][j]][k]=(s[k][i]!=s[k][j]);
	}
	rep(i,4)
		rep(j,4){
			if(j>i)
			cin>>a[id[i][j]][7];
		}
	
	rep(i,6){
		int p=i;
		rb(j,i,5){
			if(abs(a[j][i])>abs(a[p][i]))
			p=j;
		}
		if(a[p][i]==0){
			cout<<-1<<endl;
			exit(0);
		}
		swap(a[i],a[p]);
		rl(j,7,i){
			a[i][j]/=a[i][i];
		}
		rb(j,0,5){
			if(i!=j){
				if(a[j][i]){
					rl(k,7,i){
						a[j][k]-=a[j][i]*a[i][k];
					}
				}
			}
		}
//	rep(i,6){
//		rep(j,8){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	}
	rep(j,100000){
		Data tmp;
		rep(i,7)
			tmp.num[i]=0;
		tmp.num[6]=j;
		int ok=1;
		rep(i,6){
			if(ceil(a[i][7]-a[i][6]*tmp.num[6])!=a[i][7]-a[i][6]*tmp.num[6]) ok=0;
			tmp.num[i]=a[i][7]-a[i][6]*tmp.num[6];
			if(tmp.num[i]<0){
				ok=0;
			}
		}
		if(ok)
		update(res,tmp);
	}
} 
int main(){
	fastio;
	rep(i,7)
		res.num[i]=1000000;
	solve();
	op();
	return 0;
}