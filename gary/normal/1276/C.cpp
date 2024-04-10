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
10.
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
int n,a[400000+10];
vector<vector<int> > res,vis;
vector<mp> num_record;
bool cmp(mp A,mp B){
	return A.SEC>B.SEC;
}
int main(){
	cin>>n;
	rb(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int las=-1,cnt=0;
	rb(i,1,n){
		if(a[i]!=las){
			if(las!=-1){
				num_record.PB(II(las,cnt));
			}
			cnt=1;
			las=a[i];
		}
		else cnt++;
	}
	num_record.PB(II(las,cnt));
	sort(ALL(num_record),cmp);
	int point=0,n_=n,maxi=-1,is;
	rl(i,n,1){
		while(point<num_record.size()&&num_record[point].SEC>i){
			point++;
		}
		n_-=point;
		if(n_/i<i) continue;
		if((n_/i)*i>maxi){
			maxi=(n_/i)*i;
			is=i;
		}
	}
	int m;
	cout<<maxi<<'\n'<<is<<' '<<maxi/is<<'\n';
	n=is,m=maxi/is;
	rb(i,1,n){
		vector<int> tmp(n+m+10,0);
//		cout<< 
		res.PB(tmp);
	}
	int x,y,y2;
	x=y=y2=0;
	for(auto it:num_record){
		it.SEC=min(it.SEC,n);
		rb(i,1,it.SEC){
			res[x++][y++]=it.FIR;
			if(x==n){
				x=0;
				y=++y2;
			}
			if(y2==m) break;
		}
		if(y2==m) break;
	}
	rep(i,n)
		rep(j,m){
			if(!res[i][j])
				res[i][j]=res[i][j+m];
			printf("%d ",res[i][j] );
			if(j==m-1) puts("");
		}
			
	
	return 0;
}