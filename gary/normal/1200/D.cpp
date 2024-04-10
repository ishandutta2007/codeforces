//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
//Thank nhho for this
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
char a[2000+10][2000+10];
int fir[2000+10],las[2000+10]; 
int addres[2000+10][2000+10];
int addres2[2000+10][2000+10];
int sum[2000+10];
int save[2000+10][2000+10];
int n,k;
int OK=0;
int main(){
	memset(fir,-1,sizeof(fir));
	memset(las,-1,sizeof(las));
	cin>>n>>k;
	rb(i,1,n)
		rb(j,1,n) {
			cin>>a[i][j];
			save[j][i]=a[i][j];
			if(a[i][j]=='B'){
				if(fir[i]==-1) fir[i]=j;
				las[i]=j;
			}
		}
	rb(i,1,n) OK+=(fir[i]==-1);
	rb(i,1,k)
	{
		if(fir[i]!=-1){
			if(las[i]-fir[i]+1<=k){
				sum[max(1,las[i]-k+1)]++;
				sum[fir[i]+1]--;
			}
		}
	}
	rb(j,1,n-k+1) sum[j]+=sum[j-1],addres[1][j]+=sum[j];
	rb(i,2,n-k+1){
		memset(sum,0,sizeof(sum));
		rb(j,1,n) addres[i][j]=addres[i-1][j];
		if(fir[i-1]!=-1){
			if(las[i-1]-fir[i-1]+1<=k){
				sum[max(1,las[i-1]-k+1)]--;
				sum[fir[i-1]+1]++;
			}
		}
		if(fir[i+k-1]!=-1){
			if(las[i+k-1]-fir[i+k-1]+1<=k){
				sum[max(1,las[i+k-1]-k+1)]++;
				sum[fir[i+k-1]+1]--;
			}
		}
//		cout<<"two:";
//		rb(j,1,n-k+1) cout<<sum[j]<<" ";
//		cout<<endl;
		rb(j,1,n-k+1) sum[j]+=sum[j-1],addres[i][j]+=sum[j];
//		cout<<endl;
	}
	memset(fir,-1,sizeof(fir));
	memset(las,-1,sizeof(las));
	rb(i,1,n)
		rb(j,1,n) a[i][j]=save[i][j],addres2[i][j]=addres[i][j];
	memset(addres,0,sizeof(addres));
	memset(sum,0,sizeof(sum));
	rb(i,1,n)
		rb(j,1,n) {
			if(a[i][j]=='B'){
				if(fir[i]==-1) fir[i]=j;
				las[i]=j;
			}
		}
	rb(i,1,n) OK+=(fir[i]==-1);
	rb(i,1,k)
	{
		if(fir[i]!=-1){
			if(las[i]-fir[i]+1<=k){
				sum[max(1,las[i]-k+1)]++;
				sum[fir[i]+1]--;
			}
		}
	}
	rb(j,1,n-k+1) sum[j]+=sum[j-1],addres[1][j]+=sum[j];
	rb(i,2,n-k+1){
		memset(sum,0,sizeof(sum));
		rb(j,1,n-k+1) addres[i][j]=addres[i-1][j];
		if(fir[i-1]!=-1){
			if(las[i-1]-fir[i-1]+1<=k){
				sum[max(1,las[i-1]-k+1)]--;
				sum[fir[i-1]+1]++;
			}
		}
		if(fir[i+k-1]!=-1){
			if(las[i+k-1]-fir[i+k-1]+1<=k){
				sum[max(1,las[i+k-1]-k+1)]++;
				sum[fir[i+k-1]+1]--;
			}
		}
		rb(j,1,n-k+1) sum[j]+=sum[j-1],addres[i][j]+=sum[j];
	}
	int res=-INF;
//	rb(i,1,n-k+1){
//		rb(j,1,n-k+1){
//			cout<<a[j][i]<<" ";
//		}
//		cout<<endl;
//	}
	rb(i,1,n-k+1){
		rb(j,1,n-k+1){
			addres[j][i]+=addres2[i][j];
			res=max(res,addres[j][i]);
		}//cout<<endl; 
	}
	cout<<res+OK<<endl;
	return 0;
}