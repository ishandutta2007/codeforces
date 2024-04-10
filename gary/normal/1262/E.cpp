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
8. CSPday2 meal
9.-or
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
int n,m;
vector<vector<int> > land,sum,record,sum2; 
bool check(int X1,int Y1,int X2,int Y2){
	if(X1<0||Y1<0||X2>=n||Y2>=m) return 0;
	int tmp=sum[X2][Y2];
	if(X1){
		tmp-=sum[X1-1][Y2];
	}
	if(Y1){
		tmp-=sum[X2][Y1-1];
	}
	if(X1&&Y1){
		tmp+=sum[X1-1][Y1-1];
	}
	return tmp==(X2-X1+1)*(Y2-Y1+1);
}
bool check2(int i,int j,int t){
	int X1,Y1,X2,Y2;
	X1=i-t;
	Y1=j-t;
	X2=i+t;
	Y2=j+t;
	X1=max(0,X1);
	Y1=max(0,Y1);
	X2=min(X2,n-1);
	Y2=min(Y2,m-1);
	int tmp=sum2[X2][Y2];
	if(X1){
		tmp-=sum2[X1-1][Y2];
	}
	if(Y1){
		tmp-=sum2[X2][Y1-1];
	}
	if(X1&&Y1){
		tmp+=sum2[X1-1][Y1-1];
	}
	return tmp;
}
bool check(int x){
	rep(i,n)
		rep(j,m)
			record[i][j]=sum2[i][j]=0;
	rep(i,n)
		rep(j,m){
			int L1,R1,L2,R2;
			L1=i-x;
			R1=j-x;
			L2=i+x;
			R2=j+x;
			if(check(L1,R1,L2,R2)){
				record[i][j]=1;
			}	
		} 
	rep(i,n)
	{
		sum2[i][0]=record[i][0];
		rep(j,m){
			if(j){
				sum2[i][j]=sum2[i][j-1]+record[i][j];
			}
		}
	}
	rep(i,n){
		if(i){
			rep(j,m){
				sum2[i][j]+=sum2[i-1][j];
			}
		}
	}
	rep(i,n){
		rep(j,m){
			if(land[i][j]){
				if(check2(i,j,x));
				else{
					return 0;
				} 
			}
		}
	}
	return 1;
}
void recover(int x){
	rep(i,n)
		rep(j,m){
			int L1,R1,L2,R2;
			L1=i-x;
			R1=j-x;
			L2=i+x;
			R2=j+x;
			if(check(L1,R1,L2,R2)){
				record[i][j]=1;
			}	
		} 
	rep(i,n)
	{
		rep(j,m){
			if(record[i][j]){
				printf("X");
			}
			else printf(".");
		}
		puts("");
	}
}
int main(){
	scanf("%d %d",&n,&m);
	rb(i,1,n){
		vector<int> tmp;
		rb(j,1,m)
			{char a;
			cin>>a;
			tmp.PB(a=='X');
			}
		land.PB(tmp);
	}
	sum=sum2=record=land;
	rep(i,n){
		sum[i][0]=land[i][0];
		rep(j,m){
			if(j){
				sum[i][j]=sum[i][j-1]+land[i][j];
			}
		}
	}
	rep(i,n){
		if(i)
		rep(j,m){
			sum[i][j]+=sum[i-1][j];
		}
	}
	int l=0,r=min(m,n)/2+1;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid; 
		else r=mid;
	}
	cout<<l<<endl;
	recover(l);
	return 0;
}