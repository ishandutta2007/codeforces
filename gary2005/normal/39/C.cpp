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
const int INF=0x3f3f3f3f*2;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
mp seg[2002];
int n;
bool cmp(mp A,mp B){
	if(A.SEC!=B.SEC){
		return A.SEC<B.SEC;
	}
	return A.FIR>B.FIR;
}
bool cmp2(pair<mp,int> A,pair<mp,int> B){
	return A.FIR.SEC<B.FIR.SEC; 
}
int dp[2002];//dp[i]icircle  
vector<int> path[2002];
map<mp,int> R;
void run(int i){
	vector<pair<mp,int> > v;
	int maxi[2002]={0};
	rb(j,1,i-1){
		if(seg[j].FIR>=seg[i].FIR){
			v.PB(II(seg[j],j));
		}
	}
	sort(ALL(v),cmp2);
	int pre[2002]={0},f[2002]={0};
	int Ind=0;
	rb(j,1,v.size()){
		int l=0,r=j;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(v[mid-1].FIR.SEC>v[j-1].FIR.FIR){
				r=mid;
			} 
			else{
				l=mid;
			}
		}
		l=maxi[l];
		pre[j]=l;
		f[j]=dp[v[j-1].SEC]+f[pre[j]];
		if(f[j]>f[Ind]){
			Ind=j;
		}
		if(f[j]>f[maxi[j-1]]){
			maxi[j]=j;
		}
		else{
			maxi[j]=maxi[j-1];
		}
	}
	path[i].PB(i);
	dp[i]=f[Ind]+1;
	while(Ind){
		for(auto it:path[v[Ind-1].SEC]){
			path[i].PB(it);
		}
		Ind=pre[Ind];
	}
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n){
		int c,r;
		cin>>c>>r;
		seg[i]=II(c-r,c+r);
		R[seg[i]]=i;
	}
//	return 0;
	seg[++n]=II(-INF,INF);
	sort(seg+1,seg+1+n,cmp);//
	/*rb(i,1,n){
		cout<<seg[i].FIR<<" "<<seg[i].SEC<<endl;
	}*/
	rb(i,1,n){
//		cout<<.
		run(i);
//		cout<<"____________"<<dp[i]<<endl;
	}
//	return 0;
	cout<<path[n].size()-1<<endl;
	sort(ALL(path[n]));
	for(auto it:path[n]){
		if(it!=n){
			cout<<R[seg[it]]<<" ";
		}
	}
	return 0;
}